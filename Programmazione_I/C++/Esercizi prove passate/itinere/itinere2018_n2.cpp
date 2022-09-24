/*
Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe A di
dimensioni n × m, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s `e sottostringa di almeno k stringhe della
riga i-esima della matrice A
*/
#include<string>
#define m 5
#define n 4
using namespace std;


bool* foo(string* A[n][m], short k, string s){
    bool *ret=new bool[n];

    short counter;

    for(int i=0; i<n;i++){
        counter=0;
            for(int j=0;j<m; j++){
                if( A[i][j]->find(s) != string::npos){
                    counter++;
                }
            }
            if(counter>=k){
                ret[i]=true;
            } else {
                ret[i]=false;
            }
    }
    return ret;
}