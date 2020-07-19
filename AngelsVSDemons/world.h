#ifndef MUNDO_H
#define MUNDO_H
#include "abb.h"
#include "dlinklist.h"
#include "filemanager.h"

struct World{

    //Attr.

    //ARRAYS/////////////////////
    ////////////////////////////
    QStringList names;
    QStringList secondNames;
    QStringList countries;
    QStringList religions;
    ////////////////////////////
    //STRUCTS//////////////////
    ///////////////////////////
    DLinkList<Person> *peopleList;
    ABB *abb;
    ///////////////////////////
    //Constr.
    World(){}
    //Methods
    void preStart(QString path);

};

#endif // MUNDO_H
