/* 11.3 
Codificare un programma completo in linguaggio C++ in cui:
• l’utente deve inserire da tastiera il capitale iniziale (C), il
tasso di interesse (TI), il target (T) e numero di anni (N);

• se uno tra T ed N `e un numero minore o uguale a zero,
allora il programma non dovr`a tener conto di tale
parametro; nel caso in cui sia T che N siano minori o
uguali a zero allora il programma terminer`a con un
messaggio di errore;

il programma darà in output il capitale finale ed il numero
totale di anni di accumulo; come nello esercizio
precedente, l’accumulo degli interessi sul montante si
interrompe quando il capitale raggiunge o supera la cifra
target T e comunque il numero di anni di accumulo non
deve superare N.

*/

#include <iostream>

using namespace std;


int main () {
    double TARGET; // T
    double capitale; // C
    double TASSO_INTERESSE; // TI
    int N; // N
    int anno; 
    
        
    cout << "Inserisci il capitale iniziale: " << endl,
    cin >> capitale;

    cout << "Inserisci il tasso d'interesse in double10: " << endl;
    cin >> TASSO_INTERESSE;

    cout << "Inserisci il target in formato double: " << endl;
    cin >> TARGET;

    cout << "Inserisci il numero di anni: " << endl;
    cin >> N;

    
    if (TARGET<=0 || N<=0){
        
        cerr << "Errore input" << endl;
    }
   
        while (capitale<TARGET) {
            capitale+=capitale*TASSO_INTERESSE;
            anno++;
            if (anno>N){
                cout << "Anni superati" << endl;
                break;
            }
        }
        if (!(cin.fail())){

        cout << "Capitale: " << capitale << endl;
        }
}