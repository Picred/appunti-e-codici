#include <iostream>

using namespace std;

int main(){

int a, b, c;
int risultato;

cout << "Inserisci il primo numero intero: ";
cin >> a;

cout << "Inserisci il secondo numero intero: ";	
cin >> b;

cout << "Inserisci il terzo numero intero: ";	
cin >> c;

//risultato=((a>b ? a : b) > c ? (a>b ? a : b) : c);

int max1=(a>b ? a : b);
risultato= (max1>c ? max1 : c);

cout << "Il massimo è " << risultato << endl;

}