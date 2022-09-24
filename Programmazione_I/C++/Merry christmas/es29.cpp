/*
Scrivere un metodo che prenda in input una
matrice quadrata A di numeri interi ed un double w, e
restituisca il valore booleano true se il rapporto tra il
minimo ed il massimo valore della diagonale
secondaria di A e minore o uguale a w.
*/
#include <iostream>
#define n 3

using namespace std;


bool foo(int A[n][n], double w){

    double rapporto=0.0;
    int massimo=A[n-1][n-1];
    int minimo=A[n-1][n-1];

    //scorro la diagonale secondaria
    for (int i=0; i<n; i++){
        if(A[i][n-1-i] > massimo){
            massimo=A[i][n-1-i];
        }

        if (A[i][n-1-i]<minimo){
            minimo=A[i][n-1-i];
        }
    }

    rapporto = static_cast<double>(minimo)/massimo;

    if (rapporto<=w){
        return true;
    }

    return false;
}

int main (){
    int A[n][n]= { {1,2,3},
                   {4,5,6},
                   {7,8,9} };

    double w=0.3;

    cout << foo(A,w);

    return 0;
}