#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
/*
 * FILE MANAGER
 * Se encarga de administrar los archivos .txt, los sobreescribe, los lee,...
 */
struct FileManager{
public:
    FileManager();

    //LEE CADA LINEA DEL ARCHIVO
    static QString readFile(QString path);

    //DIVIDE CADA LINEA DEL .TXT Y LO TRANSFORMA EN UNA LISTA QSTRING
    static QStringList splitFile(QString text);

    //ESCRIBE DESPUES DE LA ULTIMA LINEA DE UN ARCHIVO
    static void writeFileA(QString string, QString path);

    //SOBRESCRIBE UN ARCHIVO
    static void writeFileN(QString string, QString path);
};

#endif // FILEMANAGER_H
