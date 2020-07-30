#include "soul.h"

Soul::Soul(){
    this->angel = new Angel("", 0, 0);
    this->human = new Person();
}

Soul::Soul(Person* human, Angel* angel){
    this->human = human;
    this->angel = angel;
}
