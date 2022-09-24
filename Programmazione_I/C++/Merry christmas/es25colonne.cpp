/*
25.Scrivere un metodo che prenda in input una 
matrice di interi M di dimensioni nx m, uno short k ed 
un double x, e restituisca il valore booleano true se 
esiste almeno una colonna in M contenente 
esattamente k coppie di elementi adiacenti tali che il 
rapporto tra il primo elemento ed il secondo elemento 
di ogni coppia sia minore di x. NB: Si assuma k <= n -
1 e si presti attenzione alle divisioni per zero!
*/

#include <iostream>

#define n 2
#define m 3

using namespace std;

bool fun(int M[n][m], short k, double x){
    
    int counter;

    for(int j=0;j<m;j++){
        counter=0;

        for(int i=0;i<n;i++){
            if (i+1!=n){
                int el1=M[i][j], el2=M[i+1][j];

                if(static_cast<double>(el1)/el2<x)
                   counter++;
         
            }   
            
        }
            if(counter>=k)
                 return true;
    }

    return false;
}

int main(){

    int M[n][m];

    short k = 1;

    double x = 1;

    M[0][0]=14;
    M[0][1]=4;
    M[0][2]=2;

    M[1][0]=7;  
    M[1][1]=4;  
    M[1][2]=2;

    //2  1  1

    cout << fun(M,k,x);

    return 0;
}

