#include "structcreator.h"
#include <QDateTime>
#include <QRandomGenerator>

/* CREAR HUMANO
 * E:
 * S:
 * D:
 */

Person *StructCreator::createPerson(int id, QString name, QString secondName, QString country, QString beliefs, QString career){
    Person *nuevo = new Person(id,name, secondName,country, beliefs, career);
    return nuevo;
}

/*  GET RANDOM LIST
 * E: Una QLista
 * S: Un QString
 * D: Selecciona al azar un QString de la Lista
 */

QString StructCreator::getRand(QStringList list){

    int n =((randomInit(0,4122001)%list.length()));
    return list.takeAt(n);
}
//Selecciona un numero random
int StructCreator::randomInit(int n, int seed){
    std::uniform_int_distribution<int> dist(n,seed);
    return dist(*QRandomGenerator::global());
}

/* CREA UN ANGEL
 * E: Atr Angel
 * S: Un Puntero a Angel
 * D: Crea un angel con los datos recibidos
 */

Angel *StructCreator::createAngel(QString name, int version, int gen){
    Angel *nuevo = new Angel(name,version,gen);
    return nuevo;
}
/*Heapify
 * E:
 * S:
 * D:To heapify a subtree rooted with node i which is
an index in arr[]. N is size of heap
 */

/*
void StructCreator::heapify(Person heap[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i+1; // left = 2*i + 1
    int r = 2*i+2; // right = 2*i + 2

    //If left child is larger than root
    if (l < n && heap[l].id > heap[largest].id){
        largest = l;
    }
    // If right child is larger than largest so far
    if (r < n && heap[r].id > heap[largest].id)
        largest = r;

    //If largest is not root
    if (largest != i){
        swap(heap[i],heap[largest]);

    }

}
*/
