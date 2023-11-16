/*
Scrivere un metodo che prenda in input un
parametro formale matrice A di interi di dimensioni
nxn ed un double w, e restituisca un valore booleano
true se esiste almeno una colonna della matrice A per
cui il rapporto tra la somma degli elementi della
colonna stessa e la somma degli elementi della
diagonale principale di A sia maggiore di w
*/
#include <iostream>

using namespace std;

#define n 3

bool foo(int A[n][n],double w){
    int somma_colonna=0;
    int somma_principale=0;
    double rapporto=0.0;

    //calcolo somma elementi diagonale principale
    for (int i=0;i<n; i++){
        somma_principale+=A[i][i];
    }
        
    //fisso la la colonna e scorro le righe
        for(int j=0;j<n; j++){
            somma_colonna=0;
            for (int i=0;i<n;i++){
                somma_colonna+=A[i][j];   
            rapporto=somma_colonna / static_cast<double>(somma_principale);

                if(rapporto>w){
                    return true;
                }
            }

        }
        return false;
}


int main(){
    //TEST FUNZIONE
    int A[n][n];

    A[0][0]=2;
    A[0][1]=3;
    A[0][2]=4;
    A[1][0]=8;
    A[1][1]=0;
    A[1][2]=1;
    A[2][0]=10;
    A[2][1]=11;
    A[2][2]=7;

    bool esiste;
    // 20/9=2.2222 - 14/9=1.5555 - 12/9=1.333

    esiste=foo(A,2.1);
    cout << esiste;

    reuturn 0;
}