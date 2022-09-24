/*
Scrivere un metodo che prenda in input un parametro formale 
matrice A di puntatori ad interi di dimensione nxm, due double d1 e d2 
ed uno short s, e restituisca il numero di colonne di A nelle quali esistano
almeno s coppie di elementi contigui (ES: A[1][1] e A[2][1]) tali che il 
rapporto tra il primo ed il secondo elemento sia compreso tra d1 e d2.  
NB: Si assuma a priori che s<=n-1 e che d1 < d2. Si presti attenzione ai 
numeri "mancanti"nella matrice A.
*/

#include <iostream>

using namespace std;

#define n 3
#define m 2

int funzione(int* A[n][m],double d1, double d2, short s){
    int n_colonne;
    // bool coppie=false;
    double rapporto=0.0;
    int n_coppie;

    //scorro le colonne aumentando le righe
    for(int j=0;j<m;j++){
        n_coppie=0;
        n_colonne=0;
        for (int i=0;i<n;i++){
            int el_attuale= *A[i][j];
            //controllo se il successivo è fuori matrice
            if (i+1 == n){
            break;
            }
            int el_successivo= *A[i+1][j];
            //calcolo il rapporto

            rapporto= el_attuale/static_cast<double>(el_successivo);
            //rapporto compreso fra d1 e d2?
            if (rapporto>d1 && rapporto<d2){
                n_coppie++;
                n_colonne++;
            }  
            //ci sono s coppie che soddisfano la condizione?
            if(n_coppie>=s)
                return n_colonne;
        }
    }
    return n_colonne;
}

int main(){ //TEST FUNZIONE
    int*A[n][m];
    int c=1;
    //inizializzo i puntatori
A[0][0]=new int(6);
A[0][1]=new int(30);
A[1][0]=new int(3);
A[1][1]=new int(15);
A[2][0]=new int(3);
A[2][1]=new int(3);
    
    //stampo la matrice di puntatori
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << *A[i][j] << " ";
            }
        cout << endl;
        }

    int colonne=0;
    double d1=2.0;
    double d2=4.0;
    short s=2;

    colonne=funzione(A,d1,d2,s);
    cout << colonne;

    return 0;
}