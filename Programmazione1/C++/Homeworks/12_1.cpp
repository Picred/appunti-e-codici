/*
Codificare un programma in linguaggio C++ nel quale si 
chiedano all’utente due numeri in virgola mobile (a e b) da tastiera. 
Il programma deve calcolare e stampare la somma, la media,
ed il max tra i due numeri. Tutti gli output del programma dovranno essere in notazione
scientifica, con una precisione di 4 cifre dopo la virgola.
*/

#include <iostream> // cin/cout
#include <cmath> // Operatori matematici
#include <iomanip> // Precisione del risultato

using namespace std;

int main () {
	
	float a, b, somma, media, max;
	
	cout << "Inserisci il primo numero con la virgola: ";
	cin >> a;
	
	cout << "Inserisci il secondo numero con la virgola: ";
	cin >> b;
	
	somma=a+b;
	cout << "La somma tra i due numeri e'': " << scientific << fixed << setprecision(4) << somma << endl;
		
			media=a+b;
			media=media/2;
			
			cout << "La media tra i due valori e': " << scientific << fixed << setprecision(4) << media << endl;
		
		if (a>b) {
				max=a;
				cout << "Il valore massimo tra i due numeri e': " << scientific << fixed << setprecision(4) << max << endl;
				}
		else{
			
				max=b;
				cout << "Il valore massimo tra i due numeri e': " << scientific << fixed << setprecision(4) << max;
		}
		return 0;
	}