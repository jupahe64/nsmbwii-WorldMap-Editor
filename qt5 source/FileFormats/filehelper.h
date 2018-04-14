#ifndef FILEEHELPER_H
#define FILEEHELPER_H
#include <QtCore>
#include "csv.h"

class FileHelper
{
public:
    static QMap<QString, Csv*> unpackCSVsFromU8(QFile &file);

    static void packCSVsInU8(QFile &file, QMap<QString, Csv*> CSVs);

    static QString readNullterminatedString(QFile &file);

    static float* toFloat(QByteArray bytes);

    static QByteArray readAt(QFile &file, qint64 offset, quint64 maxlen){
        file.seek(offset);
        return file.read(maxlen);
    }
};

#endif // FILEEHELPER_H
