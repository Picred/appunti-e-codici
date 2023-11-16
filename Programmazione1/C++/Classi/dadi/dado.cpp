#include "dado.h"
#include<ctime>

Dado::Dado() : valore(rand()%6+1){} //il dado, appena inizializzato, ha un valore random

short Dado::getValore(){return valore;}

void Dado::lanciaDado(){
    valore= rand()%6+1;
}