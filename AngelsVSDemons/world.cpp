#include "world.h"
#include <QRandomGenerator>
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
    this->peopleList = new DLinkList<Person>();
}

/*  ALGORTIMO DE NACIMIENTO PRIMARY
 * E: Un int
 * S: No tiene
 * D: De acuerdo con el numero recibido agrega la cantidad de humanos a la lista
 */

void World::birth(int quant){
    int i = 0;

    while(i <= quant){

        //Captura los randoms de los txts
        QString name = StructCreator::getRand(names);
        QString secondN = StructCreator::getRand(secondNames);
        QString religion = StructCreator::getRand(religions);
        QString country = StructCreator::getRand(countries);
        QString career = StructCreator::getRand(careers);
        //Crea al nuevo humano
        Person *nuevo = StructCreator::createPerson(population+i,name,secondN,country,religion,career,nullptr);
        //nuevo->imprimir();
        //Lo pega a la lista
        peopleList->append(nuevo);
        //Verifica si existe la familia

        ++i;
    }
    population = quant + population;
}

/* Verifica si existen los apellidos de una persona en determinado pais
 * E: Dos strings
 * S: Un nodo al heap del arbol
 * D: Busca una familia en la lista de heaps. Si retorna nulo es que no existe la familia en ese pais.
 */

Node<HeapPerson>* World::verifyFamilyExistance(QString name,QString country){
    Node<HeapPerson> *tmp = families->first;

    while(tmp != nullptr){
        if (name == tmp->data->lastName and country == tmp->data->country)
            return tmp;
        else
            tmp = tmp->nxt;
    }

    return nullptr;
}
/* Retorna la cantidad de personas en el mundo
 * E: No tiene
 * S: Un int
 * D: Devuelve la cantidad de personas que tiene el mundo
 */

int World::getPopulation(){
    return population;
}
