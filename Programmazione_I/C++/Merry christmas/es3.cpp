/*
Scrivere un metodo che prenda in input un
parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se
esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna
stessa e la somma degli elementi della diagonale
secondaria di Q sia maggiore di w
*/

#include <iostream>
#define n 3

using namespace std;

bool foo(int Q[n][n], double w){
    double somma_diagonale=0;
    double somma_colonna=0;
    int k=n-1;
    int q=0;
    
    //calcolo somma diagonale
    while (q<n && k>=0){
        somma_diagonale+=Q[q][k];
        
        // cout << somma_diagonale << endl; // debug 1
        
        q++; k--;
        
    }
    //scorro le colonne della matrice Q 
        for (int j=0; j<n; j++){
            somma_colonna=0;
            
            // cout << endl; //debug 2

            for (int i=0; i<n; i++){
                somma_colonna+=Q[i][j];
                
                // cout << somma_diagonale << endl; //debug 2

                if ((somma_colonna/somma_diagonale) > w ){    
                    return true;
                }
            }
        }
    return false;
}

int main(){
    int Q[n][n]={   {8,9,11},
                    {2,0,8},
                    {1,21,5} };
    double w=2.4;
    bool check;
    
    //stampo la matrice
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << Q[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl;
    check=foo(Q,w);
    if(check){
    cout << "Condizione verificata con w=" << w;
    } else {
        cout << "Condizione non verificata con w=" << w; 
    }
}