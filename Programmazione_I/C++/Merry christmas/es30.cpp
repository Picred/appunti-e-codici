/*
Scrivere un metodo che prenda in input una
matrice di stringhe A e due numeri short senza segno,
k ed s, e restituisca il valore booleano true se esiste
almeno una riga di A contenente almeno k stringhe
ognuna contenente un numero di lettere maiuscole
minore di s
*/
#include <iostream>
#include <cctype>
#include <string>

#define n 2
#define m 3

using namespace std;

bool foo(string A[n][m], unsigned short k, unsigned short s){
    int maiuscole;
    int n_stringhe=0;
    //scorro le righe
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            maiuscole=0;
            //scorro i caratteri delle stringhe
            string str=A[i][j]; //metto la stringa in una variabile
            for (int p=0; p<str.length(); p++){
                if ( isupper(str[p]) >0 ){ // isupper dà un numero >0 se tale carattere è maiuscolo, altrimenti 0
                    maiuscole++;
                }
            }
            if (maiuscole < s ){
                n_stringhe++;
            }
        }
    }
    if (n_stringhe >= k){
        return true;
    }
    return false;
}

int main(){
    string A[n][m]= { {"AA","SS","dvaSG"},
                      {"AA","AA","ekGWkcj"}};
    unsigned short k=2; //almeno k stringhe con 
    unsigned short s=2; //meno di s maiuscole

    cout << foo(A,k,s);

    return 0;
}