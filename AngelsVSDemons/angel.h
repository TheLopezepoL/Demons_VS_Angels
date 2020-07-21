#ifndef ANGEL_H
#define ANGEL_H
#include <QString>
#include "person.h"
struct Angel{
    //Attr.
    QString name;
    int version;
    int gen;
    Person  *humanSaved;


};

#endif // ANGEL_H
