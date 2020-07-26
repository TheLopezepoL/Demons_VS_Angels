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
    qDebug() << "Pais: " << this->country;


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
/* Agregar hijo a la lista de hijos
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */
void Person::addSon(Person *newSon){
    newSon->setFather(this);
    this->sons->append(newSon);
}

/* Imprime hijos
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */
void Person::printHijos(){
    int i = 1;
    Node<Person> *tmp = sons->first;
    qDebug() << "";
    qDebug() << "------------LISTA DE HIJOS------------";
    while (tmp != nullptr) {
        qDebug() << "";
        qDebug() << "HIJO #" << i;
        tmp->data->imprimir();
        tmp = tmp->nxt;
        qDebug() << "";
        ++i;
    }
    qDebug() << "--------------------------------------";
}
//Imprime los pecados
void Person::printSins(){
    qDebug() << " ";
    qDebug() << "LISTA DE PECADOS";
    QString sins[7] = {"ORGULLO","ENVIDIA","IRA","PEREZA","CODICIA","GLOTONERIA","LUJURIA"};
    for (int i = 0; i<7 ; ++i){
        qDebug() << " ";
        qDebug() << sins[i] << ": " << this->sins[i];
    }
}
//Imprime los pecados
void Person::printActions(){
    qDebug() << " ";
    qDebug() << "LISTA DE BUENAS ACCIONES";
    QString goodActions[7] = {"HONRA","AYUDA","FELICIDAD","LABORIOSIDAD","GENEROSIDAD","SATISFACCION","HONESTIDAD"};
    for (int i = 0; i<7 ; ++i){
        qDebug() << " ";
        qDebug() << goodActions[i] << ": " << this->goodActions[i];
    }
}
/* Suma pecados
 * E: Dos ints
 * S: No tiene
 * D: Le suma un pecado al que se encuentre en el index recibido
 */
void Person::addSin(int sinIndex, int cantidad){
    this->sins[sinIndex] = this->sins[sinIndex] + cantidad;
}
/*Suma buenas acciones
 * E: Dos ints
 * S: No tiene
 * D: Le suma un pecado al que se encuentre en el index recibido
 */
void Person::addAction(int aIndex, int cantidad){
    this->goodActions[aIndex] = this->goodActions[aIndex] + cantidad;
}
/* Suma pecados a hijos
 * E: Un puntero a lista de hijos, DOS INTS
 * S: No tiene
 * D: Suma los nuevos pecados a los hijos de la persona
 */
void Person::addSinAUX(int sinIndex,int cant){
    int res = cant/2;
    Node<Person> *son = this->sons->first;
    while (son != nullptr){
        son->data->addSin(sinIndex,res);
        son->data->addNietos(sinIndex,res,false);
        son = son->nxt;
    }

}
/* Suma buenas acciones a hijos
 * E: Un puntero a lista de hijos, DOS INTS
 * S: No tiene
 * D: Suma buenas acciones a los hijos de la persona
 */
void Person::addGoodActionAUX(int aIndex, int cant){
    int res = cant/2;
    Node<Person> *son = this->sons->first;
    while (son != nullptr){
        son->data->addAction(aIndex,res);
        son->data->addNietos(aIndex,res,true);
        son = son->nxt;
    }

}
/* Suma pecado a los nietos
 * E: Dos ints, boolean
 * S: No tiene
 * D: Verifica que a que se le tiene que sumar
 */
void Person::addNietos(int index, int cant, bool type){
    Node<Person> *nieto = this->sons->first;
    int res = cant/2;
    if (type){
        while (nieto != nullptr){
            nieto->data->addAction(index,res);
            nieto = nieto->nxt;
        }
    }
    else if (!type){
        while (nieto != nullptr){
            nieto->data->addSin(index,res);
            nieto = nieto->nxt;
        }
    }
}

/*  VERIFY SON
 * E: Un puntero a persona
 * S: Un booleano
 * D: Checkea si la persona recibida esta en la lista de hijos
 */
bool Person::verifySon(Person *person){
    Node<Person> *tmp = this->sons->first;
    while( tmp != nullptr){
        if (tmp->data == person)
            return true;
        tmp = tmp->nxt;
    }
    return false;
}









