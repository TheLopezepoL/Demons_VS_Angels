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

/*CAMBIAR ESTADO
 */
void Person::changeState(QString state){

    if (state == "SALVADO")
        this->state = SALVADO;
    else  if (state == "CONDENADO")
        this->state = CONDENADO;
    else  if (state == "VIVO")
        this->state = VIVO;
}
