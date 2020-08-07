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
    this->continents = FileManager::splitFile(FileManager::readFile(path+"/Continentes"));
    this->peopleList = new Humans();
    this->paises = new DLinkList<Counter>();
    this->paisesGA = new DLinkList<Counter>();
    this->heaven = new Heaven();
    countryList();
    Demon* newHell[7] = {new Demon("Lucifer", "Orgullo", 0, peopleList), new Demon("Belcebu", "Envidia", 1, peopleList), new Demon("Satan", "Ira", 2, peopleList), new Demon("Abadon", "Pereza", 3, peopleList), new Demon("Mammon", "Codicia", 4, peopleList), new Demon("Belfegor", "Gula", 5, peopleList), new Demon("Asmodeo", "Lujuria", 6, peopleList)};
    for (int i = 0; i < 7; i++)
        this->hell[i] = newHell[i];
}

/*  ALGORTIMO DE NACIMIENTO PRIMARY
 * E: Un int
 * S: No tiene
 * D: De acuerdo con el numero recibido agrega la cantidad de humanos a la lista
 */

void World::birth(int quant){
    int i = 0;
    this->tree = "";
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
    populationAlive = quant +populationAlive;
    population = quant + population;
    binnacle = binnacle +"\n"+ "Se han generado: "+ QString::number(quant) + " humanos!" + " Hay un total de "+ QString::number(population) + " humanos." ;
    //Actualiza el arbol
    abbGenerator();
    tree = tree + "ARBOL DE IDS:\n" + abb->binnacle();
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
    qDebug()<< "Cantida TOTAL PECADOS: " << counterSins;
    qDebug()<< "Cantida TOTAL BUENAS ACCIONES: " << counterGA;
}

/* ABB CREATOR
 * E: Un integer
 * S: No tiene
 * D: Genera aleatoriamente el ABB para ubicar humanos en la lista de humanos
 */
void World::abbGenerator(){
    ABB *nuevo = new ABB();
    int i = getPowerTwo(population*0.01)-3;
    qDebug() << i;
    NodeHuman *mid = peopleList->returnHuman(population/2);
    nuevo->insertar(mid);
    NodeHuman *first = peopleList->first;
    NodeHuman *last = peopleList->last;
    while ( i != 0) {
        int random = StructCreator::randomInit(1,population-2);

        nuevo->insertar(peopleList->returnHuman(random));
        --i;
    }
    nuevo->insertar(first);
    nuevo->insertar(last);
    this->abb = nuevo;
    tree = tree + "LA CANTIDAD DE NODOS ES: " + QString::number(nuevo->nodeCounter(nuevo->root)) + "\n";
}


/* DETERMINA LA CANTIDAD DE NODOS DEL ARBOL
 * E: Un int
 * S: Un int
 * D: Se encarga de determinar la cantidad de nodos que debe tener el ABB a la hora de ser generado.
 */

int World::getPowerTwo(int n){
    int i = 0;
    while(i < n){
        if (qPow(2,i) >= n)
            return qPow(2,i);
        i++;
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
    //qDebug() << i;
    NodeHuman *possibleSon = peopleList->first;

    while (i != 0) {
        if (possibleSon == nullptr)
            break;
        else{
            Person *son = possibleSon->person;
            if ( !son->hasFather() and !son->verifySon(person) and(son->secondName == person->secondName) and (son->country == person->country) and (son->id != person->id)) {
                person->addSon(son);
                --i;
            }
            possibleSon = possibleSon->nxt;
        }
    }

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
            cantidadCadaPecado[i] = cantidadCadaPecado[i] + random;
            counterSins = counterSins + random;
            tmp->person->addSin(i,random);
            tmp->person->addSinAUX(i,random);
            this->addCountrySins(random,tmp->person->country);
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
            cantidadCadaBuenaAccion[i] = cantidadCadaBuenaAccion[i] + random;
            counterGA = counterGA + random;
            tmp->person->addAction(i,random);
            this->addCountryGA(random,tmp->person->country);
        }
        tmp = tmp->nxt;
    }
}

/* SUMA A LOS PAISES LAS BUENAS ACCIONES
 * E: Un int (id)
 * S: No tiene
 * D: Recibe un id y despliega toda la info de los pecados de toda la familia del id.
 */
void World::addCountryGA(int cant, QString name){
    Node<Counter> *tmp = paisesGA->first;
    while (tmp != nullptr){
        if (tmp->data->name == name){
            tmp->data->cant = tmp->data->cant + cant;
        }
        tmp = tmp->nxt;
    }
}

