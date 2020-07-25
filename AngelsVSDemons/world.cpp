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

void World::preStart(QString path/*,Humans peopleList, Heaven *heaven, Hell *hell*/){
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
        Person *nuevo = StructCreator::createPerson(id,name,secondN,country,religion,career);
        //nuevo->imprimir();
        //Lo pega a la lista
        peopleList->insertPos(nuevo);
        //Verifica si existe la familia
        ++i;

    }
    //Agrega hijos
    setSons();
    population = quant + population;
    //Actualiza el arbol
    abbGenerator();
    //Imprime Humanos
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
        tmp->person->printHijos();
        tmp->person->printSins();
        tmp->person->printActions();
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
    ABB *nuevo = new ABB();
    int i = getPowerTwo(population*0.01);
    Person *mid = peopleList->returnHuman(population/2);
    nuevo->insertar(mid);
    //mid->imprimir();
    while ( i != 0) {
        //qDebug() << i;
        int random = StructCreator::randomInit(0,population-1);
        nuevo->insertar(peopleList->returnHuman(random));
        --i;
    }
    this->abb = nuevo;
    //abb->posOrden(abb->root,0);
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
            return qPow(2,i);
        else if(qPow(2,i) == n)
            return qPow(2,i);
        ++i;
    }
    return 0;
}


/* Set Sons AUXILIAR
 * E: Un puntero a persona
 * S: No tiene
 * D: Setea la cantidad de hijos de la persona y se los setea
 */

void World::setSonsAux(Person *person){
    int i = StructCreator::randomInit(0,5);
    NodeHuman *possibleSon = peopleList->first;
    while (i != 0) {
        Person *son = possibleSon->person;
        if (possibleSon == nullptr)
            break;
        else if (!son->hasFather() and (son->secondName == person->secondName) and (son->country == person->country) and (son->id != person->id)) {
            person->addSon(son);
        }

        --i;
        possibleSon = possibleSon->nxt;

    }
    //person->imprimir();
    //person->printHijos();
}

/* SET SONS
 * E: No tiene
 * S: No tiene
 * D: Hace un ciclo para asignar un hijo a la lista de hijos
 */

void World::setSons(){
    NodeHuman *tmp = peopleList->first;
    while (tmp != nullptr) {
        //tmp->person->imprimir();
        if (tmp->person->sons->isEmpty()){
            setSonsAux(tmp->person);
        }
        tmp = tmp->nxt;
    }
}

/* SUMA DE PECADOS
 * E: No tiene
 * S: No tiene
 * D: Le suma un random de pecados a cada humano
 */
void World::sinGenerator(){
    NodeHuman *tmp = peopleList->first;
    while (tmp != nullptr){
        for (int i = 0; i<7 ; ++i){
            int random = StructCreator::randomInit(0,100);
            tmp->person->addSin(i,random);
            tmp->person->addSinAUX(i,random);
        }
        tmp = tmp->nxt;
    }
}
/*SUMA DE BUENAS ACCIONES
 * E: No tiene
 * S: No tiene
 * D: Le suma un random de nuevas acciones a cada humano
 */
void World::blessGenerator(){
    NodeHuman *tmp = peopleList->first;
    while(tmp != nullptr){
        for (int i = 0; i<7 ; ++i){
            int random = StructCreator::randomInit(0,100);
            tmp->person->addAction(i,random);
            tmp->person->addGoodActionAUX(i,random);
        }
        tmp = tmp->nxt;
    }
}
