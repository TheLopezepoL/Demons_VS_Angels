#ifndef WARZONE_H
#define WARZONE_H
#include "hell.h"
#include "heaven.h"
#include "world.h"

struct Warzone{
    //Attr.
    Hell *hell;
    Heaven *heaven;
    World *world;
    Humans *humans;
    //Cosntr.
    Warzone(){}
    //Methods
    void invoke();

};

#endif // WARZONE_H
