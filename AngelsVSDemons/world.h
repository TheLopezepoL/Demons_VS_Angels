#ifndef MUNDO_H
#define MUNDO_H
#include <QVector>
#include "abb.h"
#include "dlinklist.h"
#include "filemanager.h"
#include "hell.h"
#include "heaven.h"
#include "humans.h"
struct World{
    //////////////////////////////////////
    //Attr.
    //////////////////////////////////////
    Hell *hell;
    Heaven *heaven;
    //////////////////////////////////////
    int population;
    //////////////////////////////////////
    //ARRAYS/////////////////////
    //////////////////////////////////////
    QVector <int> ids;
    QStringList names;
    QStringList secondNames;
    QStringList countries;
    QStringList religions;
    QStringList careers;
    //////////////////////////////////////
    //STRUCTS//////////////////
    //////////////////////////////////////
    Humans *peopleList;
    ABB *abb;
    //////////////////////////////////////
    //Constr.
    //////////////////////////////////////
    World(){
        this->population = 0;
    }
    //////////////////////////////////////
    //Methods
    //Creador de listas nombres,apellidos,profesiones,...
    void preStart(QString path);
    //Creador de Arbol del Mundo
    void abbGenerator();
    void abbGeneratorAux(int cant,int times);
    int getPowerTwo(int n);
    //Nacimiento de humanos
    void birth(int quant);
    //Genera los pecados
    void sinGenerator();
    //Genera las buenas acciones
    void blessGenerator();
    //Consulta de Pecados
    void sinInfo();
    //Consulta de Buenas Acciones
    void blessInfo();
    //Verifica y devuelve el ID en el rango dado
    int getHumanID(int min,int max);
    //Print Humnas
    void imprimirHumanos();
    //////////////////////////////////////

};

#endif // MUNDO_H