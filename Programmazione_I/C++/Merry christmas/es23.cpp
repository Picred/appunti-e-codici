/*

23.Scrivere un metodo che prenda in input un 
parametro formale matrice K di double di dimensioni n x m
e due interi a e b, e restituisca un array A di short 
di dimensione m, in cui l'elemento A[i] è calcolato 
come il numero di elementi della colonna i-esima di K 
tali che, approssimati all'intero più vicino, siano 
compresi tra a e b (inclusi). NB: si assuma a < b.

*/

#include <iostream>
#include <cmath>

#define n 2
#define m 3

using namespace std;

short* foo(double K[n][m],int a,int b){
    
    short *A = new short [m];

    int k;
        for(int j=0, k=0;j<m; j++, k++){
            int counter=0;
                for(int i=0;i<n;i++){
                    if(round(K[i][j]) >= a && round(K[i][j]) <= b){
                        counter++;
                    }
                    A[k] = counter;
                }
        }
    
        
    return A;
}

int main(){
    double K[n][m];

    int a = 0;
    int b = 200;

    K[0][0]=45.14;  //1 colonna 45               45  4   4
    K[0][1]=4.14;   //2 colonna 4                98  20  37
    K[0][2]=3.9;    //3 colonna 4               
    
    K[1][0]=97.6;   //1 colonna 98               
    K[1][1]=19.74;  //2 colonna 20               
    K[1][2]=37.17;  //3 colonna 37               

    //A[m] = 2 2 2

    

    short* A=foo(K,a,b);
    
    //stampo array
    for (int i=0;i<m;i++){
        cout << A[i] << " ";
    }

    return 0;
}