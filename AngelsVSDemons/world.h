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
    int cantidadCadaPecado[7] = {0,0,0,0,0,0,0};
    int cantidadCadaBuenaAccion[7] = {0,0,0,0,0,0,0};
    QString goodActions[7] = {"HONRA","AYUDA","FELICIDAD","LABORIOSIDAD","GENEROSIDAD","SATISFACCION","HONESTIDAD"};
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
    //Set winner
    QString setWinner();
    //Da la cantidad de Pecados de cada pecado
    QString cantidadPecadosQString();
    //Da la cantidad de cada una de las Buenas Acciones
    QString cantidadBuenasAccionesQS();
    //Creador de listas nombres,apellidos,profesiones,...
    void preStart(QString path);
    //Sort de Paises
    void sortListSins();
    void sortListGoodActions();
    //InsertsortList
    void iCRnsertSL(Node<Counter> *x,Node<Counter> *y);
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

    //Buscar por ID
    Person* searchHuman(int id); // Llamada a la funcion simplificada
    Person* searchHuman(int id, NodeABB* node); // Busca en el arbol
    Person* searchHuman(int id, NodeHuman* ptr); // Busca en la lista desde el nodo del arbol mas cercano
    //Crea una lista con toda la familia del ID
    DLinkList<Person>* getFamily(int id);
    //Mostrar Pecados Familia (Por ID)
    QString familySins(int id);
    //Mostrar Buenas Acciones Familia (Por ID)
    QString familyGoodActions(int id);
    //Mostrar Infierno (Por demonio)
    QString showHell(int demonIdx);
    //Mostrar Cielo (Por Hash Table)
    QString showHeaven();
    //Buscar por Apellido y Ciudad (Aunque no esten relacionados de sangre)
    QString searchFamily(QString secondName, QString country);
    //Buscar y mostrar porcentaje de una categoria en TODOS los humanos
    void printAllHumansInfo(bool sins);  //Llamada a la funcion, crea un archivo llamado allInfo.txt
    QString printAllHumansInfo(int category, bool sins); //Busca todas las posibles llamadas para apellidos etc...
    QString printAllHumansInfoSins(int category, QString data); //Recorre toda la lista de humanos buscando coicidencias y devuelve el ID y porcentaje
    QString printAllHumansInfoGoodActions(int category, QString data);


    //Mapa de Continentes
    //////////////////////////////////////


};

#endif // MUNDO_H
