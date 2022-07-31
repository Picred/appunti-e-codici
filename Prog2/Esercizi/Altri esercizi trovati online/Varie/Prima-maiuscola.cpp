#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

template <class T>
void stampa(T *v, int n, ostream& os){
	for(int i=0; i<n; i++) os << v[i];
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		int p;
		int s;
		int t;
		
		in >> p;
		char primo[p];
		for(int i=0; i<p; i++) in >> primo[i];
		

		primo[0] = toupper(primo[0]);
		stampa(primo,p,out);
		out << " ";

		in >> s;
		char secondo[s];
		for(int i=0; i<s; i++) in >> secondo[i]; 
		

		secondo[0] = toupper(secondo[0]);
		stampa(secondo,s,out);

		out << " ";

		in >> t;
		char terzo[t];
		for(int i=0; i<t; i++) in >> terzo[i]; 

		terzo[0] = toupper(terzo[0]);
		stampa(terzo,t,out);
		
		out << endl;		
	}
	in.close();
	out.close();

	return 0;
}
