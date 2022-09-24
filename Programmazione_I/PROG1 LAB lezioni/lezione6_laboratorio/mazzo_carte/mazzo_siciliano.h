#ifndef MAZZO_SICILIANO_H
#define MAZZO_SICILIANO_H

#include "carta_siciliana.h"

#define N 40

class MazzoSiciliano {
    CartaSiciliana *carte[N];
    public:
        MazzoSiciliano();
        CartaSiciliana *pescaCarta();
        short contaCarte();
        void ricomponi();
};

#endif