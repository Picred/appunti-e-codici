/*
Scrivere un metodo che prenda in input una matrice A di stringhe ed una stringa Str,
 e restituisca un boolean che indichi se Str è sottostringa di tutte le stringhe 
 presenti in una qualche colonna di A.
*/

#include<string>
#include<iostream>
using namespace std;

#define n 2
#define m 4

bool foo(string A[n][m],string Str){
    //devo scorrere per colonna e vedere se str è sottostringa di tutta UNA colonna
    for(int j=0; j<m; j++){
        bool found=true;
        for(int i=0; i<n && found; i++){
            if(A[i][j].find(Str)==string::npos){
                found==false;
            }   
        }
        if(found)
            return found;
    }
    return found;
}