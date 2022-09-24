/*
Scrivere un metodo che prenda in input tre matrici
A, B e C di boolean con le stesse dimensioni, e
restituisca un boolean che indichi se una diagonale in
A, soprastante la diagonale principale, è presente
anche in B e C (nella stessa posizione e con la stessa
sequenza di valori!
*/



#include <iostream>
#define n 3
#define m 3

using namespace std;

bool funzione(bool A[n][m],bool B[n][m],bool C[n][m]){
    int counter=0;
    for(int i=0;i<n;i++){
        if(A[i][i+1]==B[i][i+1] && A[i][i+1]==C[i][i+1]){
            counter++;
        }
    }
    if(counter==n-1){
    return true;
    } else {
        return false;
    }
}



int main(){
    
    bool A[n][m]={{0,1,1},
                  {0,0,1},
                  {1,0,0} };
    
    bool B[n][m]={{0,1,0},
                  {0,1,1},
                  {1,0,0}};

    bool C[n][m]={{0,1,0},
                  {0,0,1},
                  {1,0,1}};
    
    cout << funzione (A,B,C);

    return 0;
}
