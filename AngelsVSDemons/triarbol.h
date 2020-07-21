#ifndef TRIARBOL_H
#define TRIARBOL_H
#include "angel.h"
struct NodeT{
    //Attr.
    Angel *angel;
    NodeT *first,*second,*third;
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
};

#endif // TRIARBOL_H
