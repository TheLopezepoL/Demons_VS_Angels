#ifndef HELL_H
#define HELL_H
#include "dlinklist.h"
#include "person.h"
#include "demon.h"
#include <QVector>
#include "humans.h"


struct Hell{
    //Humanos
    Humans *peopleList;
    //Correo del Infierno
    QString email;
    //Bitacora del Infierno
    QString binnacle;
    //Lista de Humanos tomados del mundo
    DLinkList<Person> humanosTomados;
    //Cantidad de Humanos
    int quant;
    //Demonios
    QVector<Demon> demons[7];
    //Cosntr.
    Hell(QString email,Humans *peopleList){
        this->email = email;
        this->peopleList = peopleList;
    };
    //Methods
    void start();
    void condenacion();


};

#endif // HELL_H
