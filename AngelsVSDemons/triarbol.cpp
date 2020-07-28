#include "triarbol.h"
/* SET GODS
 * E:
 * S:
 * D:
 */
void TriArbol::setGods(){
    Angel *serufines = new Angel("SERUFINES",0,0);
    Angel *querabines = new Angel("QUERABINES",0,0);
    Angel *tronos = new Angel("TRONOS",0,0);
    this->god->first = new NodeT(serufines);
    this->god->second = new NodeT(querabines);
    this->god->third = new NodeT(tronos);
}
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


}


/* AGREGA TRES ANGELES A UN NODE
 * E: Un node de angel y un int
 * S: No tiene
 * D: Agrega tres angeles
 */

