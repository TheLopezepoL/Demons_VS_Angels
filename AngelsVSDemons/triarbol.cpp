#include "triarbol.h"

/* INSERTAR
 * E: Un puntero a angel
 * S: No tiene
 * D: Agrega un angel en el arbol
 */

void TriArbol::insertar(Angel *angel){
    root = insertarAux(angel,root);
}

/* INSERTAR AUXILIAR
 * E: Un node y un angel
 * S: Un node
 * D: Inserta un nodo en el arbol
 */

NodeT *TriArbol::insertarAux(Angel *angel, NodeT *node){
    if (node == nullptr)
        return new NodeT(angel);
    else{


    }

}


/* AGREGA TRES ANGELES A UN NODE
 * E: Un node de angel y un int
 * S: No tiene
 * D: Agrega tres angeles
 */

