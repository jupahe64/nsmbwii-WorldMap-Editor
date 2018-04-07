#ifndef CSV_H
#define CSV_H
#include <QtCore>

class Csv
{
public:
    Csv();
    Csv(QFile &file, quint32 length);

    QStringList loadCSVField(QStringList &parts, int &i);

    QList<QVector<QStringList>*> entries;

    void write(QFile &file);

    void write(QTextStream &stream);

    quint32 size();

    int columnCount() const;

private:
    int tableColumnCount;
};

#endif // CSV_H
