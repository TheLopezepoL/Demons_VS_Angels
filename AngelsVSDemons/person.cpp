#include "person.h"

#include <QDebug>
/* Imprimir Datos
 *
 */

void Person::imprimir(){
    qDebug();
    qDebug() << "ID: " << this->id;
    qDebug() << "Nombre: " << this->name;
    qDebug() << "Apellido: " << this->secondName;
    qDebug() << "Carrera: " << this->career;
    qDebug() << "Creencia: " << this->beliefs;
}
