#ifndef CONTINENT_H
#define CONTINENT_H
#include <QStringList>

struct Continent{
    //Attr.
    QString name;
    QStringList paises;
    int cant;

    //Constr.
    Continent(QString name){
        this->cant =0;
        this->name = name;
    }
    //Methods


};

#endif // CONTINENT_H
