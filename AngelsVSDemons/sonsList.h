#ifndef SONSLIST_H
#define SONSLIST_H
#include "person.h"
//Nodo de lista Hijos
struct NodeSon{
    //Attributes
    Person *person;
    NodeSon *nxt,*prv;

    //Constructor
    NodeSon(Person *person){
        this->person = person;
        nxt = prv = nullptr;
    }

    //Methods
};
struct SonsList{
    //Attributes
    NodeSon *first,*last;

    //Constructor
    SonsList(){
        first = last = nullptr;
    }

    //Methods
    bool isEmpty();
    void append(Person* hijo);
    void popLast();
    NodeSon* searchSon(QString id);
    void printList();
    int length();
};

#endif // SONSLIST_H
