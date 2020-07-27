#ifndef HEAPS_H
#define HEAPS_H
#include "person.h"
#include <QVector>


struct Heap{
    Person** array;
    int len;

    Heap();

    void append(Person* data);
    bool compare(Person* son, Person* father);
};

#endif // HEAPS_H
