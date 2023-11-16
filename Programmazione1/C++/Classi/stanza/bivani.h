#ifndef BIVANI_H
#define BIVANI_H

#include "stanza.h"
#include "bagno.h"

class Bivani{
    private:
        Stanza s1;
        Stanza s2;
        Bagno b1;
    public:
        Bivani() : s1("Camera da letto", 10,20), s2("Cucina", 20,30),b1(50,50){}
};

#endif