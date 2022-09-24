/*
Scrivere un metodo che prenda come parametri
formali una matrice quadrata A n×n di puntatori ad int
e restituisca in output un bool che indichi se la somma
degli elementi puntati dalla diagonale sottostante la
diagonale secondaria è divisibile per n
*/
#include <iostream>

using namespace std;

#define n 3

bool foo(int* A[n][n]){
    //elementi della diagonale sottostante la secondaria
    int somma=0;
    
    for (int i=1; i<n; i++){
        somma+= *A[i][n-i];
    }

    if (somma%n==0){
        return true;
    }
    return false;
}

int main(){
    int *A[n][n];

    A[0][0]=new int(1);
    A[0][1]=new int(1);
    A[0][2]=new int(1);

    A[1][0]=new int(1);
    A[1][1]=new int(1);
    A[1][2]=new int(3);

    A[2][0]=new int(2);
    A[2][1]=new int(3);
    A[2][2]=new int(1);

    //3+3=6 6%3=0 -> true
    cout << foo(A);

    return 0;
}