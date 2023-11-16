/*
21.Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a. 
*/
#include <iostream>
#include <cmath>

using namespace std;


bool fun(double **D,int n, int m, int a){
    double somma=0.0;
    //scorro le colonne
    for (int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if (i+1!=n){
            double el1=D[i][j];
            double el2=D[i+1][j];
            somma= round(el1+el2);
            } else {
                break;
            }
            if(somma==a){
                return true;
            }
            
        }
    }
    return false;
}

int main(){
    //allocazione dinamica della matrice
    int n = 3;
    int m = 2;
    double c=0.0;

    int a = 15;

    double **D=new double*[n];
        for (int i=0; i<n;i++){
            D[i]=new double [m];
            for (int j=0;j<m;j++){
                D[i][j]=c+0.575;
                c=c+1.754;
            }
        }

    //stampo la matrice
     for (int i=0; i<n;i++){
        for (int j=0;j<m;j++){
            cout << D[i][j] << "  ";
        }
        cout << endl;
    }

    cout << endl << fun (D,n,m,a);
    
    return 0;
}