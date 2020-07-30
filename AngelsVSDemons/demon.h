#ifndef DEMON_H
#define DEMON_H
#include <QString>

#include "dlinklist.h"
#include "person.h"
#include "demonicheap.h"
#include "email.h"
#include "humans.h"
#include "filemanager.h"
#include <QDateTime>

struct Demon{

    //Attr.
    QString name;
    QString sin;
    //TIPO DE PECADO EN EL ARRAY (ID)
    int sinIndex;
    //Bitacora Demoniaca
    QString binnacle;
    //ARBOL DE FAMILIAS
    DemonicHeap* heap;
    //Cantidad de Humanos que el demonio ha recogido
    int quant;
    //Lista de Humanos del mundo
    Humans* world;


    //Constr.
    Demon(QString name,QString sin, int sinIndex, Humans* world){
        this->name = name;
        this->sin = sin;
        this->sinIndex = sinIndex;
        this->world = world;
        binnacle = "";
        heap = new DemonicHeap();
        quant = 0;
    }

    Demon(){
        name = "";
        sin = "";
        sinIndex = 0;
        world = new Humans();
        binnacle = "";
        heap = new DemonicHeap();
        quant = 0;
    }

    //Methods
    void claimSinners(int quant);
    void sendEmail();
    int average();
    Family* min();
    Family* max();

};

#endif // DEMON_H
