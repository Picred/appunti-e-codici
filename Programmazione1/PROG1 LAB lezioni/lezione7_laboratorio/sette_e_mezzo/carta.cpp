#include "carta.h"

#include<iostream>
using namespace std;

short Carta::getValore() const {
    return valore;
}

string Carta::getSeme() const {
    return seme;
}

void Carta::print() const {
    cout << valore << " di " << seme;
}

double Carta::getPunteggio() const { //calcola il punteggio della carta nel gioco
    if(valore<=7){
        return valore;
    } else {
        return 0.5;
    }
}