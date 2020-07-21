#ifndef HEAP_H
#define HEAP_H
#include "person.h"

struct NodeH{
  //Attr.
    //Punteros
  NodeH *leftSon,*rightSon;
    //Determina si tiene padre o no
  bool hasFather;
    //Persona almacenada
  Person* data;
  //Constr.
  NodeH(Person* data){
      leftSon = rightSon = nullptr;
      this->hasFather = false;
      this->data = data;
  }
};

struct HeapPerson{
    //Attr.
    QString country;
    QString lastName;
    NodeH *root;
    //Constr.
    HeapPerson(QString country, QString lastName){
        this->country = country;
        this->lastName = lastName;
        root = nullptr;
    }
    //Methods
    //Inserta en el Heap
    void insertar(Person *person);
    NodeH *insertarAux(NodeH *node,Person *person);
    //Elimina del Heap
    void eliminar(Person*person);
    //Cuenta los nodos del heap
    int contNodos();
};

#endif // HEAP_H
