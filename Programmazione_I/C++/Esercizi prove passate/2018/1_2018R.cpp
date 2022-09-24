/*
Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w.
*/
#include <iostream>

using namespace std;


bool foo(int ***A, int k, int n, double w);

int main(){
    
    int A[3][2][2]={1,2,3,4,5,6,7,8,9,10,11,12};
    double w = 5.4;

    bool esiste;

    esiste=foo(A,3,2,w); 
    cout << esiste;
}



bool foo(int ***A, int k, int n, double w){
    int max, min;
    bool check=false;


    for (int i=0; i<k; k++){
        max=A[i][0][0];
        min=A[i][0][0];

        cout << "k= " << k << endl; 

        for (int j=0; j<n; j++){
                
                if (A[i][j][j]>min){
                    min=A[i][j][j];
                } 
                if (A[i][j][j]>max){
                    max= A[i][j][j];
                }
        }
            if ( ((max+min)/2.0) <= w ) { return true;}
    }
    return false;   
}