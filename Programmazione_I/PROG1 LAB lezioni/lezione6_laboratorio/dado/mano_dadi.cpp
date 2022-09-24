#include "dado.h"
#include<iostream>

using namespace std;

int main() {
    Dado d11; //dado 1 del primo giocatore
    Dado d12; //dado 2 del primo giocatore
    Dado d21; //dado 1 del secondo giocatore
    Dado d22; //dado 2 del secondo giocatore

    cout << "Il primo giocatore lancia i dadi." << endl;
    d11.lancia();
    d12.lancia();
    cout << "Il secondo giocatore lancia i dadi." << endl;
    d21.lancia();
    d22.lancia();

    int punteggio1 = d11.getValore() + d12.getValore(); //punteggio totale giocatore 1
    int punteggio2 = d21.getValore() + d22.getValore(); //punteggio totale giocatore 2

    if(punteggio1>punteggio2)
        cout << "Vince il giocatore 1 ("<<punteggio1<<" vs "<<punteggio2 <<")"<<endl;
    else if(punteggio2>punteggio1)
        cout << "Vince il giocatore 2 ("<<punteggio2<<" vs "<<punteggio1 <<")"<<endl;
    else
        cout << "Parita' ("<<punteggio1<<" vs "<<punteggio2<<")"<<endl;
}