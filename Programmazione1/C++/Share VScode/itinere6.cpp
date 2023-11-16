/*
Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero pi`u vicino di
quest’ultimo.
*/
#include <iostream>
#include <cmath>

using namespace std;

#define n 2
#define m 3
#define k 2

int *foo(int A[n][m], double B[k][n]){
    int *arr = new int[n];
    
    double media_aritmetica;
    int elemento_rigaA;
    double elemento_colonnaB;

    int j=0;
    int j1=0;
    int i1=0;
    //scorro le righe di A
    for (int i=0; i<n; i++){
        while (j<m && j1<k && i1<n){
            elemento_rigaA=A[i][j];
            elemento_colonnaB=round(B[j1][i]);
            
            if (elemento_rigaA==elemento_colonnaB){
            arr[i1]=(elemento_rigaA+elemento_colonnaB)/2;
            i1++;
            }
            j++; j1++;
        }
    }
    return arr;
    
}

int main(){
    int A[n][m]; double B[k][n];
    A[0][0]=23;
    A[0][1]=7;
    A[0][2]=17;

    A[1][0]=53;
    A[1][1]=88;
    A[1][2]=90;

    B[0][0]=26.8;
    B[0][1]=52.9;
    B[1][0]=7.4;
    B[1][1]=87.6;

    int *array=foo(A,B);
    // array=gesu(A,B);

    for (int i=0; i<n; i++){
        cout << array[i] << " ";
    }
}