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

/* Verifica si tiene padre
    E: NO TIENE
    S: BOOL
    D: Verifica si tiene padre, si no tiene entonces retorna false.
*/

bool Person::hasFather(){
    if (this->father != nullptr)
        return true;
    else
        return false;
}


/* Set Father
 * E: Un puntero a persona
 * S: No tiene
 * D: Setea el el puntero padre a la persona(puntero) recibida
 */

void Person::setFather(Person *person){
    if (!this->hasFather()){
        this->father = person;
    }
}


/* Agregar hijo al array
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */

void Person::addSon(Person *newSon){
    
    for (int i=0; i<6;i++){
        if (sons[i])
            continue;
        else{
            newSon->father = this;
            sons[i]=newSon;
            break;
        }
    }
}

/* Imprime hijos
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */
void Person::printHijos(){
    qDebug() << "";
    qDebug() << "------------LISTA DE HIJOS------------";
    for (int i=0; i<6;i++){
        qDebug() << "HIJO #" << i+1;
        this->sons[i]->imprimir();
    }
    qDebug() << "";
}

