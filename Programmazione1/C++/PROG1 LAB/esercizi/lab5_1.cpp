/*

Scrivere una funzione che prenda in input una matrice quadrata A di short,
e restituisca un bool che indichi se la diagonale principale è identica
(procedendo dall’alto verso il basso) alla secondaria.

*/

#include <iostream>
using namespace std;

bool fun(short **A, int n){
    
    for (int i=0; i<n; i++){
        if(A[i][i]!=A[i][n-i-1]){
            return false;
        }
    }
    return true;
}


int main(){
    
    int n = 3;
    
    short** A=new short*[n];
    for(int i=0;i<n; i++){
        A[i]=new short[n];
    }
    A[0][0]=1;
    A[0][1]=2;
    A[0][2]=1;

    A[1][0]=1;
    A[1][1]=2;
    A[1][2]=1;

    A[2][0]=1;
    A[2][1]=2;
    A[2][2]=1;

    cout << fun(A,n) << endl;
    
    return 0;
}
/*
1 2 2
1 2 1
3 2 1
*/