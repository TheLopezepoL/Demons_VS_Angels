#ifndef HEAVEN_H
#define HEAVEN_H
#include "angel.h"
#include "triarbol.h"
#include "humans.h"
#include <QStringList>
struct Heaven{
    //Attr
    Humans *peopleList;
    QString binnacle;
    TriArbol *arbol;
    QString angelsNames[10] = {"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel","Uriel","Azrael","Sariel"};
    //Constr.
    Heaven(){}
    //Methods
    //Crea las estructuras y recibe la lista de humanos
    void preStart(Humans *peopleList);
    //Crea el 3Arbol
    void narbol();
    //Salvacion
    void salvation();




};

#endif // HEAVEN_H
