/*
Scrivere un metodo che prenda in input una matrice quadrata di puntatori a stringhe Q ed una stringa s. 
Il metodo restituisca il valore booleano true se e solo se il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, e maggiore del numero di stringhe che contengono s presenti nella diagonale secondaria di Q.
*/

#include <iostream>
#include <string>

#define n 3
using namespace std;


bool foo(string* Q[n][n], string s){
    int str_principale=0;
    int str_secondaria=0;

    //scorro la diagonale principale
    for (int i=0; i<n; i++){
        if( (*Q[i][i]).find(s) != string::npos){
            str_principale++;
        }
    }
    //scorro la diagonale secondaria
    for (int i=0; i<n; i++){
            if( (*Q[i][n-1-i]).find(s) != string::npos){
                str_secondaria++;
            }
  
    }
    
    if(str_principale > str_secondaria){
        return true;
    } else{
        return false;
    }
}

int main(){
    string* Q[n][n];

    Q[0][0]=new string("cap");
    Q[0][1]=new string("ca");
    Q[0][2]=new string("cap");

    Q[1][0]=new string("ca");
    Q[1][1]=new string("cap");
    Q[1][2]=new string("ca");
    
    Q[2][0]=new string("ca");
    Q[2][1]=new string("ca");
    Q[2][2]=new string("cap");

    string s="cap";

    bool esiste;

    esiste=foo(Q,s);
    cout << esiste;

    return 0;
}