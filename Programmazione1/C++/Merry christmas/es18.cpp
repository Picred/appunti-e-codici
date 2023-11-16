/*
Scrivere un metodo che prenda in input una
matrice di puntatori a stringhe M e due numeri short
senza segno, k ed s, e restituisca il numero di colonne
contenenti almeno k stringhe con un numero di lettere
vocali minore di s
*/
#include <iostream>

using namespace std;


int foo(string* **M, int n, int m,unsigned short k, unsigned short s){
    int n_stringhe;
    int vocali;
    int colonne=0;
    //scorro la matrice per colonne
    for(int j=0; j<m; j++){
        n_stringhe=0;
        
        for(int i=0; i<n;i++){
            string elemento= *M[i][j];
            //scorro la stringa in cerca di vocali
            vocali=0;
            for (int t=0; t<elemento.length(); t++){
                if(elemento[t]=='a' || elemento[t]=='A' || elemento[t]=='e' || elemento[t]=='E' || elemento[t]=='i' || elemento[t]=='I' \
                || elemento[t]=='o' || elemento[t]=='O' || elemento[t]=='u' || elemento[t]=='U'){
                    vocali++;
                }
            }
            if (vocali<s){
                n_stringhe++;
            }
        }
        
            if (n_stringhe>=k){
                colonne++;
            }
    }
    return colonne;
}

int main(){

    int n=3;
    int m=2;

    string ***M=new string**[n];
    for (int i=0; i<n; i++){
        M[i]=new string*[m];

    }

    M[0][0]=new string("cuiao");
    M[0][1]=new string("caiiio");

    M[1][0]=new string("fguuuufv");
    M[1][1]=new string("kjy");

    M[2][0]=new string("lkuuuupm");
    M[2][1]=new string("lytirq");

    unsigned short k=2;
    unsigned short s=4;

    cout << foo(M,n,m,k,s);

    return 0;
}

