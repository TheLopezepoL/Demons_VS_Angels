#include "heaven.h"

Heaven::Heaven(){
    this->binnacle = "";
    this->arbol = new TriArbol();
    this->souls = new Hash();
}

void Heaven::sendEmail(){
    QString root = "/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels/Salvados/";
    root.append("Salvacion_" + QDateTime::currentDateTime().toString("yyyyMMd_hms"));
    FileManager::writeFileN(binnacle, root);
    Email::sendEmail("Salvacion", binnacle);
}

void Heaven::salvation(Demon *hell[7]){
    this->arbol->newAngels(hell);
        Node<NodeT> *angel = this->arbol->listaNodes->first;
        while(angel != nullptr){
            this->souls->append(angel->data->angel->humanSaved, angel->data->angel);
            binnacle.append(QDateTime::currentDateTime().toString("yyyy-MM-d h:m:s ap") + "\t");
            binnacle.append("Humano #" + QString::number(angel->data->angel->humanSaved->id) + "\t" + angel->data->angel->humanSaved->name + " " + angel->data->angel->humanSaved->secondName + " de " + angel->data->angel->humanSaved->country + "\n");
            binnacle.append("Salvado el " + QDateTime::currentDateTime().toString("yyyy-MM-d"));
            binnacle.append("\tPor " + QString::number(angel->data->angel->humanSaved->totalSins()) + " acciones");
            binnacle.append("\tPor el angel " + angel->data->angel->name + QString::number(angel->data->angel->version) + "\tGeneracion: " + QString::number(angel->data->angel->gen));
            angel = angel->nxt;
        }
}
