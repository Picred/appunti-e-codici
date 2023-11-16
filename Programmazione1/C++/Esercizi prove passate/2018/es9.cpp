/*
Scrivere un metodo che prenda in input un parametro formale A matrice di stringhe di dimensione n x m,
ed una stringa s. Il metodo restituisca true se esistono almeno due stringhe in A che contengono 
la stringa s e che abbiano differenti indici di riga e di colonna.
*/
#include<string>

using namespace std;

#define n 3
#define m 4

bool foo(string A[n][m], string s){
    int nStringhe;
    int x,y; // due nuovi indici che memorizzano dove é stata trovata la corrispondenza
    //scorro la matrice

    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if (j!=y){ //non confronto la i con la x perché la i aumenterá in ogni caso, quindi sará sempre diversa
                if( A[i][j].find(s) != string::npos){
                    x=i; y=j;
                    nStringhe++;
                    break;
                }
            }
        }   
    }
    if(nStringhe>=2)
        return true;
    else      
        return false;
}