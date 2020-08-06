#include "person.h"

#include <QDebug>
/* Imprimir Datos
 *
 */

void Person::imprimir(){
    qDebug();
    qDebug() << "ID: " << this->id;
    qDebug() << "Nombre: " << this->name;
    qDebug() << "Apellido: " << this->secondName;
    qDebug() << "Carrera: " << this->career;
    qDebug() << "Creencia: " << this->beliefs;
    qDebug() << "Pais: " << this->country;


}

/*CAMBIAR ESTADO
 */
void Person::changeState(QString state){

    if (state == "SALVADO")
        this->state = SALVADO;
    else  if (state == "CONDENADO")
        this->state = CONDENADO;
    else  if (state == "VIVO")
        this->state = VIVO;
}

/* Verifica si tiene padre
    E: NO TIENE
    S: BOOL
    D: Verifica si tiene padre, si no tiene entonces retorna false.
*/

bool Person::hasFather(){
    if (this->father != nullptr)
        return true;
    else
        return false;
}
/* Set Father
 * E: Un puntero a persona
 * S: No tiene
 * D: Setea el el puntero padre a la persona(puntero) recibida
 */
void Person::setFather(Person *person){
    if (!this->hasFather()){
        this->father = person;
    }
}
/* Agregar hijo a la lista de hijos
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */
void Person::addSon(Person *newSon){
    newSon->setFather(this);
    this->sons->append(newSon);
}

/* Imprime hijos
 * E: Un puntero a persona
 * S: No tiene
 * D: Agrega un hijo en el array de hijos
 */
void Person::printHijos(){
    int i = 1;
    Node<Person> *tmp = sons->first;
    qDebug() << "";
    qDebug() << "------------LISTA DE HIJOS------------";
    while (tmp != nullptr) {
        qDebug() << "";
        qDebug() << "HIJO #" << i;
        tmp->data->imprimir();
        tmp = tmp->nxt;
        qDebug() << "";
        ++i;
    }
    qDebug() << "--------------------------------------";
}
//Imprime los pecados
void Person::printSins(){
    qDebug() << " ";
    qDebug() << "LISTA DE PECADOS";
    QString sins[7] = {"ORGULLO","ENVIDIA","IRA","PEREZA","CODICIA","GLOTONERIA","LUJURIA"};
    for (int i = 0; i<7 ; ++i){
        qDebug() << " ";
        qDebug() << sins[i] << ": " << this->sins[i];
    }
}
//Imprime los pecados
void Person::printActions(){
    qDebug() << " ";
    qDebug() << "LISTA DE BUENAS ACCIONES";
    QString goodActions[7] = {"HONRA","AYUDA","FELICIDAD","LABORIOSIDAD","GENEROSIDAD","SATISFACCION","HONESTIDAD"};
    for (int i = 0; i<7 ; ++i){
        qDebug() << " ";
        qDebug() << goodActions[i] << ": " << this->goodActions[i];
    }
}
/* Suma pecados
 * E: Dos ints
 * S: No tiene
 * D: Le suma un pecado al que se encuentre en el index recibido
 */
void Person::addSin(int sinIndex, int cantidad){
    this->sins[sinIndex] = this->sins[sinIndex] + cantidad;
}
/*Suma buenas acciones
 * E: Dos ints
 * S: No tiene
 * D: Le suma un pecado al que se encuentre en el index recibido
 */
void Person::addAction(int aIndex, int cantidad){
    this->goodActions[aIndex] = this->goodActions[aIndex] + cantidad;
}
/* Suma pecados a hijos
 * E: Un puntero a lista de hijos, DOS INTS
 * S: No tiene
 * D: Suma los nuevos pecados a los hijos de la persona
 */
void Person::addSinAUX(int sinIndex,int cant){
    int res = cant/2;
    Node<Person> *son = this->sons->first;
    while (son != nullptr){
        son->data->addSin(sinIndex,res);
        son->data->addNietos(sinIndex,res,false);
        son = son->nxt;
    }

}
/* Suma buenas acciones a hijos
 * E: Un puntero a lista de hijos, DOS INTS
 * S: No tiene
 * D: Suma buenas acciones a los hijos de la persona
 */
void Person::addGoodActionAUX(int aIndex, int cant){
    int res = cant/2;
    Node<Person> *son = this->sons->first;
    while (son != nullptr){
        son->data->addAction(aIndex,res);
        son->data->addNietos(aIndex,res,true);
        son = son->nxt;
    }

}
/* Suma pecado a los nietos
 * E: Dos ints, boolean
 * S: No tiene
 * D: Verifica que a que se le tiene que sumar
 */
void Person::addNietos(int index, int cant, bool type){
    Node<Person> *nieto = this->sons->first;
    int res = cant/2;
    if (type){
        while (nieto != nullptr){
            nieto->data->addAction(index,res);
            nieto = nieto->nxt;
        }
    }
    else if (!type){
        while (nieto != nullptr){
            nieto->data->addSin(index,res);
            nieto = nieto->nxt;
        }
    }
}

