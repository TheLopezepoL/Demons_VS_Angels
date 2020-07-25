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
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. N is size of heap
    static void heapify(Person heap[],int num, int i);
    // Function to build a Max-Heap from the given array
    static void buildHeap(Person arr[], int n);

};

#endif // GENERATOR_H
