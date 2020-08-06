#ifndef PERSONA_H
#define PERSONA_H
#include <QString>
#include <QVector>
#include "dlinklist.h"
#include <QDateTime>

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
    int sins[7] = {0,0,0,0,0,0,0};
    //ArrayList goodActions
    int goodActions[7] = {0,0,0,0,0,0,0};


    //Constructor
    Person(){
        id = 0;
        name = "";
        secondName = "";
        country = "";
        beliefs = "";
        career = "";
        sons = new DLinkList<Person>();
        father = nullptr;
        state = VIVO;
        binacle = "";
    }

    Person(int id, QString name, QString secondName, QString country, QString beliefs, QString career){
        this->id = id;
        this->name = name;
        this->secondName = secondName;
        this->country = country;
        this->beliefs = beliefs;
        this->career = career;
        this->father = nullptr;
        this->sons = new DLinkList<Person>();
        this->state = VIVO;
    }

    //Methods
    //Imprimir buenas acciones
    void printActions();
    //Imprimir pecados
    void printSins();
    //IGUALA EL PADRE
    void setFather(Person *person);
    //SI TIENE PADRE O NO
    bool hasFather();
    void imprimir();
    //CAMBIA ESTADO (CONDENADO,VIVO,SALVADO)
    void changeState(QString state);
    //AGREGA HIJO
    void addSon(Person *newSon);
    //IMPRIMIR HIJOS
    void printHijos();
    //ADD SIN
    void addSin(int sinIndex, int cantidad);
    //ADD GOOD ACTION
    void addAction(int sinIndex, int cantidad);
    //ADD SIN TO SONS
    void addSinAUX(int sinIndex,int cant);
    //ADD GOOD ACTION TO SONS
    void addGoodActionAUX(int aIndex,int cant);
    //ADD TO NIETOS
    void addNietos(int index,int cant,bool type);
    //VERIFY IF SON IS IN LIST
    bool verifySon(Person *person);
    //CALCULA EL NUMERO DE PECADOS DE 1 SOLO PECADO
    int totalSins(int sin);
    //CALCULA EL TOTAL DE PECADOS
    int totalSins();
    //ESCRIBIR CONDENA
    QString demonicBinnacle(int sinIndx);
    //Escribir Persona
    QString humanInfo();
    //Escribir Datos Personales y Estado
    QString showPersonalData();
    //Escribir Hijos
    QString showSons();
    //Escribir Pecados;
    QString showSins();
    //Escribir Buenas Acciones;
    QString showGoodActions();
};

#endif // PERSONA_H
