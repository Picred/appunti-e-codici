/*
Scrivere un metodo che prenda in input un parametro formale matrice S di puntatori a carattere di dimensione
n × m, uno short w ed uno short k, e restituisca il valore booleano true se in S sono presenti almeno una riga ed almeno una
colonna che presentano ciascuna almeno w stringhe di lunghezza minore di k.
*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

bool foo(char* S[n][m],short w, short k){
    int cont_riga=0;
    int cont_colonna=0;
    int n_caratteri;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                //conto i caratteri della stringa
                n_caratteri=0;
                for (int p=0; p < (*(S[i][j]).length()); p++) { //ERRORE
                    n_caratteri++;
                }
                //confronto elementi della riga
                if ( n_caratteri < k){
                    cont_riga++;
                } else {
                    continue;
                }
                if (cont_riga >= w){
                    return true;
                }

                //confronto elementi della colonna invertendo [i][j]con[j][i]
                 if ( n_caratteri < k){
                    cont_colonna++;
                } else {
                    continue;
                }
                if (cont_colonna >= w){
                    return true;
                }
                
            }
        }
        return false;
}

