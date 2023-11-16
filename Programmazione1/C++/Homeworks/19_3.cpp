/*
Definire una funzione che prende in input un array
monodimensionale di double e restituisce l’arrotondamento
all’intero piu’ vicino della somma degli elementi dello array.
*/
#include <iostream>

using namespace std;

int arrotondamento(double A[], int DIM);

int main(){
    int DIM;
    cout << "Dimensione array: ";
    cin >> DIM; 
    double A[DIM];
    double n;
    for (int i=0; i<DIM; i++){
        cout << "Inserisci valore array " << i << ": ";
        cin >> n;
        A[i]=n;
    }
    cout << arrotondamento(A, DIM);
}

int arrotondamento(double A[], int DIM){
    double somma;
    for (int i=0; i<DIM; i++){
        somma+=A[i];
    }
    int sum=somma+0.5;
    return sum;
}