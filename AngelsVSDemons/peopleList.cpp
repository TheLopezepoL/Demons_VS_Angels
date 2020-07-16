#include "peopleList.h"

//Verifica si la lista esta vacia
bool PeopleList::isEmpty(){
    return first == nullptr;
}

/*
 * INSERTAR UNA PERSONA A LA LISTA DE PERSONAS DEL MUNDO (INSERTAR AL FINAL)
 * E: Una persona
 * S: No tiene
 * D: Agrega una persona en la lista de habitantes del mundo
 */
void PeopleList::append(Person *person){
    if (isEmpty())
        first = last = new NodePerson(person);
    else{
        NodePerson *nuevo = new NodePerson(person);
        last->nxt = nuevo;
        nuevo->prv = last;
        last = nuevo;
    }
}

/*LENTGH
 * E: No tiene
 * S: Int
 * D: Da la cantidad de elem de la lista
 */
int PeopleList::length(){
    int i = 0;
    NodePerson *tmp = first;
    while (tmp != nullptr) {
        ++i;
        tmp = tmp->nxt;
    }
    return i;
}

/*
 * IMPRIMIR
 * E: No tiene
 * S: No tiene
 * D: Imprime las personas del mundo
 */
/*
void PeopleList::printList(){
    NodePerson *tmp = first;
    while (tmp != nullptr){
        tmp->person->
    }
}
*/
