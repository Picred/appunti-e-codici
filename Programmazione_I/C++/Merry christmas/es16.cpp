/*
Due stringhe si dicono c-equivalenti se esse
risultano uguali dopo aver eliminato da ambedue tutte
le occorrenze del carattere c.
Scrivere un metodo che
prenda in input una matrice A di puntatori a stringhe
ed un carattere c, e restituisca un boolean che indichi
se esistono in A due stringhe c-equivalenti.
*/


#include <iostream>
#include <string>
#define n 3
#define m 2

using namespace std;

bool funzione(string* A[n][m],char c){
    int s=0;

    //elimino tutti i caratteri c da tutte le stringhe
    for (int i=0;i<n;i++){
        for (int j=0; j<m; j++){
            string s1= *A[i][j];
            //scorro i caratteri della stringa
            for (int k=0; k<s1.length()-s; k++){
                if (s1[k] == c){ 
                    (*A[i][j]).erase(k,1);
                    s++;
                }
            }
        }
    }

    //vedo se ci sono stringhe c-equivalenti
    for (int i=0;i<n;i++){
        for (int j=1; j<m; j++){
            string s1= *A[i][j-1];
            string s2= *A[i][j];
            if(s1==s2){
                return true;
            }
        }
    }

    return false;
}

int main(){
    char c='c';

    string *A[n][m];

    A[0][0]=new string("pippasfo");
    A[0][1]=new string("pippo");

    A[1][0]=new string("laptopc");
    A[1][1]=new string("laptop");

    A[2][0]=new string("portaticle");
    A[2][1]=new string("balcone");
    
    cout << funzione(A,c);

    return 0;
}