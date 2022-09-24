/*
Scrivere un metodo che prenda in input un parametro formale array A di interi 
di dimensione k × n × n ed un double w, e restituisca il valore di verità true 
se esiste un valore dell'indice relativo alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il 
valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w.
*/
#include <iostream>

using namespace std;

bool foo(int ***A, int k, int n, double w);

int main(){
    
    //int A[3][2][2]={1,2,3,4,5,6,7,8,9,10,11,12};
    int c = 1;
    int ***A = new int**[3];
    for(int i=0; i<3; i++) {
        A[i] = new int*[2];
        for (int j=0; j<3; j++){
            A[i][j] = new int[2];
            for(int k=0; k<3; k++) {
                A[i][j][k] = c++;
            }
        }
    }
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

        cout << "k= " << i << endl; 

        for(int p=0; p<n; p++) {
            for(int q=0; q<n; q++) {
                cout << A[i][p][q] << "\t";
            }
            cout << endl;
        }

        for (int j=0; j<n; j++){
                
                if (A[i][j][j]<min){
                    min=A[i][j][j];
                } 
                if (A[i][j][j]>max){
                    max=A[i][j][j];
                }
        }
            if ( ((max+min)/2.0) <= w ) { return true;}
    }
    return false;   
}