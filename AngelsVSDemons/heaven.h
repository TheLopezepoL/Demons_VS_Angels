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
    int cantidadAngeles;
    //Constr.
    Heaven(Humans *peopleList){
        this->peopleList = peopleList;
        this->arbol = new TriArbol();
    }
    //Methods
    //Salvacion
    void salvation();



};

#endif // HEAVEN_H