/* Crea lista de Continentes
 * E: No tiene
 * S: No tiene
 * D: Crea la lista de paises con el continente asignado
 */

void World::countryList(){
    int counter = 0;
    for (int i = 0 ; i < 5 ; ++i){
        for (int j = counter ; j < counter+5 ; ++j){
            //qDebug () << countries[j] << continents[i];
            Counter *nuevo = new Counter(countries[j],continents[i],0);
            Counter *nuevoGA = new Counter(countries[j],continents[i],0);
            paises->append(nuevo);
            paisesGA->append(nuevoGA);
        }
        counter = counter + 5;
    }

}

//IMPRIME LISTA DE PAISES
void World::printCountryListSins(){

    Node<Counter> *tmp = paises->first;

    while (tmp != nullptr){
        qDebug() << "";
        qDebug() << "Pais: " << tmp->data->name;
        qDebug() << "Continente: " << tmp->data->continent;
        qDebug() << "Cantidad Pecadores: " << tmp->data->cant;
        tmp = tmp->nxt;


    }
}

void World::printCountryListGA(){

    Node<Counter> *tmp = paisesGA->first;

    while (tmp != nullptr){
        qDebug() << "";
        qDebug() << "Pais: " << tmp->data->name;
        qDebug() << "Continente: " << tmp->data->continent;
        qDebug() << "Cantidad Buenas Acciones: " << tmp->data->cant;
        tmp = tmp->nxt;


    }
}

/* SORT DE LISTA DE PAISES
 * E: Un puntero a nodo de pais
 * S: No tiene
 * D: Hace el cambio del nodo en la lista
 */
//PECADOS
void World::sortListSins(){
    Node<Counter> *current = nullptr;
    Node<Counter> *index = nullptr;
    Counter *tmp;

    if (paises->first == nullptr)
        return;
    for (current = paises->first ; current->nxt != nullptr ; current = current->nxt){
        for (index = current->nxt ; index != nullptr ; index = index->nxt){
            if (current->data->cant > index->data->cant){
                tmp = current->data;
                current->data = index->data;
                index->data = tmp;
            }
        }
    }

}
//BUENAS ACCIONES
void World::sortListGoodActions(){
    Node<Counter> *current = nullptr;
    Node<Counter> *index = nullptr;
    Counter *tmp;

    if (paisesGA->first == nullptr)
        return;
    for (current = paisesGA->first ; current->nxt != nullptr ; current = current->nxt){
        for (index = current->nxt ; index != nullptr ; index = index->nxt){
            if (current->data->cant > index->data->cant){
                tmp = current->data;
                current->data = index->data;
                index->data = tmp;
            }
        }
    }
}
/* SUMA LOS PECADOS A CADA PAIS
 * E: Dos strings
 * S: No tiene
 * D: Agrega los pecados a los paises de la lista de cada pais
 */
void World::addCountrySins(int cant ,QString name){
    Node<Counter> *tmp = paises->first;

    while (tmp != nullptr){
        if (tmp->data->name == name){
            tmp->data->cant = tmp->data->cant + cant;
        }
        tmp = tmp->nxt;
    }
}

/* GET TOP 10 DE PAISES MAS PECADORES
 * E: No tiene
 * S: Un array con el top 10 de paises
 * D: Retorna el top 10 de los paises mas pecadores
 */
DLinkList<Counter> *World::top10Sins(){
    DLinkList<Counter> *array = new DLinkList<Counter>();
    Node<Counter> *tmp = paises->last;
    int i = 0;
    while( tmp != nullptr){
        if (i < 10){
            array->append(tmp->data);
        }
        tmp = tmp->prv;
        ++i;
    }
    //printTops(array);
    return array;
}

/* GET TOP 10 DE PAISES CON MAS BUENAS ACCIONES
 * E: No tiene
 * S: Un array con el top 10 de paises
 * D: Retorna el top 10 de los paises mas BUENAS ACCIONES
 */
DLinkList<Counter> *World::top10GA(){
    DLinkList<Counter> *array = new DLinkList<Counter>();
    Node<Counter> *tmp = paisesGA->last;
    int i = 0;
    while( tmp != nullptr){
        if (i < 10){
            array->append(tmp->data);
        }
        tmp = tmp->prv;
        ++i;
    }
    //printTops(array);
    return array;
}
/* GET TOP 5 DE PAISES MENOS PECADORES
 * E: No tiene
 * S: Un array con el top 5 de paises
 * D: Retorna el top 5 de los paises MENOS pecadores
 */

