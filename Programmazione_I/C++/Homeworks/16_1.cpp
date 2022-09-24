/*
16.1
Scrivere un programma in C++ che permetta di simulare
una sequenza di N lanci di una coppia di dadi, dove N `e un
numero scelto dall’utente oppure una costante scelta a tempo
di compilazione. Il programma dovr`a stampare le sequenze
dei due numeri (output primo dado e output secondo dado)
in due colonne separate. ES:
                1 6
                3 4
                1 2
                6 3

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main ()
{

int tiro1,tiro2, totali; // tiro1 e tiro2=valori random dei tiri. totali=tiri totali da input

    srand(time(0)); //stampa valori random in più esecuzioni

    cout << "Inserisci il numeri di tiri che vuoi fare con due dadi: ";
    cin >> totali;

    if (cin.fail()) { // controllo se c'è un errore di input -> finisco il programma 
        cerr << "ERRORE: Input non valido.";
       return -1;
    }

        cout << setw(4) << "I tuoi tiri sono i seguenti:" << endl; //stampa dei 'totali' tiri
    for (int i=0; i<totali; i++){
            // intervallo [1,6] (b-a+1)+a
        tiro1=rand()%(6-1+1)+1; // assegno un valore random all'interno di [1,6]
        tiro2=rand()%(6-1+1)+1; // assegno un valore random all'interno di [1,6]

        //stampa dei tiri random
        cout << setw(3) << tiro1;
        cout << setw(5) << tiro2 << endl;
    }

    return 0;
}