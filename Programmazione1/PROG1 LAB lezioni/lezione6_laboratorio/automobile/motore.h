#ifndef MOTORE_H
#define MOTORE_H

#include<string>
#include "serbatoio.h"

using namespace std;

class Motore {
    private:
        string tipoMotore; //tipo del motore (benzina, diesel o ibrido)
        double litri_per_100km; //consumo in litri per 100km
        double chilometriPercorsi; //chilometri percorsi da questo motore
        void aggiornaConsumo(); //metodo privato che aggiorna il consumo sulla base del tipo di motore e dei km percorsi
    public:
        Motore(string); //costruttore
        void percorri(Serbatoio&, double); //percorre un certo numero di chilometri usando il carburante contenuto in un serbatoio
        double getChilometriPercorsi(); //restituisce il numero di chilometri percorsi
        double getLitriPer100Km(); //restituisce il consumo in litri per 100km
};
#endif