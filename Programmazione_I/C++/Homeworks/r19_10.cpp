/*
Definire una funzione che prende in input due array
monodimensionali di short v1 e v2 della stessa lunghezza. La
funzione restituisce un array di identica lunghezza in cui il generico
elemento di posto i contiene il numero max(v1[i],v2[i]).
*/
#include <iostream>

using namespace std;

short foo(short v1[], short v2[], int dim);

int main(){
    int dim=5;
    short v1[dim]={2,6,1,0,10};
    short v2[dim]={3,8,0,11,20};
    short v3[]={};

    v3=foo(v1,v2,dim);

    for (int i=0; i<5; i++){
        cout << v3[i];
    }
}

short foo(short v1[], short v2[], int dim){
    short v3[dim]={};

    for (int i=0; i<dim; i++){
        if(v1[i]>v2[i]){
            v3[i]=v1[i];
        } else {
            v3[i]=v2[i];
        }
        cout << v3[i] << " ";
    }
    return v3;
}