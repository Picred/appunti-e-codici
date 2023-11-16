#include "serbatoio.h"
#include<string>
#include<iostream>

using namespace std;

Serbatoio::Serbatoio(string size) : carburanteContenuto(0) {
    // imposta una capienza a seconda della taglia del serbatoio
    if(size=="large")
        capienza=50;
    else if(size=="medium")
        capienza=35;
    else if(size=="small")
        capienza=25;
    else {
        capienza=-1;
        cerr << "Taglia serbatorio "<<size << " non riconosciuta"<<endl;
    }
}

double Serbatoio::getCapienza() {
    return capienza;
}

double Serbatoio::getCarburanteContenuto() {
    return carburanteContenuto;
}

void Serbatoio::inserisciCarburante(double carburante) {
    // se il carburante supera la capienza, riempi fino alla capienza massima
    if(carburanteContenuto + carburante > capienza) {
        carburanteContenuto = capienza;
    } else {
        carburanteContenuto += carburante;
    }
}

void Serbatoio::consuma(double litri) {
    // consuma un determinato numero di litri di carburante
    if(litri>carburanteContenuto) {
        // se non c'è abbastanza carburante, non fare nulla
        cerr << "Attenzione, il carburante non e' sufficiente, non ho consumato litri" << endl;
    } else {
        carburanteContenuto-=litri;
    }
}