#include "heapPerson.h"


/* Insertar
 * E:
 * S:
 * D:
 */

void HeapPerson::insertar(Person *person){
    root = insertarAux(root,person);
}

/* Insertar AUXILIAR
 * E:
 * S:
 * D:
 */

NodeH* HeapPerson::insertarAux(NodeH *node, Person *person){
    if (node == nullptr)
        return new NodeH(person);
    else if (node->leftSon == nullptr) {
        return
    }
}