DLinkList<Counter> *World::top5LessSins(){
    DLinkList<Counter> *array = new DLinkList<Counter>();
    Node<Counter> *tmp = paises->first;
    int i = 0;
    while( tmp != nullptr){
        if (i < 5){
            array->append(tmp->data);
        }
        tmp = tmp->nxt;
        ++i;
    }
    printTops(array);
    return array;
}
/* GET TOP 5 DE PAISES MENOS BUENAS ACCIONES
 * E: No tiene
 * S: Un array con el top 5 de paises
 * D: Retorna el top 5 de los paises MENOS pecadores
 */

DLinkList<Counter> *World::top5LessGA(){
    DLinkList<Counter> *array = new DLinkList<Counter>();
    Node<Counter> *tmp = paisesGA->first;
    int i = 0;
    while( tmp != nullptr){
        if (i < 5){
            array->append(tmp->data);
        }
        tmp = tmp->nxt;
        ++i;
    }
    printTops(array);
    return array;
}
//IMPRIMIR TOPS
QString World::printTops(DLinkList<Counter> *top){
    QString msg = "\n";
    Node<Counter> *tmp = top->first;
    int i = 1;
    while (tmp != nullptr){
        msg = msg + "\n" + "#" + QString::number(i) + "\n" + "Pais: " + tmp->data->name + "\n" + "Continente: " + tmp->data->continent + "\n" + "Cantidad: " +QString::number(tmp->data->cant);
        tmp = tmp->nxt;
        ++i;
    }
    return msg;
}

/* GET MAPA LIST
 * E: No tiene
 * S: No tiene
 * D: Devuelve una lista con los nombres de las imagenes de los continentes
 */

QStringList World::getMapa(bool key){
    if (key == true){
        int percentaje = counterSins * 0.2;
        QStringList images;
        for (int i = 0 ; i < 5 ; ++i){
            int cant = getCantContinent(continents[i]);
            cantPecadosCont = cantPecadosCont + "El continente " + continents[i] + " tiene un total de " + QString::number(cant) + " pecados." + "\n";
            if (cant >= percentaje)
                images.append(continents[i] + "1.png");
            else if (cant < percentaje) {
                images.append(continents[i] + "0.png");
            }
        }
        cantPecadosCont = cantPecadosCont + "En el mundo hay un total de: " + QString::number(counterSins) + " pecados.";
        return images;
    }
    else {
        int percentaje = counterGA * 0.2;
        QStringList images;
        for (int i = 0 ; i < 5 ; ++i){
            int cant = getCantContinent(continents[i]);
            cantGA = cantGA + "El continente " + continents[i] + " tiene un total de " + QString::number(cant) + " buenas acciones." + "\n";
            if (cant >= percentaje)
                images.append(continents[i] + "1.png");
            else if (cant < percentaje) {
                images.append(continents[i] + "0.png");
            }
        }

        cantGA = cantGA + "En el mundo hay un total de: " + QString::number(counterGA)+ " buenas acciones.";;
        return images;
    }

}


//CANTIDAD DE PECADOS EN EL CONTINENTE
int World::getCantContinent(QString continent){
    int i = 0;
    Node<Counter> *tmp = paises->first;
    while (tmp != nullptr) {
        if (tmp->data->continent == continent)
            i = i + tmp->data->cant;
        tmp = tmp->nxt;
    }
    return i;

}
int World::quantDeadHumans(){
    int total = 0;
    for (int i = 0; i < 6; i++)
        total += hell[i]->quant;
    return total;
}

QString World::selectDemon(int x){
    QString info = "";
    info.append("Demonio: " + hell[x]->name + "\tPecado:" + hell[x]->sin);
    return info;

}

QString World::cantidadPecadosQString(){
    QString msg = "\nPECADOS-----------------------------------------------";
    for (int i = 0 ; i < 7 ; ++i){
        msg = msg + "\n" + "El pecado " + hell[i]->sin + " tiene un total de " + QString::number(cantidadCadaPecado[i]);
    }
    return msg;
}

QString World::cantidadBuenasAccionesQS(){
    QString msg = "\nBUENAS ACCIONES-----------------------------------------------";
    for (int i = 0 ; i < 7 ; ++i){
        msg = msg + "\n" + "La buena accion " + goodActions[i] + " tiene un total de " + QString::number(cantidadCadaBuenaAccion[i]);
    }
    return msg;
}

