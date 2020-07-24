#ifndef GENERATOR_H
#define GENERATOR_H
#include <QRandomGenerator>
#include <QStringList>
#include <QString>
#include "filemanager.h"
#include "person.h"
struct StructCreator{
    StructCreator(){}
    //Methods
    static QString getRand(QStringList list);
    static int randomInit(int n, int seed);
    static Person *createPerson(int id, QString name, QString secondName, QString country, QString beliefs, QString career);
    static Node<Person>* checkedNodePos(int id, Node<Person> *first);

};

#endif // GENERATOR_H
