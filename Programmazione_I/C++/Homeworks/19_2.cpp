/*
Definire una funzione che prende in input due interi senza segno e
restituisce il rapporto (numero in virgola mobile) tra i due
argomenti. Se il divisore e’ zero, la funzione restituisce il valore -1.

*/
#include <iostream>

using namespace std;

float divisione(unsigned int n1, unsigned int n2);

//prova della funzione
int main (){
    int n1, n2;

    cout << "n1,n2: ";
    cin >> n1 >> n2;
    
    cout << divisione(n1,n2);
}

float divisione(unsigned int n1, unsigned int n2){
    if (n2!=0){
        float rap;
        rap=static_cast<float>(n1)/n2;
        return rap;
    } 
    else {
        return -1;
    }
    
}