QString World::setWinner(){
    int neto = 0;
    QString msg = "NETOS------------------------------------------------";
    for (int i = 0 ; i < 7 ; ++i){
        neto = neto + (cantidadCadaBuenaAccion[i] - cantidadCadaPecado[i]);
        msg = msg + "\n" + "La buena accion " + goodActions[i] + " y el pecado " + hell[i]->sin + " tienen un neto de: " +  QString::number(cantidadCadaBuenaAccion[i] - cantidadCadaPecado[i]);
    }
    msg = msg + cantidadPecadosQString() + cantidadBuenasAccionesQS();
    if (neto >= 0){
        msg = msg + "\n---------------------EL CIELO HA GANADO!---------------------";
        return msg;
    }
    else if (neto < 0) {
        msg = msg + "\n---------------------EL INFIERNO HA GANADO!---------------------";
        return msg;
    }
    return msg;
}

Person* World::searchHuman(int id){ return searchHuman(id, this->abb->root); }

Person* World::searchHuman(int id, NodeABB *node){
    if (node->person->person->id == id)
        return node->person->person;
    else if (node->person->person->id > id){
        if (node->leftSon != nullptr)
            return searchHuman(id, node->leftSon);
        else
            return searchHuman(id, node->person);
    }
    else {
        if (node->rightSon != nullptr)
            return searchHuman(id, node->rightSon);
        else
            return searchHuman(id, node->person);
    }
}

Person* World::searchHuman(int id, NodeHuman *ptr){
    bool direction = ptr->person->id < id; // Si va hacia la derecha = true : izquierda = false
    while (ptr != nullptr){
        if (ptr->person->id == id)
            return ptr->person;
        if (direction){
            if (ptr->person->id > id)
                return nullptr; // No existe el id
            ptr = ptr->nxt; // Sigue buscando
        }
        else { // Mismo proceso por si tiene que ir para atras
            if (ptr->person->id > id)
                return nullptr;
            ptr = ptr->prv;
        }
    }
    return nullptr;
}

DLinkList<Person>* World::getFamily(int id){
    Person* human = searchHuman(id);
    human->printHijos();
    DLinkList<Person>* family = new DLinkList<Person>();
    if (human != nullptr) {
        family->append(human);
        Node<Person>* ptr = family->first;
        while(ptr !=  nullptr){
            Node<Person>* son = ptr->data->sons->first;
            while(son !=  nullptr){
                family->append(son->data);
                son = son->nxt;
            }
            ptr = ptr->nxt;
        }
    }
    else
        qDebug() << "No se encontro al humano.";
    return family;
}

QString World::familySins(int id){
    DLinkList<Person>* family = getFamily(id);
    QString text = "";
    Node<Person>* ptr = family->first;
    while (ptr != nullptr){
        text.append(ptr->data->showPersonalData());
        text.append(ptr->data->showSins());
        text.append("\n----------------------------------------------\n");
        ptr = ptr->nxt;
    }
    return text;
}


QString World::familyGoodActions(int id){
    DLinkList<Person>* family = getFamily(id);
    QString text = "";
    Node<Person>* ptr = family->first;
    while (ptr != nullptr){
        text.append(ptr->data->showPersonalData());
        text.append(ptr->data->showGoodActions());
        text.append("\n----------------------------------------------\n");
        ptr = ptr->nxt;
    }
    return text;
}

QString World::hellPrint(){

    QString msg = "----------------------------------------------INFIERNO----------------------------------------------\n";
    for (int i = 0 ; i < 7 ; ++i){
        msg =  msg + showHell(i);
    }
    return msg;
}


QString World::showHell(int demonIdx){
    Demon* demon = this->hell[demonIdx];
    if (demon != nullptr){
        QString text = "Infierno de " + demon->name + "\n";
        text.append("Reino de la " + demon->sin + "\n");
        text.append("Humanos castigados: " + QString::number(demon->quant) + "\n");
        for (int i = 0; i < 10000; i++){
            if (demon->heap->array[i] != nullptr)
                text.append(demon->heap->array[i]->stringFamily());
            else
                break;
        }
        return text;
    }
    return "";
}

QString World::showHeaven(){
    Hash* hash = this->heaven->souls;
    if (hash != nullptr){
        QString text = "~~~Cielo~~~\n";
        for (int i = 0; i < 1000; i++){
            Node<Soul>* ptr = hash->savedHumans[i]->first;
            while (ptr != nullptr){
                text.append("\nANGEL :" + ptr->data->angel->name + " "+ QString::number(ptr->data->angel->version) + "\n");
                text.append("Humano :\n" + ptr->data->human->showPersonalData());
                ptr = ptr->nxt;
            }
        }
        return text;
    }
    return "";
}

