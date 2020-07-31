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

void Heaven::salvation(){

}
