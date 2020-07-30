#include "family.h"

Family::Family()
{
    family = new DLinkList<Person>();
    country = "";
    secondName = "";
    sins = 0;
}

Family::Family(QString country, QString secondName){
    this->country = country;
    this->secondName = secondName;
    family = new DLinkList<Person>();
    sins = 0;
}

bool Family::isFamily(Person *person){
    if (person != nullptr){
        Person* ptr = this->family->first->data;
        if (person->country == ptr->country && person->secondName == ptr->secondName)
            return true;
    }
    return false;
}

Person* Family::saveHuman(Person *person, int sin){
    if (person != nullptr){
        this->sins -= person->totalSins(sin);
        return this->family->erradicate(person);
    }
    return nullptr;
}

void Family::addHuman(Person *person, int sin){
    if (person != nullptr){
        this->sins += person->totalSins(sin);
        this->family->append(person);
    }
}

void Family::mostrarFamilia(){
    Node<Person>* person = this->family->first;
    while(person != nullptr){
        person->data->imprimir();
        person = person->nxt;
    }
}
