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
    QString binnacle;
    //Cosntr.
    Angel (QString name,int version, int gen){
        this->name = name;
        this->version = version;
        this->gen = gen;
        this->humanSaved = nullptr;
    }
    //Methods
    void setHuman(Person *humanSaved);
    void printAngel();

};

#endif // ANGEL_H
