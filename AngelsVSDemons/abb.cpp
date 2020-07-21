#include "abb.h"


/*  INSERTAR RECURSIVO
 *  E: Un objeto
 *  S: No tiene
 *  D: Agrega un objeto al arbol
 */
//PRIMARY
void ABB::insertar(Person* person){
    root = insertarAux(person,root);
}
//AUXILIAR
NodeABB * ABB::insertarAux(Person* person, NodeABB *node){
    if (node == nullptr)
        return new NodeABB(person);

    else if (node->person->id < person->id) {
         node->rightSon = insertarAux(person,node->rightSon);
    }
    else if (node->person->id > person->id){
         node->leftSon = insertarAux(person,node->leftSon);
    }
    return node;
}

/*  inOrden
 * E: Un node
 * S: No tiene
 * D: Imprime el arbol en orden*/
void ABB::inOrden(NodeABB *node){
    if (node != nullptr){
        inOrden(node->leftSon);
        qDebug() << node->person->id << " ";
        inOrden(node->rightSon);
    }
};
/* Node Counter
 * E: Node
 * S: Int
 * D: Cuenta la cantidad de nodos del arbol
 */
int ABB::nodeCounter(NodeABB *node){
    if (node == nullptr)
        return 0;
    else
        return 1 + nodeCounter(node->rightSon) + nodeCounter(node->leftSon);
}

/* BUSCAR DATO
 * E: Un integer, un node
 * S: Un node
 * D: Buscar el valor en el arbol
 */

NodeABB *ABB::search(int valor, NodeABB *node){
    if (node == nullptr)
        return nullptr;
    else if (node->person->id == valor) {
        return node;
    }
    else if (node->person->id < valor)
        return search(valor,node->rightSon);
    else{
        return search(valor,node->leftSon);
    }
}
