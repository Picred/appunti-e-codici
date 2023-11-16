#include "motore.h"
#include "serbatoio.h"
#include<string>
#include<iostream>

using namespace std;
// inizializza gli attributi e aggiorna il consumo
Motore::Motore(string tipo) : tipoMotore(tipo), chilometriPercorsi(0) {
    aggiornaConsumo();
}

// aggiorna il consumo
void Motore::aggiornaConsumo() {
    // coefficiente di "invecchiamento"
    // è pari a 1 se il veicolo ha percorso meno di 500 km
    // dopo inizia a crescere linearmente
    double coef;
    if(chilometriPercorsi<500)
        coef = 1;
    else
        coef = chilometriPercorsi/500;

    if(tipoMotore=="benzina")
        litri_per_100km = coef*6.7; //moltiplico per coef in modo da aumetare i consumi per i motori più vecchi
    else if(tipoMotore=="diesel")
        litri_per_100km = coef*5.3;
    else if(tipoMotore=="ibrido")
        litri_per_100km = coef*4.2;
    else {
            cerr << "Attenzione, tipo motore "<<tipoMotore<<" non riconosciuto."<<endl;
            litri_per_100km = -1;
    }
}

// usa il motore per percorre i km
// aggiorna il numero di chilometri percorsi
// e il consumo
// restituisce il numero di litri consumati
void Motore::percorri(Serbatoio &s, double chilometri) {
    // dato che vogliamo modificare lo stato dell'istanza Serbatoio,
    // dobbiamo definirla come riferimento Serbatoio&
    double litri_necessari = litri_per_100km*chilometri/100;
    // se non ho abbastanza carburante
    if(s.getCarburanteContenuto()<litri_necessari)
        // messaggio di errore
        cerr << "Errore: non ho abbastanza carburante per percorrere "<<chilometri<<" chilometri!"<<endl;
    else {
        // consuma i litri necessari e aggiorna chilometri e consumo
        s.consuma(litri_necessari);
        chilometriPercorsi += chilometri;
        aggiornaConsumo();
    }
}

// restituisce il numero di chilometri percorsi
double Motore::getChilometriPercorsi() {
    return chilometriPercorsi;
}

double Motore::getLitriPer100Km() {
    return litri_per_100km;
}