/*
Codificare un programma in linguaggio C++ che chieda
all’utente di inserire il raggio di un cerchio.
Il programma dovr`a calcolare e stampare l’area e la
circonferenza del cerchio
*/

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int main (){
	
	double raggio, area, circonferenza, pi=3.14;
	
	cout << "Inserisci il valore del raggio: " << endl;
	cin >> raggio;

	area=raggio*raggio;
	area=area*pi;
	cout << "L'area del cerchio e': " << fixed << setprecision(5) << area << endl;
		
	circonferenza=raggio*2;
	circonferenza=circonferenza*pi;
	cout << "La circonferenza del cerchio e' uguale a: " << fixed << setprecision(5) << circonferenza << endl;

}