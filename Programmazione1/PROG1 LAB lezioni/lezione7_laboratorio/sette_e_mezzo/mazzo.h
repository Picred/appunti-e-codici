#ifndef MAZZO_H
#define MAZZO_H

#include "carta.h"

#define NUM_CARTE 40

class Mazzo {
    Carta **carte; //array di puntatori a Carta
    bool *carte_presenti; //array di booleani che indicano le carte presenti
    public:
        Mazzo(); //costruttore
        Carta* estrai(); //metodo per estrarre una carta
        int contaCarte(); //conta le carte
        void mescola(); //mescola il mazzo (lo ricompone)


};

#endif