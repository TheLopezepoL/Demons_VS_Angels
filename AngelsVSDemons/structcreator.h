#ifndef GENERATOR_H
#define GENERATOR_H
#include <QRandomGenerator>
#include <QStringList>
#include <QString>
#include "filemanager.h"
#include "person.h"
#include "angel.h"
struct StructCreator{
    StructCreator(){}
    //Methods
    //Selecciona random en lista
    static QString getRand(QStringList list);
    //Selecciona random entre un intervalo
    static int randomInit(int n, int seed);
    //Crea una Persona
    static Person *createPerson(int id, QString name, QString secondName, QString country, QString beliefs, QString career);
    //Crea un Angel
    static Angel *createAngel(QString name,int version, int gen);
    //Crea un Demonio
    // To heapify a subtree rooted with node i which is
    // an index in arr[]. N is size of heap
    static void heapify(Person heap[],int num, int i);
    // Function to build a Max-Heap from the given array
    static void buildHeap(Person arr[], int n);

};

#endif // GENERATOR_H
