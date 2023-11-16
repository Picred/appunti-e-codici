/*
Scrivere un metodo che preveda un parametro formale matrice A di double di dimensioni n × k ed un array B di interi di
dimensione n, e restituisca l’indice della colonna in A che contiene il maggior numero di elementi tali che l’approssimazione
dell’elemento stesso al numero intero pi`u vicino sia uguale al corrispondente elemento intero in B (NB: in pratica il generico
elemento di indice (i,j) va confrontato con l’elemento in B di indice i).
*/
#include<cmath>

using namespace std;

#define n 4
#define k 5

short foo(double A[n][k], int B[n]){
    short indice_ret;
    int counter;
    int max=0;
    //scorro la matrice di double A
    for (int i=0; i<n; i++){
        counter=0;
        for (int j=0; i<k; j++){
            int appros= round(A[i][j]);
            if (appros == B[i])
                counter++;
        }
            if (counter>max){
                max=counter;
                indice_ret=i;
            }

    }
    return indice_ret;
}