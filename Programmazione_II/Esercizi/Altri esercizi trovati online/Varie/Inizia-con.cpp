#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
void stampa(T *v, int n, ostream& out){
	for(int i=0; i<n; i++) out << v[i];
	out << " ";
}


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		char c;
		in >> c;
		int n;
		in >> n;

		char primo[n];
		for(int i=0; i<n; i++) in >> primo[i];
		if(primo[0]==c) stampa(primo,n,out);
		
		in >> n;
		char secondo[n];
		for(int i=0; i<n; i++) in >> secondo[i];
		if(secondo[0]==c) stampa(secondo,n,out);

		in >> n;
		char terzo[n];
		for(int i=0; i<n; i++) in >> terzo[i];
		if(terzo[0]==c) stampa(terzo,n,out);

		out << endl;
	}
	in.close();
	out.close();

	return 0;
}