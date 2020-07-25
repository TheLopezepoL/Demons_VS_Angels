#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
#include <QVector>
#include "dlinklist.h"

enum State{

    SALVADO,
    CONDENADO,
    VIVO
};

struct Person{

    //Attributes
    int id;
    QString name;
    QString secondName;
    QString country;
    QString beliefs;
    QString career;
    DLinkList<Person> *sons;
    Person *father;
    //Estado
    State state;
    //Bitacora
    QString binacle;
    //ArrayList sins
    QVector <int> sins[7];
    //ArrayList goodActions
    QVector <int> goodActions[7];

    //Constructor
    Person(int id, QString name, QString secondName, QString country, QString beliefs, QString career){
        this->id = id;
        this->name = name;
        this->secondName = secondName;
        this->country = country;
        this->beliefs = beliefs;
        this->career = career;
        this->father = nullptr;
        this->sons = new DLinkList<Person>();
    }

    //Methods
    void setFather(Person *person);
    bool hasFather();
    void imprimir();
    void changeState(QString state);
    void addSon(Person *newSon);
    void printHijos();




};

#endif // PERSONA_H
