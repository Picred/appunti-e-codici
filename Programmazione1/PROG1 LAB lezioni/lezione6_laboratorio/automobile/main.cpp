#include "automobile.h"
#include<iostream>
using namespace std;

int main() {
    Automobile a1("ibrido","medium");
    Automobile a2("benzina","large");

    a1.rifornisci(100);
    a2.rifornisci(100);

    cout << "Autonomia iniziale di a1: "<<a1.autonomia()<<endl;
    cout << "Autonomia iniziale di a2: "<<a2.autonomia()<<endl;

    double km=100;

    while((a1.autonomia()>km) & (a2.autonomia()>km)) {
        a1.percorri(km);
        a2.percorri(km);
        cout << endl;
        cout << "Autonomia residua di a1: "<<a1.autonomia() << endl;
        cout << "Autonomia residua di a2: "<<a2.autonomia() << endl;
    }

    cout << endl;
    if(a1.autonomia()>a2.autonomia())
        cout << "Vince la corsa a1 dopo aver percorso "<< a1.chilometri() << " chilometri con una autonomia residua di "<<a1.autonomia() << " chilometri."<<endl;
    else
        cout << "Vince la corsa a2 dopo aver percorso "<< a2.chilometri() << " chilometri con una autonomia residua di "<<a2.autonomia() << " chilometri.";
}