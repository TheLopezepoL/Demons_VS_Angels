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
 *
 *
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

