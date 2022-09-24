/*
Scrivere un metodo che preveda un parametro formale matrice di char di dimensione n x m ed un ulteriore
parametro intero a, e restituisca il valore booleano true se esiste almeno una riga o una colonna che 
contiene almeno 'a' caratteri
che siano tutti minuscoli o tutti maiuscoli e che abbiano posizioni adiacenti.
NB: Si assuma che la matrice contenga solo caratteri
corrispondenti alle lettere dell'alfabeto.
*/
#include<cctype>
#include<string>
using namespace std;

bool foo(char** A,int n, int m, int a){
    int cont; //conta il numero di caratteri adiacenti minuscoli OPPURE maiuscoli
    //scorro per righe
    for (int i=0; i<n; i++){
        cont=1;
        for (int j=0; j<m; j++){
            char c = A[i][j];
            for (int k=0; k<m; k++){ // ogni carattere della matrice va confrontato con i successivi adiacenti
                if ( (isupper(c) && isupper(A[i][k])) || (islower(c) && islower(A[i][k])) ){
                    cont++;
                
                    if (cont>=a){
                        return true;
                    }
                } else {
                    break; //se uno é maius e uno e minus, non ha senso continuare a ciclare i char successivi
                }
            }
        }
    }

    //scorro per colonna
    for (int j=0; j<m; j++){
        cont=1;
        for (int i=0; i<n; i++){
            char c = A[i][j];
            for (int k=0; k<n; k++){ // ogni carattere della matrice va confrontato con i successivi adiacenti
                if ( (isupper(c) && isupper(A[k][j])) || (islower(c) && islower(A[k][j])) ){
                    cont++;
                
                    if (cont>=a){
                        return true;
                    }
                } else {
                    break; //se uno é maius e uno e minus, non ha senso continuare a ciclare i char successivi
                }
            }
        }
    }
    return false; //se fino a qui non é stato ritornato vero vuol dire che non ci sono corrispondenze
}
