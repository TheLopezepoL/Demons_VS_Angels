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
    mundo->birth(10);
    //mundo->blessGenerator();

    mundo->peopleList->first->person->addSinAUX(0,100);
    mundo->peopleList->first->person->addAction(0,100);
    mundo->imprimirHumanos();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
