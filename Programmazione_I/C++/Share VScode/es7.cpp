/*
7.Scrivere un metodo che prenda in input un 
parametro formale matrice A di puntatori ad interi di 
dimensione nxm, due double d1 e d2 ed uno short s, e 
restituisca il numero di colonne di A nelle quali 
esistano almeno s coppie di elementi contigui (ES: 
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il 
secondo elemento sia compreso tra d1 e d2. NB: Si 
assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A.

    *1   2   5
    *4   4   4   
    *2   2   5
    *6   4   4  


*/

#include <iostream>
#define n 3
#define m 2

using namespace std;

int n_colonne(int* A[n][m], double d1, double d2, short s){
    int counter;
    int n_colonne=0;
    int x=0;

    double rapporto;
    
    
    for(int j=0;j<m;j++){
        counter=0;

        for(int i=0;i<n;i++){
            x = i+1;

            if(x < n){
            rapporto = static_cast <double> (*A[i][j]) / (*A[x][j]);
            } 
            
           /* //debug
            cout << "\n\n";
            cout << *A[i][j] << "\t" << *A[x][j]<<endl;;
            cout << "rapporto[" << i << "]:" <<rapporto << endl;*/


            if (rapporto > d1 && rapporto < d2){
                counter++;
            } 
            else 
                break;
            
            if (counter >= s ){
                n_colonne++;

                break;
            }
        }
    }

    return n_colonne;
}

int main(){

    int *P[n][m];

    /*int*  M[n][m]={ {9, 4},
                      {5, 2},
                      {1, 5} };  */

    P[0][0] = new int(9);
    P[0][1] = new int(4);
    P[1][0] = new int(5);
    P[1][1] = new int(2);
    P[2][0] = new int(1);
    P[2][1] = new int(5);     

    double d1=0.9;
    double d2=200.9;

    short  s=3;

    cout<<n_colonne(P,d1,d2,s)<<endl;

}