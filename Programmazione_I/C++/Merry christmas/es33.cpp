/*
Scrivere un metodo che prenda in input una
matrice quadrata A di puntatori ad interi e restituisca
un double calcolato come il rapporto tra la somma
degli elementi della diagonale principale di A e la
somma degli elementi della diagonale secondaria diA
stessa. NB: Si presti attenzione ai numeri mancanti!
*/
#include <iostream>

using namespace std;

double foo(int* **A, int n){
    double rapporto=0.0;
    int somma_principale=0;
    int somma_secondaria=0;
    //sommo elementi diagonale principale
    for (int i=0; i<n; i++){
        somma_principale+=*A[i][i];
        somma_secondaria+=*A[i][n-1-i];
    }
    rapporto=static_cast<double>(somma_principale)/somma_secondaria;
    return rapporto;
}

int main(){
    int n=3;
    int* **A=new int**[n];

    for (int i=0; i<n; i++){
        A[i]=new int*[n];
        for (int j=0; j<n; j++){
            A[i][j]=new int[255];
        }
    }

    *A[0][0]=14;
    *A[0][1]=29;
    *A[0][2]=33;

    *A[1][0]=40;
    *A[1][1]=51;
    *A[1][2]=67;

    *A[2][0]=75;
    *A[2][1]=89;
    *A[2][2]=93;

        //somma principale =158   somma_secondaria=159
    cout << "rapporto=" << foo(A,3);

    return 0;
}