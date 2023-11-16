#include<iostream>
#include<cmath>
using namespace std;

int funzione(double* , int );

int main(){
	int n;
	cout<<"inserisci dimensione"<<endl;
	cin>>n;
	double v[n];
	
	int result= funzione(v, n);
	cout<<result;
}

int funzione(double *v, int n){
	double somma = 0.0;
	
	for(int i=0; i<n; i++){
		cout<<"inserisci numero"<<endl;
		cin>>v[i];
		somma = somma+v[i];
	}
	int r=round(somma);
	return r;
}
