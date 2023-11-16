/*
Scrivere un metodo che prenda in input tre
parametri formali: una matrice di puntatori a stringhe
A di dimensioni nxm, uno short k ed una stringa s. Il
metodo restituisca un array di bool di dimensione n in

cui il singolo elemento di indice i assume valore true se
la stringa s e sottostringa di almeno k stringhe della
riga i-esima della matrice A
*/
#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

bool* foo(string* A[n][m], short k, string s){
    bool *C=new bool[n];
    short n_stringhe;

    for (int i=0; i<n; i++){
        n_stringhe=0;
        for (int j=0; j<m; j++){
            string str= *A[i][j];
            // cout << str;
            if (str.find(s)!=string::npos){
                n_stringhe++;
            }
            
        }
            if(n_stringhe>=k){
                C[i]=true;
            } else {
                C[i]=false;
            }
    }
    return C;
}


int main(){
    bool *C;
    
    string *A[n][m];


    A[0][0]=new string("aoac");
    A[0][1]=new string("aoui");
    A[0][2]=new string("aonvur");

    A[1][0]=new string("bd");
    A[1][1]=new string("pd");
    A[1][2]=new string("lol");

    short k=2; //true s è sottostringa di almeno k stringhe nella stessa riga
    string s="ao";
    
    C=foo(A,k,s);

    cout << "fine" << endl;
    for (int i=0; i<n; i++){
        cout << C[i] << " ";
    }

    return 0;
}