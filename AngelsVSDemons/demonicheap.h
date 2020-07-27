#ifndef DEMONICHEAP_H
#define DEMONICHEAP_H
#include "heap.h"
#include "family.h"


struct DemonicHeap{
    Family** array;
    int len;

    DemonicHeap();

    void append(Person* person, int sin);
    Person* erradicate(Person* person, int sin);
    bool hasFamily(Person* person, int sin);
    void insertionSort();

};

#endif // DEMONICHEAP_H
