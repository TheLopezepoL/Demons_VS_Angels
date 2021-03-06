#include "heap.h"

Heap::Heap(){
    array = {};
    len = 0;
}

void Heap::append(Person *data){

    Person *newArray[++len];
    for (int i=0; i<len-1; i++)
            newArray[i] = array[i];
    newArray[len] = data;
    array = newArray;

    int son = len;
    while(son != 0 && compare(array[son], array[(son-(son%2))/2])){
        Person* swap = array[(son-(son%2))/2];
        array[(son-(son%2))/2] = array[son];
        array[son] = swap;
    }

}

//DEVUELVE TRUE SI EL HIJO ES MAS PECADOR QUE EL PADRE, FALSE EN CASO CONTRARIO O SI UNO ES NULO
bool Heap::compare(Person *son, Person *father){
    if(son != nullptr && father != nullptr){
        if(son->totalSins() < father->totalSins()) //el menor es mas pecador
            return true;
    }
    return false;
}
