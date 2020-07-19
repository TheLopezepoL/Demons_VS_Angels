#include "world.h"

/* ALISTADOR DE ARRAYS
 *
 * E:
 * S:
 * D:
 *
 */

void World::preStart(QString path){
    this->names = FileManager::splitFile(FileManager::readFile(path+"/Nombres"));
    this->secondNames = FileManager::splitFile(FileManager::readFile(path+"/Apellidos"));
    this->countries = FileManager::splitFile(FileManager::readFile(path+"/Paises"));
    this->religions = FileManager::splitFile(FileManager::readFile(path+"/Creencias"));
}
