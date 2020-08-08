#include "demon.h"
#include <QDebug>

void Demon::claimSinners(int quant){
    bool someoneAlive = true;
    Person* dummy = new Person();
    while(someoneAlive && quant > 0){
        NodeHuman* ptr = this->world->first;
        NodeHuman* maxSinner = new NodeHuman(dummy);
        while (ptr != nullptr){
            if(ptr->person->state == VIVO && ptr->person->totalSins(this->sinIndex) < maxSinner->person->totalSins(this->sinIndex))
                maxSinner = ptr;
            ptr = ptr->nxt;
        }
        if(maxSinner->person == dummy){
            someoneAlive = false;
            qDebug() << "Ya no quedan mas humanos para condenar.";
        }
        else {
            quant--;
            someoneAlive = true;
            maxSinner->person->state = CONDENADO;
            binnacle.append(maxSinner->person->demonicBinnacle(sinIndex));
            this->heap->append(maxSinner->person, this->sinIndex);
            this->quant++;
        }
    }
}

int Demon::average(){
    int x = 0;
    for (int i = 0; i < this->heap->len; i++)
        x += this->heap->array[i]->sins;
    x /= this->quant;
    return x;
}

Family* Demon::max(){
    Family* maxFam = new Family();
    for (int i = 0; i < this->heap->len; i++){
        if (this->heap->array[i]->sins > maxFam->sins)
            maxFam = this->heap->array[i];
    }
    return maxFam;
}

Family* Demon::min(){
    Family* minFam = new Family();
    for (int i = 0; i < this->heap->len; i++){
        if (this->heap->array[i]->sins < minFam->sins)
            minFam = this->heap->array[i];
    }
    return minFam;
}

void Demon::sendEmail(){
    QString root = "/home/thelopezepol/Escritorio/C++/ED S1 2020/Demons_VS_Angels/Condenados/";
    //QString root = "/home/rev/Documents/GitHub/Demons_VS_Angels/Condenados/";
    root.append("Condenacion_" + QDateTime::currentDateTime().toString("yyyyMMd_hms"));
    FileManager::writeFileN(binnacle, root);
    Email::sendEmail("Condenacion", binnacle);
}


