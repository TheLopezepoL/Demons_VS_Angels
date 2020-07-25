#ifndef TRIARBOL_H
#define TRIARBOL_H
#include "angel.h"
struct NodeT{
    //Attr.
    Angel *angel;
    NodeT *first;
    NodeT *second;
    NodeT *third;
    //Cosntr.
    NodeT(Angel *angel){
        this->angel = angel;
        first = second = third = nullptr;
    }

};
//Arbol 3-ario del Cielo
struct TriArbol{
    //Attr.
    NodeT *root;
    //Constr.
    TriArbol(){
        root = nullptr;
    }
    //Methods
    void insertar(Angel *angel);
    NodeT *insertarAux(Angel *angel,NodeT *node);
    void addAngels(NodeT *node,int i);
};

#endif // TRIARBOL_H
