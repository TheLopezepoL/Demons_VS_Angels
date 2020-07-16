#ifndef LISTAPERSONASMUNDO_H
#define LISTAPERSONASMUNDO_H
#include "person.h"
//Nodo de Lista de Personas
struct NodePerson{
    //Attr.
    Person *person;
    NodePerson *nxt,*prv;
    //Constr.
    NodePerson(Person *person){
        this->person =person;
        nxt = prv = nullptr;
    }
    //Methods

};
struct PeopleList{
    //Attr.
    NodePerson *first,*last;
    //Constr.
    PeopleList(){
        first = last = nullptr;
    }
    //Methods
    //Methods
    bool isEmpty();
    void append(Person* person);
    NodePerson* searchPerson(QString id);
    void printList();
    int length();
};

#endif // LISTAPERSONASMUNDO_H
