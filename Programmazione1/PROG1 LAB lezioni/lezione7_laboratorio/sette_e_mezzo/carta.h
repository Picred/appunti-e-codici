#ifndef CARTA_H
#define CARTA_H

#include<string>
using namespace std;

class Carta {
    short valore; //il valore della carta
    string seme; //il seme della carta

    public:
        Carta(short v, string s) : valore(v), seme(s) {} //costruttore
        short getValore() const; //getter
        string getSeme() const; //getter
        void print() const; //stampa il valore della carta
        double getPunteggio() const; //calcola il punteggio nel gioco
};

#endif