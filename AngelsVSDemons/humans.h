#ifndef HUMANS_H
#define HUMANS_H
#include "person.h"



struct NodeHuman{
    //Attr.
    NodeHuman *nxt,*prv;
    Person *person;
    //Constr.
    NodeHuman(Person *person){
        this->nxt = nullptr;
        this->prv = nullptr;
        this->person = person;
    }
};

struct Humans{
    //Attr.
    NodeHuman *first,*last;
    //Constr.
    Humans(){
        this->last = this->first = nullptr;
    }
    //Methods
    bool isEmpty();
    int length();
    void insertPos(Person *person);
    Person *returnHuman(int pos);

    
};

#endif // HUMANS_H
