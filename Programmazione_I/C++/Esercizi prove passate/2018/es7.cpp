/*
Scrivere un metodo che prenda in input un parametro formale matrice S di puntatori a carattere di dimensione
n x m, uno short w ed uno short k, e restituisca il valore booleano true se in S sono presenti 

almeno una riga 
ed almeno una colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k.
*/

#include <string>

using namespace std;


bool foo(char***S, int n, int m, short w, short k){
    int nStringhe;
    //scorro per righe la matrice di puntatori a char

    for (int i=0; i<n; i++){
        nStringhe=0;
        for (int j=0; j<m; j++){
            string str = S[i][j]; //inserisco la stringa completa in una nuova variabile
            if(str.length() < k)
                nStringhe++;
            if (nStringhe>=k)
                return true;
            
        }
    }
    //scorro per colonna

        for (int j=0; j<m; j++){
            nStringhe=0;
            for (int i=0; i<n; i++){
                string str = S[i][j]; //inserisco la stringa completa in una nuova variabile
                if(str.length() < k)
                    nStringhe++;
                if (nStringhe>=k)
                    return true;
                
            }
        }

    return false;

}