QString World::searchFamily(QString secondName, QString country){
    NodeHuman* ptr = this->peopleList->first;
    int alive = 0;
    int dead = 0;
    int saved = 0;
    Humans* humans = new Humans();

    //Guardar todos los humanos con mismo pais y apellido
    while (ptr != nullptr){
        if (ptr->person->secondName == secondName && ptr->person->country == country){
            humans->insertBySins(ptr->person);
            switch(ptr->person->state){
            case VIVO:
                alive++;
                break;
            case CONDENADO:
                dead++;
                break;
            case SALVADO:
                saved++;
                break;
            default:
                break;
            }
        }
        ptr = ptr->nxt;
    }

    //Mostrar porcentajes
    QString text = "Humanos " + secondName + " de " + country + "\n";
    text.append("*PORCENTAJES*\n");
    text.append("COINCIDENCIAS ENCONTRADAS: " + QString::number(alive+dead+saved) + "\n");
    text.append("VIVOS: " + QString::number((alive*100)/(alive+dead+saved)) + "%\n");
    text.append("CONDENADOS: " + QString::number((dead*100)/(alive+dead+saved)) + "%\n");
    text.append("SALVADOS: " + QString::number((saved*100)/(alive+dead+saved)) + "%\n");
    text.append("\n*HUMANOS*\n");

    //Recorrer la lista imprimiendo los humanos seleccionados
    ptr = humans->first;
    while (ptr != nullptr){
        text.append(ptr->person->humanInfo());
        ptr = ptr->nxt;
    }

    return text;
}

void World::printAllHumansInfo(bool sins){
    QString text = "";
    QString grupos[4] = {"APELLIDOS", "PAISES", "CREENCIAS", "PROFESIONES"};
    for (int i = 0; i < 4; i++){
        text.append("\n~ ~ ~ " + grupos[i] + " ~ ~ ~\n");
        text.append(printAllHumansInfo(i, sins));
    }
    if (sins)
        FileManager::writeFileN(text, "/home/rev/Documents/GitHub/Demons_VS_Angels/allInfoSins.txt");
    else if (!sins) {
        FileManager::writeFileN(text, "/home/rev/Documents/GitHub/Demons_VS_Angels/allInfoGoodActions.txt");
    }
    //"/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels/allInfo.txt"
}

QString World::printAllHumansInfo(int category, bool sins){
    QString text = "";
    QStringList list;
    switch (category) {
    case 0:
        list = this->secondNames;
        break;
    case 1:
        list = this->countries;
        break;
    case 2:
        list = this->religions;
        break;
    case 3:
        list = this->careers;
        break;
    default:
        break;
    }
    for (int i = 0; i < list.size(); i++){
        if (sins)
            text.append(printAllHumansInfoSins(category, list[i]));
        else
            text.append(printAllHumansInfoGoodActions(category, list[i]));
    }
    return text;
}

QString World::printAllHumansInfoSins(int category, QString data){
    QString text = "";
    int cantHumans = 0;
    int cantSins = 0;
    int totalSins = cantidadCadaPecado[0] + cantidadCadaPecado[1] + cantidadCadaPecado[2] + cantidadCadaPecado[3] + cantidadCadaPecado[4] + cantidadCadaPecado[5] + cantidadCadaPecado[6];
    NodeHuman* ptr = this->peopleList->first;
    Humans* chosen = new Humans();

    //Elegir los que cumplen la condicion
    while (ptr != nullptr){
        switch (category) {
        case 0:
            if (ptr->person->secondName == data){
                chosen->insertBySins(ptr->person);
                cantHumans++;
                cantSins += ptr->person->sins[0] + ptr->person->sins[1] + ptr->person->sins[2] + ptr->person->sins[3] + ptr->person->sins[4] + ptr->person->sins[5] + ptr->person->sins[6];
            }
            break;
        case 1:
            if (ptr->person->country == data){
                chosen->insertBySins(ptr->person);
                cantHumans++;
                cantSins += ptr->person->sins[0] + ptr->person->sins[1] + ptr->person->sins[2] + ptr->person->sins[3] + ptr->person->sins[4] + ptr->person->sins[5] + ptr->person->sins[6];
            }
            break;
        case 2:
            if (ptr->person->beliefs == data){
                chosen->insertBySins(ptr->person);
                cantHumans++;
                cantSins += ptr->person->sins[0] + ptr->person->sins[1] + ptr->person->sins[2] + ptr->person->sins[3] + ptr->person->sins[4] + ptr->person->sins[5] + ptr->person->sins[6];
            }
            break;
        case 3:
            if (ptr->person->career == data){
                chosen->insertBySins(ptr->person);
                cantHumans++;
                cantSins += ptr->person->sins[0] + ptr->person->sins[1] + ptr->person->sins[2] + ptr->person->sins[3] + ptr->person->sins[4] + ptr->person->sins[5] + ptr->person->sins[6];
            }
            break;
        }
        ptr = ptr->nxt;
    }

    //Mostrar Lista
    text.append("\n*" + data + "*\n");
    text.append("Humanos: " + QString::number((cantHumans*100)/this->population) + "%\n");
    text.append("Pecados: " + QString::number((cantSins*100)/totalSins) + "%\n\n");

    ptr = chosen->first;
    while (ptr != nullptr){
        text.append("ID: " + QString::number(ptr->person->id) + "\t Pecados: " + QString::number(ptr->person->totalSins()) + "\n");
        ptr = ptr->nxt;
    }

    return text;
}


