/*
Codificare un programma in linguaggio C++ che chieda
all’utente di inserire TRE numeri da tastiera. L’utente può
inserire numeri interi o decimali.
Il programma dovrà calcolare e stampare l’arrotondamento al
valore intero più vicino di ogni numero inserito dallo utente.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main (){
	
	float d1, d2, d3;
	
	cout << "Inserisci un numero decimale o con la virgola: ";
	cin >> d1;
	
	cout << "Inserisci un secondo numero decimale o con la virgola: ";
	cin >> d2;
	
	cout << "Inserisci un terzo numero decimale o con la virgola: ";
	cin >> d3;
	
		int i1=d1+0.5;
		int i2=d2+0.5;
		int i3=d3+0.5;
	
			cout << "Il numero intero piu'' vicino al primo numero inserito e': " << i1 << endl;
			cout << "Il numero intero piu' vicino al secondo numero inserito e': " << i2 << endl;
			cout << "Il numero intero piu' vicino al terzo numero inserito e': " << i3;
		
		return 0;
	
}