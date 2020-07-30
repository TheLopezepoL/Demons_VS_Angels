#ifndef HASH_H
#define HASH_H
#include "dlinklist.h"
#include "soul.h"
#include "email.h"
#include "filemanager.h"

struct Hash{
    DLinkList<Soul>* savedHumans[1000];

    Hash();

    void append(Person* person, Angel* angel);
};

#endif // HASH_H
