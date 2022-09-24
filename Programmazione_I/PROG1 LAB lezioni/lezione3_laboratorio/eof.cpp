#include<iostream>

using namespace std;

int main() {
    int somma = 0;
    int x;
    bool finito = false;
    while(!finito) {
        cout << "Inserisci un numero: ";
        cin >> x;
        if(cin.eof()) {
            finito=true;
        } else {
            somma += x;
        }
    }

    cout << "La somma dei numeri inseriti e': "<< somma;
}