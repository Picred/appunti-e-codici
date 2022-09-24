/*
Scrivere un metodo che prenda un parametro formale matrice di stringhe S di dimensione n × m e due array di caratteri C
e D di egual dimensione n e restituisca un array di short nel quale il generico elemento di posto i contiene il numero di stringhe
che iniziano con il carattere di C avente indice i e finiscono con il carattere in D avente indice i.
*/

#include <iostream>
#include<string>
#define n 4
#define m 6
using namespace std;


short* foo(string S[n][m], char C[n], char D[n]){

    short* ret=new short[n];
    int counter;

    for (int i=0; i<n; i++){
        counter=0;
        for (int j=0; j<m; j++){
            if(S[i][j][0] == C[i] && S[i][j][(S[i][j].length()-1)] == D[i])
                counter++;
        }
        ret[i]=counter;
    }
    return ret;
}
