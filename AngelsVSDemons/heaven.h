#ifndef HEAVEN_H
#define HEAVEN_H
#include "angel.h"
#include "triarbol.h"
#include "humans.h"
#include "hash.h"
#include <QStringList>
struct Heaven{
    //Attr
    QString binnacle;
    TriArbol *arbol;
    Hash* souls;
    //Constr.
    Heaven();
    //Methods
    //Salvacion
    void salvation();
    void sendEmail();




};

#endif // HEAVEN_H
