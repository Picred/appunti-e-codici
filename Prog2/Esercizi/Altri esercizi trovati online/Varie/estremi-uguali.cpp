/*
Si fornisca un programma che date in input tre parole di lunghezza variabile sia in grado di individuare, tra queste, quelle caratterizzate dagli estremi uguali e di contarne il numero.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		int n;
		in >> n;
		char primo[n];
		int cont = 0;

		for(int i=0; i<n; i++) in >> primo[i];
		if(primo[0]==primo[n-1]) cont++;

		in >> n;
		char secondo[n];
		for(int i=0; i<n; i++) in >> secondo[i];
		if(secondo[0]==secondo[n-1]) cont++;

		in >> n;
		char terzo[n];
		for(int i=0; i<n; i++) in >> terzo[i];
		if(terzo[0]==terzo[n-1]) cont++;

		out << cont << endl;
	}
	in.close();
	out.close();

	return 0;
}