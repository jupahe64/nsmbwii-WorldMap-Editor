#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include "worldmap.h"
#include <QDebug>
#include <FileFormats/csv.h>

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
            WorldMap::WayPoint point = WorldMap::WayPoint();
            point.m_events = row->at(2);
            point.m_indirectConnections = row->at(3);
            point.m_exitAnims = row->at(4);
            point.m_secretExitAnims = row->at(7);
            maps[mapId].m_wayPoints.insert(row->at(1).first(),point);
        }
    }

    void loadRoute(Csv*csv, int mapId){
        foreach (QVector<QStringList> *row, csv->entries) {
            QString routeString = row->at(0).first();
            WorldMap::Route route = WorldMap::Route();
            QString namePoint1 = routeString.mid(1,4);
            qDebug() << namePoint1;
            if(maps[mapId].m_wayPoints.contains(namePoint1)){
                route.m_waypoint1 = &maps[mapId].m_wayPoints[namePoint1];
                maps[mapId].m_wayPoints[namePoint1].m_connectedRoutes.append(&route);
            }else{
                WorldMap::WayPoint point1 = WorldMap::WayPoint();
                route.m_waypoint1 = &point1;
                point1.m_connectedRoutes.append(&route);
                maps[mapId].m_wayPoints.insert(namePoint1,point1);
            }

            QString namePoint2 = routeString.mid(5,4);
            qDebug() << namePoint2;
            if(maps[mapId].m_wayPoints.contains(namePoint2)){
                route.m_waypoint2 = &maps[mapId].m_wayPoints[namePoint2];
                maps[mapId].m_wayPoints[namePoint2].m_connectedRoutes.append(&route);
            }else{
                WorldMap::WayPoint point2 = WorldMap::WayPoint();
                route.m_waypoint2 = &point2;
                point2.m_connectedRoutes.append(&route);
                maps[mapId].m_wayPoints.insert(namePoint2,point2);
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

    QString readNullterminatedString(QFile &file)
    {
        QString string = "";
        while(!file.atEnd()){
            char character = file.read(1).at(0);
            if(character == 0x00)
                break;
            string.append(character);
        }
        return string;
    }
    float* toFloat(QByteArray bytes){
        //reverseEndian
        char* destPtr = new char[4];
        char* srcPtr = bytes.data();

        destPtr[0]=srcPtr[3];
        destPtr[1]=srcPtr[2];
        destPtr[2]=srcPtr[1];
        destPtr[3]=srcPtr[0];

        return reinterpret_cast<float*>(destPtr);
    }

    void loadWorldMapBones(QFile &file, QString fileName, int mapId, int modelId = 0){
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        file.seek(0x6C);
        file.seek(0x60+qFromBigEndian<quint16>(file.read(2))+0x08);

        QVector<quint32> offsets = loadIndexGroupWithNames(file);
        index = 0;
        foreach (quint32 offset, offsets) {
            if(index%2==0){
                file.seek(offset);
                if (readNullterminatedString(file).startsWith("3DModels")){
                    file.seek(offsets[index+1]);

                    gotoGroupElementAt(file,modelId);
                    break;
                };
            }
            index++;
        }
        quint32 MDL0start = file.pos();
        qDebug() << QString::number(file.pos(),16);
        qDebug() << fileName << mapId << QString(file.read(0x14));
        file.seek(MDL0start+qFromBigEndian<quint32>(file.read(4)));

        qDebug() << QString::number(MDL0start,16);

        offsets = loadIndexGroupWithNames(file);
        index = 0;
        QString boneName;
        foreach (quint32 offset, offsets) {
            if((index%2==0)&&(index!=0)){
                file.seek(offset);

                boneName = readNullterminatedString(file);

                if(maps[mapId].m_wayPoints.contains(boneName)){

                    //read position
                    file.seek(offsets[index+1]+0x38);
                    maps[mapId].m_wayPoints[boneName].x = *toFloat(file.read(4));
                    maps[mapId].m_wayPoints[boneName].y = *toFloat(file.read(4));
                    maps[mapId].m_wayPoints[boneName].z = *toFloat(file.read(4));

                    //position is relative so loop through all parent bones
                    int currentOffset = offsets[index+1];
                    while(1){
                        //read parent bone
                        file.seek(currentOffset+0x5C);
                        //and set the current offset
                        currentOffset += qFromBigEndian<qint32>(file.read(4));

                        if (currentOffset==offsets[1])//reference to world bone
                            break;
                        file.seek(currentOffset+0x38);

                        //add parent position
                        maps[mapId].m_wayPoints[boneName].x += *toFloat(file.read(4));
                        maps[mapId].m_wayPoints[boneName].y += *toFloat(file.read(4));
                        maps[mapId].m_wayPoints[boneName].z += *toFloat(file.read(4));
                    }
                    file.seek(offsets[index+1]+0x60);
                    qint32 childOffset = qFromBigEndian<qint32>(file.read(4));
                    if(childOffset!=0){
                        file.seek(offsets[index+1]+childOffset+0x08);
                        file.seek(offsets[index+1]+childOffset+qFromBigEndian<qint32>(file.read(4)));
                        QString childBoneName = readNullterminatedString(file);
                        qDebug() << childBoneName;
                        maps[mapId].m_wayPoints[boneName].setRepresentationFromChildBone(childBoneName);
                    }


                }

            }
            index++;
        }
        file.close();
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
};

#endif // MAINWINDOW_H
