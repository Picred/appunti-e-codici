//esercizio 1, implementazione e verifica codice
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double **foo (double **A, int M, int N){
    srand(time(0));
    double s;
    double **B = new double *[N];
        for (int i=0; i<N; i++){
            B[i]=new double[M];
            for (int j=0; j<M; j++){
                // s=rand()%2;
             s=rand()/ (static_cast<double>(RAND_MAX));
                if (A[i][j]>s){
                    B[i][j] = A[j][i];
                } else {
                    B[i][j]=A[i%M][i%N];
                }
            }
        }
        return B;
}
//test della funzione //non dà nulla in OUTPUT
int main(){
    double **B;
    B[0][0]=55.4;
    B[1][0]=5.4;
    B[2][0]=24.8;
    B[0][1]=9.99;
    B[1][1]=69.4;
    B[2][1]=70.5;
    B[0][2]=145.1;
    B[1][2]=31.2;
    B[2][2]=15.4;


    B=foo(B,3,3);

    for (int i=0; i<3; i++){
        for (int j=0; j<3;j++){
            cout << B[i][j];
        } cout << endl;
    }

}