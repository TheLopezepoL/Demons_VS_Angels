#ifndef SOUL_H
#define SOUL_H
#include "angel.h"


struct Soul {
    Person* human;
    Angel* angel;

    Soul();
    Soul(Person* human, Angel* angel);

};

#endif // SOUL_H
