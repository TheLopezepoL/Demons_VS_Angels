#include "humans.h"
/* INSERTAR EN POSICION DE ACUERDO A SU ID
 */
void Humans::insertPos(Person *person){

    NodeHuman *tmp = this->first;
    NodeHuman *nuevo = new NodeHuman(person);

    if (this->first == nullptr){
        this->first = this->last = nuevo;
    }
    else {
        if (nuevo->person->id > this->last->person->id){
            this->last->nxt = nuevo;
            nuevo->prv = this->last;
            this->last = this->last->nxt;
        }

        else if (nuevo->person->id < this->first->person->id){
            this->first->prv = nuevo;
            nuevo->nxt = this->first;
            this->first = this->first->prv;
        }
        else{
            while (tmp != nullptr) {

                if (nuevo->person->id < tmp->person->id){
                   tmp->prv->nxt = nuevo;
                    nuevo->prv = tmp->prv;
                    nuevo->nxt = tmp;
                    tmp->prv = nuevo;
                    break;
                }
                tmp = tmp->nxt;

            }
        }
    }
}


/*BUSCAR HUMANO Y RETORNARLO*/
NodeHuman *Humans::returnHuman(int pos){
    NodeHuman *tmp = first;
    int i = 0;
    while(tmp != nullptr){
        if (i == pos)
            return tmp;
        tmp = tmp->nxt;
        ++i;
    }
    return nullptr;
}

/*LENGHT*/
int Humans::length(){
    int i = 0;
    NodeHuman *tmp = first;
    while(tmp != nullptr){
        ++i;
        tmp = tmp->nxt;
    }
    return  i;
}

//INSERTAR POR CANTIDAD DE PECADOS (DE MENOS A MAS BUENAS ACCIONES)
void Humans::insertBySins(Person *person){

    NodeHuman *tmp = this->first;
    NodeHuman *nuevo = new NodeHuman(person);

    if (this->first == nullptr){
        this->first = this->last = nuevo;
    }
    else {
        if (nuevo->person->totalSins() > this->last->person->totalSins()){
            this->last->nxt = nuevo;
            nuevo->prv = this->last;
            this->last = this->last->nxt;
        }

        else if (nuevo->person->totalSins() < this->first->person->totalSins()){
            this->first->prv = nuevo;
            nuevo->nxt = this->first;
            this->first = this->first->prv;
        }
        else{
            while (tmp != nullptr) {

                if (nuevo->person->totalSins() < tmp->person->totalSins()){
                   tmp->prv->nxt = nuevo;
                    nuevo->prv = tmp->prv;
                    nuevo->nxt = tmp;
                    tmp->prv = nuevo;
                    break;
                }
                tmp = tmp->nxt;

            }
        }
    }
}
