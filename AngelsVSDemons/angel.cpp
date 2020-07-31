#include "angel.h"
#include <QDebug>
/* HUMAN SAVED
 * E: Un puntero a persona
 * S: No tiene
 * D: Asigna el humano al angel
 */

void Angel::setHuman(Person *humanSaved){
    this->humanSaved = humanSaved;
}

void Angel::printAngel(){
    qDebug() << "";
    qDebug() << "Nombre: " << this->name;
    qDebug() << "Gen: "  << this->gen;
    qDebug() << "Version: "  << this->version;
}
