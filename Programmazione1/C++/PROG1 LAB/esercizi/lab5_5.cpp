/*

Scrivere un metodo che prenda come parametri formali una matrice A 
di stringhe ed uno short w, e restituisca in output un bool che indichi 
se esiste una riga di A in cui siano presenti almeno due stringhe in cui i primi w caratteri 
dell’una siano uguali agli ultimi w caratteri dell’altra (nello stesso ordine).

*/

#define n 2
#define m 3

#include <iostream>
#include <string>
using namespace std;

bool foo(string A[n][m], short w){
    
    //scorro per riga
    for(int i = 0; i < n; i++){
        for ( int j = 0; j<m; j++){
            string attuale= A[i][j];
            //per ogni stringa devo scorrere le successive stringhe
                for(int k=j+1; k<m;k++){
                    // A[i][j]=stringa attuale ------ A[i][k]=stringa successiva
                    string successiva=A[i][k];

                        if(attuale.substr(0,w) == successiva.substr( successiva.length()-w, w) )
                            return true;
                }
        }
    }
    return false;

}


int main(){

    int w = 2;
    string A[n][m] = {  {"ciaoaos","porcoc","lunedi"},
                        {"esame","ctitjnj","lolesct"} };

    cout << foo(A,w) << endl;

    return 0;

}
