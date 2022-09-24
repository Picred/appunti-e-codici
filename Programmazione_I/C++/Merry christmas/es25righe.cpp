/*
Scrivere un metodo che prenda in input una
matrice di interi M di dimensioni nx m, uno short k ed
un double x, e restituisca il valore booleano true se

esiste almeno una colonna in M contenente
esattamente k coppie di elementi adiacenti tali che il
rapporto tra il primo elemento ed il secondo elemento
di ogni coppia sia minore di x. 
NB: Si assuma k <= n -
1 e si presti attenzione alle divisioni per zero!
*/
#include <iostream>

using namespace std;

#define n 3
#define m 4

bool funzione(int M[n][m],short k, double x){
    double rapporto=0.0;
    int counter;

    //scorro le colonne
    for (int i=0; i<n; i++){
        counter=0;

        for (int j=0; j<m; j++){
            // cout << endl << "counter: " << counter << endl;
                if( j != (m-1) && (M[i][j+1]) != 0 && (M[i][j+1]) !=0 ){

                rapporto=M[i][j] /(double)(M[i][j+1]);
                    if (rapporto < x){
                        counter++;
                        j++;
                    }
                } else {
                    counter=0;
                    break;
                }
            
            
        }
        if (counter==k){
            return true;
        }
    }
    return false;
}


int main(){
    //esistono 2 rapporti fra elementi adiacenti nella stessa riga minori di 0.8 
    int M[n][m] = { {1,2,3,4},
                    {5,6,6,0},
                    {9,10,11,12} };
    bool check;

    check=funzione(M,2,0.8);

    cout << check;

    return 0;

    //esercizio corretto se si scorrono le righe, sbagliato per le colonne
}