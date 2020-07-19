#include "mainwindow.h"

#include <QApplication>
#include "abb.h"
#include "filemanager.h"
#include "world.h"
int main(int argc, char *argv[])
{
    World *mundo = new World();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
