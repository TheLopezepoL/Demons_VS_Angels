#include "triarbol.h"
#include "structcreator.h"
/* SET GODS
 * E: No tiene
 * S: No tiene
 * D: Crea los primeros dos niveles del arbol
 */
void TriArbol::setGods(){
    this->listaNodes = new DLinkList<NodeT>();
    Angel *serufines = new Angel("SERUFINES",0,0);
    Angel *querabines = new Angel("QUERABINES",0,0);
    Angel *tronos = new Angel("TRONOS",0,0);
    NodeT *n = new NodeT(serufines);
    NodeT *n1 = new NodeT(querabines);
    NodeT *n2 = new NodeT(tronos);
    this->god->first = n;
    this->god->second = n1;
    this->god->third = n2;
    listaNodes->append(n);
    listaNodes->append(n1);
    listaNodes->append(n2);
}

/* Get Random Name
 * E: No tiene
 * S: Un string con el nombre del angel
 * D: Selecciona un nombre random de la lista de nombres para angeles
 */
QString TriArbol::ranName(){
    int i = StructCreator::randomInit(0,9);
    return angelsNames[i];
}

/* AGREGA TRES ANGELES A UN NODE
 * E: Un node de angel y un int
 * S: No tiene
 * D: Agrega tres angeles
 */


void TriArbol::newAngels(Demon* hell[7]){

    DLinkList<NodeT> *array = new DLinkList<NodeT>();
    Node<NodeT> *tmp = listaNodes->first;
    int version = 0;

    while (tmp != nullptr) {
        qDebug() << tmp->data->angel->name;
        for (int i = 0; i < 3 ; ++i){
           version = version + 1;
           Angel *nuevo = new Angel(ranName(),version,times);

           // Salvar
           int demon = StructCreator::randomInit(0, 6);
           Family* family = hell[demon]->min();
           Node<Person>* person = family->family->first;
           Node<Person>* min = family->family->first;
           while(person != nullptr){
               if (person->data->totalSins() > min->data->totalSins())
                   min = person;
               person = person->nxt;
           }
           hell[demon]->quant--;
           hell[demon]->heap->erradicate(min->data, demon);
           nuevo->humanSaved = min->data;
           // Terminar Salvar
           person = nullptr;
           min = nullptr;
           family = nullptr;
           free(person);
           free(min);
           free(family);
           // Memoria liberada
           NodeT *newNode = new NodeT(nuevo);
           array->append(newNode);
           qDebug() << nuevo->name;
           if (i == 0)
               tmp->data->first = newNode;
           else if (i == 1) {
               tmp->data->second = newNode;
           }
           else if (i == 2) {
               tmp->data->third = newNode;
           }
        }
        tmp = tmp->nxt;
    }
    times++;
    listaNodes = array;
}

//IMPRIMIR/
void TriArbol::aOrden(NodeT *node, int nivel){
    if (node != nullptr){
        qDebug() << "";
        qDebug() << "Nivel: "<<nivel;
        qDebug() << "Node: " << node->angel->name;
        aOrden(node->first, nivel+1);
        aOrden(node->second, nivel+1);
        aOrden(node->third, nivel+1);
        //node->person->imprimir();
    }
}
