#include "mainwindow.h"

#include <QApplication>
#include <QRandomGenerator>
#include "filemanager.h"
#include "world.h"
#include "triarbol.h"
int main(int argc, char *argv[])
{
    //"/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels"
    //"/home/rev/Documents/GitHub/Demons_VS_Angels"
    /*
    mundo->preStart("/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels");
    mundo->birth(10000);
    mundo->sinGenerator();
    mundo->blessGenerator();
    mundo->imprimirHumanos();
    */
    /*
    TriArbol *n = new TriArbol();
    n->setGods();
    n->newAngels(9);
    n->newAngels(81);
    n->aOrden(n->god,0);
    */
    /*
    Person *n = new Person(1,"Marco","Reveiz","Costa Rica","Catolico","Programador");
    Person *n1 = new Person(2,"Margarita","Reveiz","Costa Rica","Catolico","Programador");
    Person *n2 = new Person(3,"Mariana","Reveiz","Costa Rica","Catolico","Programador");
    Person *n3 = new Person(4,"Lola","Reveiz","Costa Rica","Catolico","Programador");
    Person *n4 = new Person(5,"Fish","Reveiz","Costa Rica","Catolico","Programador");
    n->addSon(n1);
    n->addSon(n2);
    n1->addSon(n3);
    n2->addSon(n4);
    Humans *peopleList = new Humans();
    peopleList->insertPos(n);
    peopleList->insertPos(n1);
    peopleList->insertPos(n2);
    peopleList->insertPos(n3);
    peopleList->insertPos(n4);
    mundo->peopleList = peopleList;
    mundo->sinGenerator();
    mundo->imprimirHumanos();

*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}















