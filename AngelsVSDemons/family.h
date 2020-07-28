#ifndef FAMILY_H
#define FAMILY_H
#include <QString>
#include "dlinklist.h"
#include "person.h"


struct Family{
    QString secondName;
    QString country;
    DLinkList<Person>* family;
    int sins;

    Family();
    Family(QString country, QString secondName);

    bool isFamily(Person* person);
    Person* saveHuman(Person* person, int sin);
    void addHuman(Person* person, int sin);
};

#endif // FAMILY_H
