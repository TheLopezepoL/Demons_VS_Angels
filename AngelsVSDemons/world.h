#ifndef MUNDO_H
#define MUNDO_H
#include <QVector>
#include "abb.h"
#include "dlinklist.h"
#include "filemanager.h"
#include "heaven.h"
#include "counter.h"
#include "humans.h"
#include "demon.h"
struct World{
    //////////////////////////////////////
    //Attr.
    //////////////////////////////////////
    Heaven *heaven;
    //////////////////////////////////////
    int population = 0;
    int counterSins = 0;
    int counterGA = 0;
    //////////////////////////////////////
    //STRINGS DE MENSAJES
    QString tree = "";
    QString binnacle = "";
    QString top = "";
    QString cantPecadosCont = "";
    QString cantGA = "";
    //////////////////////////////////////
    //ARRAYS/////////////////////
    //////////////////////////////////////
    QVector <int> ids;
    QStringList names;
    QStringList secondNames;
    QStringList countries;
    QStringList religions;
    QStringList careers;
    QStringList continents;
    //////////////////////////////////////
    //STRUCTS//////////////////
    //////////////////////////////////////
    Humans *peopleList;
    ABB *abb;
    DLinkList<Counter> *paises;
    DLinkList<Counter> *paisesGA;
    //////////////////////////////////////
    Demon* hell[7];
    //////////////////////////////////////
    //Constr.
    //////////////////////////////////////
    World(){}
    //////////////////////////////////////
    //Methods
    //Creador de listas nombres,apellidos,profesiones,...
    void preStart(QString path);
    //Sort de Paises
    void sortListSins();
    void sortListGoodActions();
    //InsertsortList
    void insertSL(Node<Counter> *x,Node<Counter> *y);
    //Creador de Lista Paises
    void countryList();
    void printCountryListSins();
    void printCountryListGA();
    //Creador de Arbol del Mundo
    void abbGenerator();
    void abbGeneratorAux(int cant,int times);
    int getPowerTwo(int n);
    //Set Hijos de Humano
    void setSons();
    void setSonsAux(Person *person);
    //Nacimiento de humanos
    void birth(int quant);
    //Genera los pecados
    void sinGenerator();
    //Suma pecados a cada pais
    void addCountrySins(int cant ,QString name);
    //Suma buenas acciones a cada pais
    void addCountryGA(int cant ,QString name);
    //Genera las buenas acciones
    void blessGenerator();
    //Verifica y devuelve el ID en el rango dado
    int getHumanID(int min,int max);
    //Print Humnas
    void imprimirHumanos();
    //Top de 10 paises mas pecadores
    DLinkList<Counter> *top10Sins();
    //Top de 10 paises con mejores acciones
    DLinkList<Counter> *top10GA();
    //Print de los tops
    QString printTops(DLinkList<Counter> *top);
    //Top de 5 paises menos pecadores
    DLinkList<Counter> *top5LessSins();
    //Top de 5 paises con pocas buenas acciones
    DLinkList<Counter> *top5LessGA();

    //GET MAPA
    QStringList getMapa(bool key);
    int getCantContinent(QString continent);
    ///////////////////////////////////////////

    //Cantidad de Humanos contenados
    int quantDeadHumans();
    //Return nombre y pecado de x demonio
    QString selectDemon(int x);


    //Mapa de Continentes
    //////////////////////////////////////


};

#endif // MUNDO_H
