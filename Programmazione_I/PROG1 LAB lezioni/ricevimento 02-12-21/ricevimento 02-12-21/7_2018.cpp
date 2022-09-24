/*
Scrivere un metodo che prenda in input un parametro formale matrice S 
di puntatori a carattere di dimensione
n × m, uno short w ed uno short k, e restituisca il valore booleano 
true se in S sono presenti almeno una riga ed almeno una
colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k.
*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

bool foo(char* S[n][m],short w, short k){
    int cont_riga=0; //numero di righe che soddisfano la condizione
    int cont_colonna=0;
    int n_caratteri;

    // contare le righe che soddisfano la condizione
    for (int i=0; i<n; i++){
        int cont_stringhe=0;
        for (int j=0; j<m; j++){
            //conto i caratteri della stringa
            n_caratteri=0;
            while(S[i][j][n_caratteri]!='\0')
                n_caratteri++

            //confronto elementi della riga
            if ( n_caratteri < k){
                cont_stringhe++;
            }
        }
        if(cont_stringhe>=w) {
            cont_riga++;
            break;
        }
    }

    if(cont_riga==0)
        return false;
            
    // contare le righe che soddisfano la condizione
    for (int j=0; j<m; j++){
        int cont_stringhe=0;
        for (int i=0; i<n; i++){
            //conto i caratteri della stringa
            n_caratteri=0;
            while(S[i][j][n_caratteri]!='\0')
                n_caratteri++;

            //confronto elementi della riga
            if ( n_caratteri < k){
                cont_stringhe++;
            }
        }
        if(cont_stringhe>=w) {
            cont_colonna++;
            break;
        }
    }

    if(cont_colonna==0)
        return false;

    return true;    
}

