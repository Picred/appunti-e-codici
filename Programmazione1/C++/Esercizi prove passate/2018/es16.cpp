/*
Scrivere un metodo che prenda in input una matrice S di puntatori 
a stringhe di dimensione n x m ed un array B di short
di dimensione m e che 

restituisca uno short che rappresenti 
l'indice della riga in S con il maggior numero di stringhe aventi
lunghezza minore o uguale del corrispondente numero nello array B 
(NB: in pratica la lunghezza della stringa di indici (i,j) va
confrontata con il numero di indice j in B).
*/

#include <string>

using namespace std;

#define n 5
#define m 4

short foo(string* S[n][m], short B[m]){
    short indice;
    int counter=0;
    short max=0;
    for (int i=0; i<n; i++){
        counter=0;
        for (int j=0; j<m; j++){
            if ( S[i][j] -> length() <= B[j])
                counter++;
        }
        if(counter>max)
            indice=i;
    }
    return indice;
}