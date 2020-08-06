#ifndef ABB_H
#define ABB_H
#include "person.h"
#include "humans.h"
#include <QDebug>

struct NodeABB{
  //Attr.
  NodeABB *leftSon,*rightSon;
  NodeHuman* person;
  //Constr.
  NodeABB(NodeHuman* person){
      leftSon = rightSon = nullptr;
      this->person = person;
  }
};

struct ABB{
    //Attr.
    NodeABB *root;
    //Constr.
    ABB(){
        root = nullptr;
    }
    //Methods
    void insertar(NodeHuman*);
    NodeABB *insertarAux(NodeHuman* person, NodeABB *node);
    int nodeCounter(NodeABB *node);
    NodeABB *search(int valor , NodeABB *node);
    QString posOrden(NodeABB *node, int nivel);
    QString binnacle();
    void preOrden(NodeABB *node, int nive);



};

#endif // ABB_H
