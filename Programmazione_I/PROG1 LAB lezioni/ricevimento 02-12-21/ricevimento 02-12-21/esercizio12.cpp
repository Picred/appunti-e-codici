/* Scrivere un metodo che preveda un parametro formale matrice quadrata di 
stringhe di dimensioni n × n, uno short k ed una stringa s, 
e restituisca un array di n puntatori a stringhe in cui il generico 
elemento di indice i puntare alla i-esima stringa della diagonale 
secondaria se questa ha lunghezza maggiore o uguale a k e inizia con la stringa s, 
altrimenti la corrispondente stringa della diagonale principale. */

#include<string>

using namespace std;

//a b c  ->  [0][2]
//d e f  ->  [1][1]
//g h i  ->  [2][0]

//A[i][n-1-i]

#define n 3
string * fun(string A[n][n], short k, string s) {
    string *out = new string[n];

    for(int i=0; i<n; i++) {
        string *sc = &(A[i][n-1-i]);
        if(((*sc).length()>=k) && ((*sc).substr(0,s.length())==s))
            out[i] = sc;
        else
            out[i] = &(A[i][i]);
    }
    return out;
}