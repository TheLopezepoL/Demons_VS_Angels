#include "filemanager.h"

FileManager::FileManager(){}
//LEE EL ARCHIVO
QString FileManager::readFile(QString path){
    QString content = "";
    QFile inputFile(path);
    if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            QString line = in.readLine();
            int word = 0;
            while(word < line.size()){
                if (line.data()[word] != '\t')
                    content.append(line.data()[word]);
                else
                    content.append("; ");
                word++;
            }
            content.append("*");
        }
        inputFile.close();
    }
    else
        content = "ERROR - READ FILE ("+path+")";
    return content;
}
//VE EL SEPARADOR
QStringList FileManager::splitFile(QString text){
    QStringList newList = text.split("*");
    newList.removeLast();
    return newList;
}

void FileManager::writeFileA(QString string, QString path){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QTextStream stream(&file);
        stream << string << Qt::endl;
    } else
        qDebug() << "ERROR - WRITE FILE ("+path+")";
    file.close();
}

void FileManager::writeFileN(QString string, QString path){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << string << Qt::endl;

    } else
        qDebug() << "ERROR - WRITE FILE ("+path+")";
    file.close();
}
