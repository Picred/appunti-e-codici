/*
Scrivere un metodo che preveda due parametri formali matrici di interi, A e B di dimensioni k x n ed
n x k rispettivamente, e restituisca uno array monodimensionale di k elementi double in cui lo i-esimo 
elemento sia uguale alla differenza tra la media aritmetica degli elementi della riga i-esima di A ed il minimo valore degli elementi 
della colonna i-esima
di B.
*/

#include <iostream>

#define n 3
#define k 4

using namespace std;

double* fun(int A[k][n], int B[n][k]){
    double *Ret=new double[k]; // array da restituire

    double mediaRigaA=0.0;
    double minColonnaB=0;

    for(int i=0; i<k; i++){ //scorro per riga A e scorro per colonna B
        mediaRigaA=A[i][0];
        int j=0;
        minColonnaB=B[j][i];
        for(j=1; j<n; j++){
            mediaRigaA+=A[i][j];

            if(B[j][i] <= minColonnaB){
                minColonnaB=B[j][i];
            }
        }
        mediaRigaA/= (double)(n);
        double elemento= mediaRigaA-minColonnaB;
        Ret[i]=elemento;
    }
    
    return Ret;
}

int main(){
    int A[k][n] =   {{3,3,3},
                     {5,5,5},
                     {2,2,2},
                     {8,8,8}};
   
   
    int B[n][k] =   {{5,2,8,1},
                     {4,8,6,0},
                     {3,9,3,9}};      

    double* C=fun(A,B);
    for(int i=0;i<k;i++){
        cout << C[i]<< endl;
    }

    // cout << *fun(A,B); //stampa solo il primo indice

}