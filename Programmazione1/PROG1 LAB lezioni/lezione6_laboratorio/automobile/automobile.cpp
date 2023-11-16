#include "automobile.h"
#include<string>

using namespace std;

Automobile::Automobile(string tipo_motore, string taglia_serbatoio) : motore(tipo_motore), serbatoio(taglia_serbatoio) {}

void Automobile::rifornisci(double litri) {
    serbatoio.inserisciCarburante(litri);
}

void Automobile::percorri(double chilometri) {
    motore.percorri(serbatoio, chilometri);
}

double Automobile::autonomia() {
    //calcola l'autonomia della vettura
    double litri = serbatoio.getCarburanteContenuto();
    double litri_per_100km = motore.getLitriPer100Km();
    double km = litri/litri_per_100km*100;
    return km;
}

double Automobile::chilometri() {
    return motore.getChilometriPercorsi();
}