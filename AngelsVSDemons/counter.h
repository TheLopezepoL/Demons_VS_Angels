#ifndef COUNTER_H
#define COUNTER_H
#include <QString>

struct Counter{
    //Attr.
    QString name;
    QString continent;
    int cant;
    //Constr.
    Counter(QString name,QString continent, int cant){
        this->name = name;
        this->continent = continent;
        this->cant = cant;
    }

};

#endif // COUNTER_H
