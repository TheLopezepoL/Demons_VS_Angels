#ifndef TRIARBOL_H
#define TRIARBOL_H
#include "angel.h"
#include "demon.h"
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
    NodeT *god;
    int times;
    DLinkList<NodeT> *listaNodes;
    int gens;
    QString angelsNames[10] = {"Miguel","Nuriel","Aniel","Rafael","Gabriel","Shamsiel","Raguel","Uriel","Azrael","Sariel"};
    //Constr.
    TriArbol(){
        Angel *god = new Angel("GOD",0,0);
        this->god = new NodeT(god);
        setGods();
        gens = 0;
        times = 0;

    }
    //Methods
    void setGods();
    void newAngels(Demon* hell[7]);
    QString ranName();
    void aOrden(NodeT *node, int nivel);

};

#endif // TRIARBOL_H
