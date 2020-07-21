#ifndef MUNDO_H
#define MUNDO_H
#include "abb.h"
#include "dlinklist.h"
#include "filemanager.h"
#include "heapPerson.h"
struct World{
    //////////////////////////////////////
    //Attr.
    //////////////////////////////////////
    int population;
    //////////////////////////////////////
    //ARRAYS/////////////////////
    //////////////////////////////////////
    QStringList names;
    QStringList secondNames;
    QStringList countries;
    QStringList religions;
    QStringList careers;
    //////////////////////////////////////
    //STRUCTS//////////////////
    //////////////////////////////////////
    DLinkList<Person> *peopleList;
    DLinkList<HeapPerson> *families;
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
    void abbCreator(DLinkList<Person> *peopleList);
    //Nacimiento de humanos
    void birth(int quant);
    //Cantidad de Humanos
    int getPopulation();
    //Verifica si existe la familia del humano y retorna el nodo al arbol
    Node<HeapPerson>* verifyFamilyExistance(QString country,QString lastName);
    //Genera los pecados
    void sinGenerator();
    //Genera las buenas acciones
    void blessGenerator();
    //Consulta de Pecados
    void sinInfo();
    //Consulta de Buenas Acciones
    void blessInfo();
    //////////////////////////////////////


};

#endif // MUNDO_H
