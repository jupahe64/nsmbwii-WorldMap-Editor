#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include "worldmap.h"
#include <QDebug>
#include <FileFormats/csv.h>
#include <FileFormats/filehelper.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString fileName;

    QMap<QString, Csv*> unpackedCSVs;

    WorldMap *maps = new WorldMap[10];
    quint8 mapId;

    int index;//for reading csv

    void loadWorldMap();

    void loadPoints(Csv *csv, int mapId){
        foreach (QVector<QStringList> *row, csv->entries) {
            WorldMap::WayPoint *point = new WorldMap::WayPoint();
            point->m_events = row->at(2);
            point->m_indirectConnections = row->at(3);
            point->m_exitAnims = row->at(4);
            point->m_secretExitAnims = row->at(7);
            maps[mapId].m_wayPoints.insert(row->at(1).first(),point);
        }
    }

    void loadRoute(Csv*csv, int mapId){
        foreach (QVector<QStringList> *row, csv->entries) {
            QString routeString = row->at(0).first();
            WorldMap::Route *route = new WorldMap::Route();
            QString namePoint1 = routeString.mid(1,4);
            if(maps[mapId].m_wayPoints.contains(namePoint1)){
                route->m_waypoint1 = maps[mapId].m_wayPoints[namePoint1];
                maps[mapId].m_wayPoints[namePoint1]->m_connectedRoutes.append(route);
            }else{
                WorldMap::WayPoint *point1 = new WorldMap::WayPoint();
                point1->m_connectedRoutes.append(route);
                maps[mapId].m_wayPoints.insert(namePoint1,point1);
                route->m_waypoint1 = maps[mapId].m_wayPoints[namePoint1];
            }

            QString namePoint2 = routeString.mid(5,4);
            //qDebug() << namePoint2;
            if(maps[mapId].m_wayPoints.contains(namePoint2)){
                route->m_waypoint2 = maps[mapId].m_wayPoints[namePoint2];
                maps[mapId].m_wayPoints[namePoint2]->m_connectedRoutes.append(route);
            }else{
                WorldMap::WayPoint *point2 = new WorldMap::WayPoint();
                point2->m_connectedRoutes.append(route);
                maps[mapId].m_wayPoints.insert(namePoint2,point2);
                route->m_waypoint2 = maps[mapId].m_wayPoints[namePoint2];
            }
            maps[mapId].m_routes.insert(routeString,route);
        }
    }

    QVector<quint32> loadIndexGroup(QFile &file)
    {
        quint64 startPos = file.pos();
        file.read(4);//length in bytes
        int entryCount = qFromBigEndian<int>(file.read(4));
        file.read(16); //empty entry can be skipped
        QVector<quint32> offsets(entryCount);
        for (int i = 0; i<entryCount; i++){
            file.read(12); //id, padding, left index, right index, name offset
            offsets[i] = qFromBigEndian<quint32>(file.read(4))+startPos;
        }
        return offsets;
    }

    QVector<quint32> loadIndexGroupWithNames(QFile &file)
    {
        quint64 startPos = file.pos();
        file.read(4);//length in bytes
        int entryCount = qFromBigEndian<int>(file.read(4));
        file.read(16); //empty entry can be skipped
        QVector<quint32> offsets(entryCount*2);
        for (int i = 0; i<entryCount; i++){
            file.read(8); //id, padding, left index, right index
            offsets[i*2] = qFromBigEndian<quint32>(file.read(4))+startPos; //name offset
            offsets[i*2+1] = qFromBigEndian<quint32>(file.read(4))+startPos; //value offset
        }
        return offsets;
    }

    void gotoGroupElementAt(QFile &file, int index)
    {
        quint64 startPos = file.pos();
        file.seek(startPos+0x10*index+0x18+0x0C);
        file.seek(qFromBigEndian<quint32>(file.read(4))+startPos);
    }

    void loadWorldMapBones(QFile &file, QString fileName, int mapIdToLoad, int modelId = 0)
    {
        file.setFileName(fileName);
        if(!file.open(QIODevice::ReadOnly)) return;

        file.seek(0x6C);
        file.seek(0x60+qFromBigEndian<quint16>(file.read(2))+0x08);

        QVector<quint32> offsets = loadIndexGroupWithNames(file);
        index = 0;
        foreach (quint32 offset, offsets) {
            if(index%2==0){
                file.seek(offset);
                if (FileHelper::readNullterminatedString(file).startsWith("3DModels")){
                    file.seek(offsets[index+1]);

                    gotoGroupElementAt(file,modelId);
                    break;
                };
            }
            index++;
        }
        quint32 MDL0start = file.pos();
        //qDebug() << QString::number(file.pos(),16);
        qDebug() << fileName << mapIdToLoad << QString(file.read(0x14));
        //go to bone group
        file.seek(MDL0start+qFromBigEndian<quint32>(file.read(4)));

        gotoGroupElementAt(file,0);
        loadWorldMapBoneChilds(file, 0, 0, 0, 0, mapIdToLoad);
        file.close();
    }

    void loadWorldMapBoneChilds(QFile &file,float parentX, float parentY, float parentZ,
                                float pRotY, int mapIdToLoad, QString childRequest="")
    {
        qint32 offsetNext;
        qint32 offsetChild;
        do{
            quint32 boneStart = file.pos();
            file.seek(boneStart+0x60);
            offsetChild = qFromBigEndian<qint32>(file.read(4));
            offsetNext = qFromBigEndian<qint32>(file.read(4));

            file.seek(boneStart+0x08);
            //go to name offset
            file.seek(boneStart+qFromBigEndian<qint32>(file.read(4)));

            QString boneName = FileHelper::readNullterminatedString(file);

            //read position
            file.seek(boneStart+0x20);
            float scaleX = *FileHelper::toFloat(file.read(4));
            float scaleY = *FileHelper::toFloat(file.read(4));
            float scaleZ = *FileHelper::toFloat(file.read(4));

            FileHelper::toFloat(file.read(4));
            float rotY = *FileHelper::toFloat(file.read(4));
            FileHelper::toFloat(file.read(4));

            float posX = *FileHelper::toFloat(file.read(4));
            float posY = *FileHelper::toFloat(file.read(4));
            float posZ = *FileHelper::toFloat(file.read(4));

            double radY = -pRotY*M_PI/180.0;

            float boneX = (posX*cos(radY)-posZ*sin(radY))*scaleX;
            float boneY = posY*scaleY;
            float boneZ = (posX*sin(radY)+posZ*cos(radY))*scaleZ;

            if(boneName.startsWith("RW")||boneName.startsWith("RF"))
                maps[mapIdToLoad].m_routePaths.insert(boneName,new WorldMap::RoutePath());

            if(childRequest.startsWith('W')&&boneName.startsWith("cob")) //level wants to know its representation
                maps[mapIdToLoad].m_wayPoints[childRequest]->setRepresentationFromChildBone(boneName);

            if(maps[mapIdToLoad].m_wayPoints.contains(boneName)){
                if((childRequest.startsWith("RW")||childRequest.startsWith("RF"))&&
                   (boneName.startsWith('F')||boneName.startsWith('K'))) //path wants to know his nodes
                    maps[mapIdToLoad].m_routePaths[childRequest]->m_nodes.append(maps[mapIdToLoad].m_wayPoints[boneName]);

                maps[mapIdToLoad].m_wayPoints[boneName]->x = boneX+parentX;
                maps[mapIdToLoad].m_wayPoints[boneName]->y = boneY+parentY;
                maps[mapIdToLoad].m_wayPoints[boneName]->z = boneZ+parentZ;

            }
            if(offsetChild!=0){
                file.seek(boneStart+offsetChild);

                QString newChildRequest=childRequest; //pass childRequest to children
                if(boneName.startsWith('W')||boneName.startsWith("RW")||boneName.startsWith("RF"))
                    newChildRequest = boneName;
                loadWorldMapBoneChilds(file, boneX+parentX, boneY+parentY, boneZ+parentZ,
                                       rotY+pRotY, mapIdToLoad,newChildRequest);
            }
            file.seek(boneStart+offsetNext);
        }while(offsetNext!=0);
    }


private slots:
    void actionOpen();
    void actionSave();

    //TODO better code
    void actionWorld1(){this->mapId = 0;loadWorldMap();}
    void actionWorld2(){this->mapId = 1;loadWorldMap();}
    void actionWorld3a(){this->mapId = 2;loadWorldMap();}
    void actionWorld3b(){this->mapId = 3;loadWorldMap();}
    void actionWorld4(){this->mapId = 4;loadWorldMap();}
    void actionWorld5(){this->mapId = 5;loadWorldMap();}
    void actionWorld6(){this->mapId = 6;loadWorldMap();}
    void actionWorld7(){this->mapId = 7;loadWorldMap();}
    void actionWorld8(){this->mapId = 8;loadWorldMap();}
    void actionWorld9(){this->mapId = 9;loadWorldMap();}

    void on_listPoints_currentTextChanged(const QString &currentText);
    void on_listPoints_itemDoubleClicked(QListWidgetItem *item);
    void on_listPaths_currentTextChanged(const QString &currentText);
    void on_listExitAnims_itemDoubleClicked(QListWidgetItem *item);
    void on_listSecretExitAnims_itemDoubleClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H
