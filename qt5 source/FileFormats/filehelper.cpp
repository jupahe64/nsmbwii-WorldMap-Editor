#include "filehelper.h"

QString FileHelper::readNullterminatedString(QFile &file)
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

float* FileHelper::toFloat(QByteArray bytes){
    //reverseEndian
    char* destPtr = new char[4];
    char* srcPtr = bytes.data();

    destPtr[0]=srcPtr[3];
    destPtr[1]=srcPtr[2];
    destPtr[2]=srcPtr[1];
    destPtr[3]=srcPtr[0];

    return reinterpret_cast<float*>(destPtr);
}



QMap<QString, Csv*> FileHelper::unpackCSVsFromU8(QFile &file)
{
    QMap<QString, Csv*> unpacked = QMap<QString, Csv*>();
    QStringList *filePathLayers = new QStringList();
    qint32 currentParentDirectoryIndex = -1;
    file.seek(file.pos()+0x28);
    qint32 nodeCount = qFromBigEndian<quint32>(file.read(4))-1;
    quint32 nodesOffset = file.pos();
    for (int index = 0; index<nodeCount;index++){
        file.seek(nodesOffset+index*0x0C);
        bool isDirectory = (file.read(1).at(0x00)==0x01);
        quint32 nameOffset = (qFromBigEndian<quint32>(file.read(3)) >> 8);
        if(isDirectory){
            qint32 parentDirectoryIndex = qFromBigEndian<qint32>(file.read(4));

            if(parentDirectoryIndex==currentParentDirectoryIndex)//parent dir stayed the same
                filePathLayers->pop_back();//remove last layer (new directory in current parent)
            else if(parentDirectoryIndex==0)//parent dir is now root
                filePathLayers->clear();//remove all layers (new directory in root)

            currentParentDirectoryIndex=parentDirectoryIndex;//make this dir the parent for all following nodes

            file.seek(nodesOffset+nodeCount*0x0C+nameOffset);
            filePathLayers->append(FileHelper::readNullterminatedString(file));
        }else{
            quint32 dataOffset = qFromBigEndian<qint32>(file.read(4));
            quint32 dataSize = qFromBigEndian<qint32>(file.read(4));
            QString path = "";
            foreach (QString dir, *filePathLayers) {
                path+=dir+"/";
            }
            file.seek(nodesOffset+nodeCount*0x0C+nameOffset);
            path+=FileHelper::readNullterminatedString(file);
            file.seek(dataOffset);
            qDebug() << QString::number(dataOffset,16) << QString::number(dataSize,16) << path;
            unpacked.insert(path,new Csv(file,dataSize));
        }
    }
    return unpacked;
}

void FileHelper::packCSVsInU8(QFile &file, QMap<QString, Csv *> CSVs)
{
    //TODO: finish coding
    QTextStream out(&file);
    out << "U.8-";
    quint32 stringPoolLength = 0;
    foreach (QString key, CSVs.keys()) {
        out << key << QChar(0x00);
    }
    out << QString::number(0x20+0xC);
}
