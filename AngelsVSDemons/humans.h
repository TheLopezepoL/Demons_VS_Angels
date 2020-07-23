#ifndef HUMANS_H
#define HUMANS_H
#include "person.h"



struct NodeHuman{
    //Attr.
    NodeHuman *nxt,*prv;
    Person *person;
    int state;
    //Constr.
    NodeHuman(Person *person){
        this->nxt = nullptr;
        this->prv = nullptr;
        this->person = person;
        //0 si esta en el mundo,1 en el infierno, 2 en el cielo
        this->state = 0;
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
