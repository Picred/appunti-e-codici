/*
(Esercizio adattato dal libro “JAVA: Fondamenti di progettazione 
Software - Prima Edizione Italiana”. Addison-Wesley)

Progettare e implementare una classe Carta che rappresenti una carta da gioco. 
Ogni carta deve avere un seme e un valore. Definire dunque una classe Mazzo 
che rappresenti un mazzo di 40 carte. Il mazzo deve permettere di estrarre 
casualmente una carta, contare il numero di carte rimanenti e rimescolare le carte. 
Scrivere un programma che permetta di giocare contro il computer al gioco “sette e mezzo”.
*/

#include<iostream>
#include "mazzo.h"
using namespace std;

int main(){
    Mazzo m;
    
    // estraiamo le due carte iniziali
    Carta *carta_giocatore = m.estrai();
    Carta *carta_banco = m.estrai();

    //punteggio del giocatore
    double punteggio = carta_giocatore->getPunteggio();

    cout << "Giocatore, la tua carta e' ";
    carta_giocatore->print();
    cout << " (punteggio = "<< punteggio <<")." << endl;

    Carta *nuova_carta;

    //estraiamo una carta finché il giocatore non vuole terminare
    bool finito = false;
    do {
        cout << "Vuoi pescare una nuova carta? (y/n) ";

        char risposta;
        cin >> risposta;
        if(risposta=='n') {
            finito=true;
        } else {
            //estrai una carta e aggiorna il punteggio
            nuova_carta = m.estrai();
            punteggio += nuova_carta->getPunteggio();

            cout << "Carta estratta: ";
            nuova_carta->print();
            cout << " (punteggio = "<< punteggio <<")." << endl;
            if(punteggio>7.5) { //se siamo oltre 7.5, abbiamo perso
                cout << "Hai perso!";
                exit(0);
            }
        }
    }
    while(!finito);

    // turno del banco: cercherà sempre di ottenere più del giocatore
    double punteggio_banco = carta_banco->getPunteggio();

    cout << "La carta del banco e' ";
    carta_banco->print();
    cout << " (punteggio = "<< punteggio_banco <<")." << endl;

    // estrai carte finché non superi il punteggio del giocatore
    while(punteggio_banco<punteggio) {
        nuova_carta = m.estrai();
        punteggio_banco += nuova_carta->getPunteggio();
        cout << "Il banco estrae la carta ";
        nuova_carta->print();
        cout << " (punteggio = "<< punteggio_banco <<")." << endl;

        if(punteggio_banco>7.5) {
            // se va oltre 7.5, perde
            cout << "Il banco perde! Vince il giocatore con il punteggio "<<punteggio<<endl;
            exit(0);
        }
    }

    cout << "Il banco vince con il punteggio "<<punteggio_banco << endl;
}