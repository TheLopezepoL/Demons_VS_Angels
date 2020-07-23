#include "world.h"
#include <QRandomGenerator>
#include <QtMath>
#include "structcreator.h"
/* ALISTADOR DE ARRAYS
 *
 * E: Un string con el path del directorio
 * S: No tiene
 * D: Crea los QStringLIst del mundo
 *
 */

void World::preStart(QString path){
    this->names = FileManager::splitFile(FileManager::readFile(path+"/Nombres"));
    this->secondNames = FileManager::splitFile(FileManager::readFile(path+"/Apellidos"));
    this->countries = FileManager::splitFile(FileManager::readFile(path+"/Paises"));
    this->religions = FileManager::splitFile(FileManager::readFile(path+"/Creencias"));
    this->careers = FileManager::splitFile(FileManager::readFile(path+"/Profesiones"));
    this->peopleList = new Humans();
}

/*  ALGORTIMO DE NACIMIENTO PRIMARY
 * E: Un int
 * S: No tiene
 * D: De acuerdo con el numero recibido agrega la cantidad de humanos a la lista
 */

void World::birth(int quant){
    int i = 0;

    while(i <= quant){

        int id = getHumanID(0,999999);
        ids.append(id);
        //Captura los randoms de los txts
        QString name = StructCreator::getRand(names);
        QString secondN = StructCreator::getRand(secondNames);
        QString religion = StructCreator::getRand(religions);
        QString country = StructCreator::getRand(countries);
        QString career = StructCreator::getRand(careers);
        //Crea al nuevo humano
        Person *nuevo = StructCreator::createPerson(id,name,secondN,country,religion,career,nullptr);
        //nuevo->imprimir();
        //Lo pega a la lista
        peopleList->insertPos(nuevo);
        //Verifica si existe la familia
        ++i;

    }
    population = quant + population;
    //imprimirHumanos();
}

/* Seleccionar ID de humano
 * E: Dos ints
 * S: Un int
 * D: Verifica que el ID escogido no exista.
 */

int World::getHumanID(int min,int max){
    int id =  StructCreator::randomInit(min,max);
    if (!ids.contains(id))
        return id;
    else
        return getHumanID(min,max);
}

/* IMPRIMIR LISTA DE HUMANOS */
void World::imprimirHumanos(){
    int i = 0;
    NodeHuman *tmp = peopleList->first;
    while (tmp != nullptr){
        qDebug() << "";
        //qDebug() << "Humano Numero: " << i;
        tmp->person->imprimir();
        qDebug() << "";
        tmp = tmp->nxt;
        ++i;
    }
}

/* ABB CREATOR
 * E: Un integer
 * S: No tiene
 * D: Genera aleatoriamente el ABB para ubicar humanos en la lista de humanos
 */
void World::abbGenerator(){
    int i = getPowerTwo(population*0.01);
    while ( i != 0) {

    }
}


/* DETERMINA LA CANTIDAD DE NODOS DEL ARBOL
 * E: Un int
 * S: Un int
 * D: Se encarga de determinar la cantidad de nodos que debe tener el ABB a la hora de ser generado.
 */

int World::getPowerTwo(int n){
    int i = 0;
    while(i < n){
        if (qPow(2,i) > n)
            return i;
        else if(qPow(2,i) == n)
            return i;
        ++i;
    }
    return 0;
}
