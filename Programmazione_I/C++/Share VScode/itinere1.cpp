/*
Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × n ed
un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per cui il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale
di A sia maggiore di w.
*/
#include <iostream>

using namespace std;

#define n 3

bool funzione(int A[n][n], double w){
    
    bool check=false;
    double somma_colonna;
    double somma_diagonale=0.0;
    double rapporto=0.0;

        //sommo gli elementi della diagonale
        for (int i=0; i<n; i++){
            somma_diagonale+=A[i][i];
        }
        
    //sommo gli elementi della stessa colonna
    for (int j=0; j<n; j++){
        somma_colonna=0.0;
        for (int i=0; i<n; i++){
            somma_colonna+=A[i][j];
            } 
    rapporto = (somma_colonna/somma_diagonale);
    cout << endl << "rapporto:" << rapporto << endl;
        if ( rapporto > w ){
            check= true;
            return check;
        }
    }  
    return check;
}


int main() {
    // TEST DELLA FUNZIONE
    // n=3 
    int Matrice[n][n] = { {2,2,3},
                          {5,6,7},
                          {8,9,12} }; // C1=15 C2=17 C3=22 diagonale=20   c1/som=0.7 c2/som=0.85 c3/som=1.1
    //numero da confrontare
    double p=0.9;
    bool check=false; //si verifica la condizione nella funzione?

    check=funzione(Matrice, p);
    cout << "Il risultato della verifica e': " << check;

    return 0;
}   