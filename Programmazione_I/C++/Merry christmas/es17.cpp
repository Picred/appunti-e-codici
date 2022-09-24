/*
Scrivere un metodo che prenda in input una
matrice A di numeri interi e due double w e v, e
restituisca il valore booleano true se esiste almeno una
colonna di A in cui la media dei suoi elementi e
compresa tra w e v. NB: Si assuma che w <=v.
*/
#include <iostream>

using namespace std;


bool foo(int **A, int n, int m, double w, double v){
    //scorro matrice per colonna
    double media=0.0;
    int elementi;
    for (int j=0; j<m; j++){
        elementi=0;
        for (int i=0; i<n; i++){
            elementi+=A[i][j];
        }
        media= static_cast<double>(elementi)/n;
        if (media>w && media<v){
            return true;
        }
    }
    return false;
}

int main(){
    int n=3;
    int m=2;
    int **A=new int*[n];

    for (int i=0; i<n; i++){
        A[i]=new int[m];
    }
    A[0][0]=1;
    A[0][1]=2;

    A[1][0]=3;
    A[1][1]=4;

    A[2][0]=5;
    A[2][1]=6;

    double w=4;
    double v=5;

    cout << foo(A,n,m,w,v);

    return 0;
}