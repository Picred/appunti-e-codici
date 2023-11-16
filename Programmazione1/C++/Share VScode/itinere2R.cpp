/*
Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe A di
dimensioni n × m, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s `e sottostringa di almeno k stringhe della
riga i-esima della matrice A.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define n 3
#define m 2

bool *func(string* A[n][m],short k,string s){
    bool *array=new bool[n];
    int corrispondenze;
    string *ptr=nullptr;
    string *temp=NULL;
    bool check;
    //fisso la riga e scorro le righe variando le colonne
    for (int i=0; i<n; i++){
        corrispondenze=0;
        for (int j=0; j<m; j++){
            // *temp = A[i][j];
        temp= A[i][j].find(s); // ERRORE
            // if(ptr!=string::npos){
            //     corrispondenze++;
            // }
        }
        if (corrispondenze >= k){
            array[i]=true;
        }
    }
    return array;
}










// bool *func(***A,short k,string s){
//     bool *array=new bool[n];
//     for(int i=0;i<n;i++){
//         int counter =0;
//         for(int j=0;j<;j++){
//             int found=A[i][j].find(s);
//             if(found>=0){
//                 counter++;
//             }
//             else{}
//         }
//         if(counter>=k){
//             *array=true;
//         }
//         return *array;
//     }

// }

// int main(){

// }