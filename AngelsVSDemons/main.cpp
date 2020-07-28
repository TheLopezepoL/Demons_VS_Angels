#include "mainwindow.h"

#include <QApplication>
#include "abb.h"
#include <QRandomGenerator>
#include "filemanager.h"
#include "world.h"
int main(int argc, char *argv[])
{
    World *mundo = new World();
    //"/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels"
    //"/home/rev/Documents/GitHub/Demons_VS_Angels"
    mundo->preStart("/home/rev/Documents/GitHub/Demons_VS_Angels");
    mundo->birth(10000);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
