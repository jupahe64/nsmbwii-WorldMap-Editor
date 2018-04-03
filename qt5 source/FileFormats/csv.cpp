#include "csv.h"

Csv::Csv()
{

}

Csv::Csv(QFile &file, quint32 length)
{
    quint32 start = file.pos();
    while(file.pos()<start+length){
        QByteArray line = file.readLine();
        QString decodedLine = QTextCodec::codecForName("Shift-JIS")->toUnicode(line.data(),line.length());
        decodedLine.chop(2); //get rid of the newline chars
        QStringList parts = decodedLine.split(',');
        tableColumnCount = parts.length();
        QVector<QStringList> *row = new QVector<QStringList>();
        row->reserve(parts.length());
        int i = 0;
        for(int index = 0; i<parts.length(); index++){
            row->append(loadCSVField(parts, i));
        }
        entries.append(row);
    }
}

QStringList Csv::loadCSVField(QStringList &parts, int &i)
{
    QStringList list = QStringList();
    if(parts.at(i).startsWith('"'))
        do{
            list.append(QString(parts.at(i)).remove('"'));
            i++;
        }while(!parts[i-1].endsWith('"'));
    else{
        if (parts.at(i)!="")
            list.append(parts.at(i));
        i++;
    }
    return list;
}

void Csv::write(QTextStream &out)
{
    out.setCodec(QTextCodec::codecForName("Shift-JIS"));
    foreach(QVector<QStringList>* row,entries){
        for(int i = 0; i<tableColumnCount; i++){
            QStringList entry;
            if (i<row->length()){
                entry = row->at(i);
                qDebug() << entry.length();
            }
            else
                entry = QStringList();
            if(entry.count()==1){
                out << entry.first();
            }else if(entry.count()>1){
                out << '"';//start string list
                for(int j = 0; j<entry.length(); j++) {
                    out << entry.at(j);
                    if(j<entry.length()-1){
                        out << ",";//new string
                    }
                }
                out << '"';//end string list
            }
            if(i<tableColumnCount-2){
                out << ",";//new entry
            }
        }
        out << QChar(0x0D) << QChar(0x0A);//new line
    }
}

void Csv::write(QFile &file)
{
    QTextStream out(&file);
    this->write(out);
}

quint32 Csv::size()
{
    quint32 result;
    foreach(QVector<QStringList>* row,entries){
        for(int i = 0; i<tableColumnCount; i++){
            QStringList entry;
            if (i<row->length()){
                entry = row->at(i);
                qDebug() << entry.length();
            }
            else
                continue;
            if(entry.count()==1){
                result += entry.first().length();
            }else if(entry.count()>1){
                result++;
                for(int j = 0; j<entry.length(); j++) {
                    result += entry.at(j).length();
                    if(j<entry.length()-1){
                        result++;
                    }
                }
                result++;
            }
            if(i<tableColumnCount-2){
                result++;
            }
        }
        result+=2;
    }
}

int Csv::columnCount() const
{
    return tableColumnCount;
}
