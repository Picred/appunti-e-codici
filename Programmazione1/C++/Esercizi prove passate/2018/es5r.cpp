/*
Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, 
e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A 
che nella colonna i-esima di B. NB: per decidere se unelemento int della 
matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero
piu vicino di quest’ultimo.
*/
#include <cmath>
#define n 3
#define m 4
#define k 2

int* foo(int A[n][m], double B[k][n]){
    int *C=new int[n];

    double media=0;
    int arrot=0;

    for (int i=0; i<n; i++){
        //calcolo l'approssimazione del double in B
        for (int j=0; j<k; j++){
            arrot= round(B[j][i]);

            //scorro le righe di A
            for (int l=0; l<m; l++){
                if (A[i][l]==arrot){
                    C[i]=arrot;
                }
            }
        }
    }
}