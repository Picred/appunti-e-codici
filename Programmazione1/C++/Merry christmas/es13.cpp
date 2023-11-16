/*
Scrivere un metodo che prenda come parametri
formali una matrice quadrata A n×n di puntatori a char
e restituisca in output un bool che indichi se esiste una
colonna in A identica alla diagonale principale di A
*/
#include <iostream>

using namespace std;

#define n 3

bool foo(char*A[n][n]){
    int counter;
    //scorro la matrice di caratteri
    for (int j=0; j<n; j++){  
        counter=0; 
        for(int i=0; i<n; i++){
            char carattere= *A[i][j];
            if (carattere!=*A[i][i]){
                break;
            } else{
                counter++;
            }
        }
        if(counter==n){
            return true;
        }
    }
    return false;
}

int main(){
    char*A[n][n];
    
    A[0][0]=new char('b');
    A[0][1]=new char('b');
    A[0][2]=new char('b');

    A[1][0]=new char('t');
    A[1][1]=new char('a');
    A[1][2]=new char('b');

    A[2][0]=new char('o');
    A[2][1]=new char('r');
    A[2][2]=new char('r');

    cout << foo(A);

    return 0;
}