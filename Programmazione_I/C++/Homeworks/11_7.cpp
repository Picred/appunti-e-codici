/*
11.7
Codificare in linguaggio C++ un algoritmo che stampi le prime N potenze di 2, dove N `e un parametro scelto dall’utente
(input da tastiera).*/
#include <iostream>

using namespace std;

int main(){

    int potenza=1, n;

    cout << "Inserisci le n potenze di 2 che vuoi stampare: " << endl;
    cin >> n;


    for (int i=0; i<n; i++){
    cout << "Potenza di 2^" << i << ":" << potenza << endl;
    potenza=potenza*2;
    }
 
}