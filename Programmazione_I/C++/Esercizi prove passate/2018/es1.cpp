/*
Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo 
alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore 
massimo della diagonale
principale sia minore o uguale a w
*/

#include <iostream>
#define k 3
#define n 4

using namespace std;

bool foo(int A[k][n][n], double w){
    double media=0.0;
    int max= A[0][0][0];
    int min= A[0][0][0];
    //scorro la diagonale principale nella prima dimensione k=0
    for (int i=1;i<n;i++){
        //verifico massimo e minimo sulla diagonale
        if(A[0][i][i] < min){
            min=A[0][i][i];
        }
        if (A[0][i][i] > max){
            max=A[0][i][i];
        }
    }
    //calcolati max e min, calcolo la media fra essi
    media=(max+min)/2;
    if (media <=w){
        return true;
    }
    return false;
}