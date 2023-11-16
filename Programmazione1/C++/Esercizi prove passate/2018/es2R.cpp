/*
Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di 
stringhe palindrome di una delle righe di M.
*/

#include <iostream>
#include <string>

#define n 3
#define m 4

using namespace std;

bool foo(string *M[n][m]){
    //scorro le colonne e cerco quante palidrome ci sono in una colonna
    int pal_col=0; // palindrome colonna

    for (int j=0; j<m; j++){
        pal_col=0;
        for (int i=0; i<n; i++){
            string parola = *M[i][j];
            //verifico se la parola e' palindroma
            // scorro le lettere della parola
            
            int k=0;
            int l=parola.length();

            while (k<parola.length() && k<l){
                if( parola[k] != parola[l] ){
                    break;
                }
                k++; l--;
            } 
            
            if (k>l){ // parola palindroma?
                pal_col++;
            }

        //scorro tutte le righe e la confronto con questa colonna
        //    for (int i=0;)
        }
    }

}