#ifndef DEMON_H
#define DEMON_H
#include <QString>
#include "heapfamilies.h"
#include "dlinklist.h"
#include "person.h"

struct Demon{

    //Attr.
    QString name;
    QString sin;
    //TIPO DE PECADO EN EL ARRAY (ID)
    int sinIndex;
    //Bitacora Demoniaca
    QString binnacle;
    //ARBOL DE FAMILIAS
    HeapFamilies heapFamilias;
    //Lista de Humanos tomados del mundo
    DLinkList<Person> humanosTomados;
    //Cantidad de Humanos que el demonio ha recogido
    int quant;
    //Constr.
    Demon(QString name,QString sin, int sinIndex){
        this->name = name;
        this->sin = sin;
        this->sinIndex = sinIndex;
    }
    //Methods
    void claimSinners();

};

#endif // DEMON_H
