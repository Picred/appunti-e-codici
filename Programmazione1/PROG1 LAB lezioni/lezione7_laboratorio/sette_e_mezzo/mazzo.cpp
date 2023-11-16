#include "mazzo.h"
#include<cstdlib>
#include<ctime>

Mazzo::Mazzo() {
    carte = new Carta*[NUM_CARTE];
    carte_presenti = new bool[NUM_CARTE];
    string semi[] = {"Bastoni", "Spade", "Coppe", "Oro"};
    int count = 0;
    for(int s=0; s<4; s++) { //inizializza l'array di carte
        for(short v=1; v<=10; v++) {
            carte[count] = new Carta(v, semi[s]);
            carte_presenti[count] = true; //tutte le carte sono presenti all'inizio
            count++;
        }
    }
}

int Mazzo::contaCarte() { //conta le carte
    int sum = 0;
    for(int i=0; i< NUM_CARTE; i++) {
        if(carte_presenti[i])
            sum++;
    }
    return sum;
}

void Mazzo::mescola() {
    // mescolare il mazzo significa semplicemente rendere tutte le carte disponibili
    for(int i=0; i< NUM_CARTE; i++)
        carte_presenti[i] = true;
}

Carta* Mazzo::estrai() { //estrae una carta non estratta
    if(contaCarte()>0) {
        srand(time(0));
        int idx;
        do{
            idx = rand()%NUM_CARTE;
        } while(!carte_presenti[idx]);

        carte_presenti[idx] = false;
        return carte[idx];
    } else { //se non ci sono più carte, restituisci nullptr
        return nullptr;
    }
}