#include "mazzo_siciliano.h"
#include<cstdlib>
#include<ctime>
using namespace std;

MazzoSiciliano::MazzoSiciliano() {
    //imposta il seed
    srand(time(0));
    int i=0;
    for(int seme=11; seme<=14; seme++) {
        for (int figura=1; figura<=10; figura++) {
            carte[i++] = new CartaSiciliana(figura, seme); //costruisce le carte
        }
    }
}

CartaSiciliana* MazzoSiciliano::pescaCarta() {
    //pesca una carta a caso tra quelle non pescate
    if(contaCarte()==0) //se non ci sono più carte
        return nullptr; //restituisci puntatore a null
    CartaSiciliana *p = nullptr;
    short idx;
    do {
        idx = rand()%N; //genera un numero tra 0 e N-1
        p=carte[idx]; //ottieni il riferimento alla carta
    } while(p==nullptr); //continua finché la carta estratta non esiste
    carte[idx] = nullptr; //segna la carta come pescata
    return p;
}

short MazzoSiciliano::contaCarte() {
    short num = 0; //conta le carte
    for(int i=0; i<N; i++) //scorri le carte
        if(carte[i]) //conta i puntatori non null
            num++;
    return num;
}