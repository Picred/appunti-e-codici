/*
5.Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x.
*/

#include <iostream>

#define n 2
#define m 3

using namespace std;

int pippo(long A[n][m], long x)
{
    int index = 0, counter, counter2=0;

    for (int j = 0; j < m; j++){
        counter = 0;
        for (int i = 0; i < n; i++){
            if (A[i][j] == x){
                counter++;
            }
        }
        if (counter>counter2){ //valuto se il counter di x nella colonna è maggiore del counter predecente
            index=j; //segno la colonna corrispondente al maggior numero di x 
            counter2=counter;
        }
    }

    return index;
}

int main(){
    long M[n][m]={ {2,3,2},
                   {3,5,3} }; 

    long numero=3;

    cout << pippo(M,numero);
}
