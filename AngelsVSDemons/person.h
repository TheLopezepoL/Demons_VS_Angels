#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
#include "sonsList.h"
struct Person{
    //Attributes
    int id;
    QString name;
    QString secondName;
    QString country;
    QString beliefs;
    QString career;
    //ArrayList sins;
    //ArrayList goodActions;
    SonsList *sons;

    //Constructor
    Person(int id, QString name, QString secondName, QString country, QString beliefs, QString career, /*ArrayList sins,ArrayList goodActinos,*/sonsList *sons){
        this->id = id;
        this->name = name;
        this->secondName = secondName;
        this->country = country;
        this->beliefs = beliefs;
        this->career = career;
        this->sons = sons;
        //this->sins = sin;
        //this->goodActions = goodActions
    }



};

#endif // PERSONA_H
