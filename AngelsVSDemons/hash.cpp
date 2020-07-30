#include "hash.h"

Hash::Hash(){
    for (int i = 0; i < 1000; i++)
    this->savedHumans[i] = new DLinkList<Soul>();
}

void Hash::append(Person *person, Angel *angel){
    if (person != nullptr && angel != nullptr){
        Soul* soul = new Soul(person, angel);
        this->savedHumans[person->id%1000]->append(soul);
    }
}
