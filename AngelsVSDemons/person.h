#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
#include <QVector>
#include "dlinklist.h"

struct Person{

    //Attributes
    int id;
    QString name;
    QString secondName;
    QString country;
    QString beliefs;
    QString career;
    DLinkList<Person> *sonsList;
    //Bitacora
    QString binacle;
    //ArrayList sins
    QVector <int> sins[7];
    //ArrayList goodActions
    QVector <int> goodActions[7];

    //Constructor
    Person(int id, QString name, QString secondName, QString country, QString beliefs, QString career, DLinkList<Person> *sonsList){
        this->id = id;
        this->name = name;
        this->secondName = secondName;
        this->country = country;
        this->beliefs = beliefs;
        this->career = career;
        this->sonsList = sonsList;
    }

    //Methods
    void imprimir();




};

#endif // PERSONA_H
