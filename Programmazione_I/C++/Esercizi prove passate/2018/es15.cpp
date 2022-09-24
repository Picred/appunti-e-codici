/*
Scrivere un metodo che preveda due parametri formali: 
una matrice A di stringhe ed una matrice B di short, entrambe di
dimensioni n x m. 

Il metodo restituisca uno array di n puntatori 
a stringhe nel quale il generico elemento di indice i sará uguale
alla concatenazione delle sole stringhe della riga i-esima di A 
che hanno lunghezza pari o maggiore del corrispondente numero
in B.
*/
#include<string>
using namespace std;

#define n 5
#define m 6

string** foo(string A[n][m], short B[n][m]){
    string** Ret= new string*[n];
    string parola="";
    string* ptr;

    for (int i=0; i<n; i++){
        parola="";
        for (int j=0; j<m; j++){
            if(A[i][j].length() >= B[i][j]){
                parola+=A[i][j];
            }
        }
        ptr= &parola;
        if (parola.length() > 0)
            Ret[i]=ptr;
        else
            Ret[i]=nullptr;
    }
    return Ret;
}