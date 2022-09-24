/*
Scrivere un metodo che prenda in input una
matrice di stringhe di dimensioni n×m, due stringhe x
e y e due short k e w; il metodo restituisca la

percentuale di colonne della matrice che contengono
almeno k stringhe contenenti almeno w caratteri
presenti sia in x che in y. NB: si assuma, per
semplicità, che ognuna delle stringhe della matrice non
che le stringhe x e y non contengano lo stesso
carattere più di una volta
*/

#include <iostream>
#include <string>
#define n 2
#define m 3

using namespace std;

double fun(string S[n][m],string x, string y, short k, short w){
    double percentuale=0.0;
    int n_stringhe;

    // if (n_stringhe>=k) ----> percentuale = cast n_stringhe/n;
    //scorro le colonne 

    for (int j=0; j<m; j++){
        for (int i=0; i<n; i++){
            
        }
    }
}