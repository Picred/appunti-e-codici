#include<iostream>
#include<math.h>

using namespace std;

int main(){
	
	float p;
	int DIM;

	cout << "inserisci un numero positivo: " << endl;
	cin>>p;
	
	p = round(p);

	int V[(int)p];

	for(int indice=0; indice<p; indice++){
		cout << "inserisci il prossimo numero nell'array: " << endl;
		cin>>V[indice];
	}

	for(int indice=0; indice<p; indice++){
		cout << "Array[" << indice << "]=" << V[indice] << endl;
	}

}