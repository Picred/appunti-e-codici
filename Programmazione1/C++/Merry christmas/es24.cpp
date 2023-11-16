/*
Scrivere un metodo che prenda in input una 
matrice di stringhe S di dimensioni n m, uno short k, 
ed una stringa w. Il metodo restituisca il valore 
booleano true se esiste almeno una riga in S tale che 
la stringa w sia sottostringa di un numero di stringhe 
della riga stessa che sia minore o uguale a k.
*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

bool fun(string S[n][m], short k, string w){
    int counter;

    for(int i=0;i<n;i++){
       counter=0;
       
        for(int j=0;j<m;j++){
            if((S[i][j]).find(w)!=string::npos){
                counter++;
            }
        }
        if(counter<=k)
            return true;
    }

    return false;
    
}

int main(){

    string S[n][m];
    string w="ao";
    short k= 2;
    
    S[0][0]="ciao";
    S[0][1]="aol";
    S[0][2]="aosk";

    S[1][0]="42gbao";
    S[1][1]="ewfgaob";
    S[1][2]="rwgaohb";

    cout << fun(S,k,w);
    
    return 0;
}