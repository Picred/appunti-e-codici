/*
Definire una funzione che prende in input due argomenti double e
restituisce il valore somma degli argomenti arrotondato all’intero
piu’ vicino.

*/
#include <iostream>

using namespace std;

double somma(double n1, double n2);

//prova della funzione
int main(){
    cout << "N1 e N2: "; 
    double n1, n2;
    cin >> n1 >> n2;
    cout << somma(n1, n2);
}

double somma(double n1, double n2){
    double sum=n1+n2;
    int sum1=sum+0.5;
    return sum1;
}