#ifndef HELL_H
#define HELL_H
#include "dlinklist.h"
#include "person.h"
#include "demon.h"
#include <QVector>

struct Hell{
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
    Hell(QString email){
        this->email = email;
    };
    //Methods
    void start();


};

#endif // HELL_H
