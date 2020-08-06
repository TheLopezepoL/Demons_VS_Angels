#include "demonicheap.h"

DemonicHeap::DemonicHeap()
{
    for (int i = 0; i < 10000; i++)
        this->array[i] = nullptr;
    len = 0;
}

void DemonicHeap::append(Person *person, int sin){
    if(person != nullptr && !hasFamily(person, sin)){
        array[len] = new Family(person->country, person->secondName);
        array[len]->addHuman(person, sin);
        len++;

    }
    insertionSort();
}

bool DemonicHeap::hasFamily(Person *person, int sin){
    for (int i=0; i<len; i++){
        if (array[i]->isFamily(person)){
            array[i]->addHuman(person, sin);
            return true;
        }
    }
    return false;
}

Person* DemonicHeap::erradicate(Person *person, int sin){
    Person* deleted = nullptr;
    if (person != nullptr){
        for (int i = 0; i<len; i++){
            if(array[i]->isFamily(person)){
                deleted = array[i]->saveHuman(person, sin);
                if (array[i]->family->isEmpty()){
                    for (int j=i; j<len; j++)
                        array[j] = array[j+1];
                    len--;
                }
                break;
            }
        }
    }
    insertionSort();
    return deleted;
}


void DemonicHeap::insertionSort(){
    int i=0, j=0;
    Family* key = nullptr;
    for (i = 1; i < len; i++){

        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j]->sins <= key->sins){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
