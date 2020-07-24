#include "mainwindow.h"

#include <QApplication>
#include "abb.h"
#include <QRandomGenerator>
#include "filemanager.h"
#include "world.h"
int main(int argc, char *argv[])
{
    World *mundo = new World();
    mundo->preStart("/home/rev/Documents/GitHub/Demons_VS_Angels");
    mundo->birth(400);
    mundo->birth(300);
    mundo->birth(300);
    qDebug() << mundo->ids.length();
    //mundo->abbGenerator();
    //qDebug() << mundo->getPowerTwo(10);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