/*  VERIFY SON
 * E: Un puntero a persona
 * S: Un booleano
 * D: Checkea si la persona recibida esta en la lista de hijos
 */
bool Person::verifySon(Person *person){
    Node<Person> *tmp = this->sons->first;
    while( tmp != nullptr){
        if (tmp->data == person)
            return true;
        tmp = tmp->nxt;
    }
    return false;
}

//SI DA POSITVO ES BONDADOSO, NEGATIVO ES PECADOR
//-97 en IRA/CALMA ES PECADOR
int Person::totalSins(int sin){
    if (sin > 6)
        sin = 6;
    if (sin < 0)
        sin = 0;
    return this->goodActions[sin] - this->sins[sin];
}

int Person::totalSins(){
    int cont = 0;
    for (int i = 0; i < 7; i++)
        cont += this->totalSins(i);
    return cont;
}

QString Person::demonicBinnacle(int sinIndx){
    QString binnacle = "";
    binnacle.append(QDateTime::currentDateTime().toString("yyyy-MM-d h:m:s ap") + "\t");
    binnacle.append("Humano #" + QString::number(id) + "\t" + name + " " + secondName + " de " + country + "\n");
    binnacle.append("Murio el " + QDateTime::currentDateTime().toString("yyyy-MM-d"));
    binnacle.append(" condenado por cometer " + QString::number(sins[sinIndx]) + " pecados de ");
    switch(sinIndx){
    case 0:
        binnacle.append("Orgullo y " + QString::number(goodActions[sinIndx]) + " acciones de Humildad por el demonio Lucifer\n");
        break;
    case 1:
        binnacle.append("Envidia y " + QString::number(goodActions[sinIndx]) + " acciones de Solidaridad por el demonio Belcebu\n");
        break;
    case 2:
        binnacle.append("Ira y " + QString::number(goodActions[sinIndx]) + " acciones de Calma por el demonio Satan\n");
        break;
    case 3:
        binnacle.append("Pereza y " + QString::number(goodActions[sinIndx]) + " acciones de Diligencia por el demonio Abadon\n");
        break;
    case 4:
        binnacle.append("Codicia y " + QString::number(goodActions[sinIndx]) + " acciones de Donacion por el demonio Mammon\n");
        break;
    case 5:
        binnacle.append("Glotoneria y " + QString::number(goodActions[sinIndx]) + " acciones de Ayuno por el demonio Belfegor\n");
        break;
    case 6:
        binnacle.append("Lujuria y " + QString::number(goodActions[sinIndx]) + " acciones de Castidad por el demonio Asmodeo\n");
        break;
    default:
        break;
    }
    return binnacle;
}

QString Person::humanInfo(){
    QString info = "";

    //Info Personal
    info.append(showPersonalData());

    //Pecados
    info.append(showSins());

    //Buenas Acciones
    info.append(showGoodActions());

    //Hijos
    info.append(showSons());

    //FIN
    info.append("\n-----------------------------------------\n");
    return info;
}

QString Person::showSins(){
    QString info = "";

    info.append("~LISTA DE PECADOS~\n");
    QString sins[7] = {"ORGULLO: ","ENVIDIA: ","IRA: ","PEREZA: ","CODICIA: ","GLOTONERIA: ","LUJURIA: "};
    for (int i = 0; i < 7; i++)
        info.append(sins[i] + QString::number(this->sins[i]) + "\n");

    return info;
}

QString Person::showGoodActions(){
    QString info = "";

    info.append("~LISTA DE BUENAS ACCIONES~\n");
    QString goodActions[7] = {"HONRA: ","AYUDA: ","FELICIDAD: ","LABORIOSIDAD: ","GENEROSIDAD: ","SATISFACCION: ","HONESTIDAD: "};
    for (int i = 0; i < 7; i++)
        info.append(goodActions[i] + QString::number(this->goodActions[i]) + "\n");

    return info;
}

QString Person::showSons(){
    QString info = "";

    int i = 1;
    info.append("~LISTA DE HIJOS~\n");
    Node<Person> *ptr = this->sons->first;
    while (ptr != nullptr){
        info.append("Hijo #" + QString::number(i++));
        info.append("\t::\tID: " + QString::number(ptr->data->id) + "\n");
        ptr = ptr->nxt;
    }

    return info;
}

QString Person::showPersonalData(){
    QString info = "";

    info.append("ID: " + QString::number(this->id) + "\n");
    info.append("Nombre: " + this->name + "\n");
    info.append("Apellido: " + this->secondName + "\n");
    info.append("Carrera: " + this->career + "\n");
    info.append("Creencia: " + this->beliefs + "\n");
    info.append("Pais: " + this->country + "\n");

    //Estado (VIVO, CONDENADO, SALVADO)
    switch (this->state){
    case VIVO:
        info.append("Estado: VIVO \n");
        break;
    case CONDENADO:
        info.append("Estado: CONDENADO \n");
        break;
    case SALVADO:
        info.append("Estado: SALVADO \n");
        break;
    default:
        break;
    }

    return info;
}
