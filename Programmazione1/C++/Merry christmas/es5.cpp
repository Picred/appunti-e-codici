/*
Scrivere un metodo che prenda come parametri
formali una matrice A n×m di long ed un long x, e
restituisca in output l’indice della colonna di A con il
maggior numero di occorrenze di x.
*/

#include <iostream>

#define n 2
#define m 3

using namespace std;

int indice_colonna(long A[n][m], long x){
    int max=0;
    int max2=0;
    int indice_colonna=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                
                if(A[i][j]==x ){
                    max++;
                }
                if (max>max2){
                    max2=max;
                    max=0;
                    indice_colonna=j;
                }
            }
        }
    return indice_colonna;
}

int main(){
    long A[n][m]={ {3,3,2},
                   {3,4,2} };
    long x=4;

    cout << "La colonna con il maggior numero di x=" << x << " e': " << indice_colonna(A,x);

    return 0;
}