QString World::printAllHumansInfoGoodActions(int category, QString data){
    QString text = "";
    int cantHumans = 0;
    int contGA = 0;
    int totalGA = cantidadCadaBuenaAccion[0] + cantidadCadaBuenaAccion[1] + cantidadCadaBuenaAccion[2] + cantidadCadaBuenaAccion[3] + cantidadCadaBuenaAccion[4] + cantidadCadaBuenaAccion[5] + cantidadCadaBuenaAccion[6];
    NodeHuman* ptr = this->peopleList->first;
    Humans* chosen = new Humans();

    //Elegir los que cumplen la condicion
    while (ptr != nullptr){
        switch (category) {
        case 0:
            if (ptr->person->secondName == data){
                chosen->insertByGA(ptr->person);
                cantHumans++;
                contGA += ptr->person->goodActions[0] + ptr->person->goodActions[1] + ptr->person->goodActions[2] + ptr->person->goodActions[3] + ptr->person->goodActions[4] + ptr->person->goodActions[5] + ptr->person->goodActions[6];
            }
            break;
        case 1:
            if (ptr->person->country == data){
                chosen->insertByGA(ptr->person);
                cantHumans++;
                contGA += ptr->person->goodActions[0] + ptr->person->goodActions[1] + ptr->person->goodActions[2] + ptr->person->goodActions[3] + ptr->person->goodActions[4] + ptr->person->goodActions[5] + ptr->person->goodActions[6];
            }
            break;
        case 2:
            if (ptr->person->beliefs == data){
                chosen->insertByGA(ptr->person);
                cantHumans++;
                contGA += ptr->person->goodActions[0] + ptr->person->goodActions[1] + ptr->person->goodActions[2] + ptr->person->goodActions[3] + ptr->person->goodActions[4] + ptr->person->goodActions[5] + ptr->person->goodActions[6];
            }
            break;
        case 3:
            if (ptr->person->career == data){
                chosen->insertByGA(ptr->person);
                cantHumans++;
                contGA += ptr->person->goodActions[0] + ptr->person->goodActions[1] + ptr->person->goodActions[2] + ptr->person->goodActions[3] + ptr->person->goodActions[4] + ptr->person->goodActions[5] + ptr->person->goodActions[6];
            }
            break;
        }
        ptr = ptr->nxt;
    }

    //Mostrar Lista
    text.append("\n*" + data + "*\n");
    text.append("Humanos: " + QString::number((cantHumans*100)/this->population) + "%\n");
    text.append("Buenas Acciones: " + QString::number((contGA*100)/totalGA) + "%\n\n");

    ptr = chosen->first;
    while (ptr != nullptr){
        text.append("ID: " + QString::number(ptr->person->id) + "\t Buenas Acciones: " + QString::number(ptr->person->totalSins()) + "\n");
        ptr = ptr->nxt;
    }

    return text;
}












//Claim sinners
void World::claimSinners(){
    int cantidad = populationAlive*0.05;
    for (int i = 0 ; i < 7 ; ++i){
        hell[i]->claimSinners(cantidad);
        hell[i]->sendEmail();
        populationAlive = populationAlive-cantidad;
    }

}
