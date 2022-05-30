/*ESERCIZIO:
    Scrivere un programma che sfrutta un metodo "leggiElementi()" per inizializzare un array di double di dimensione non nota
    chiedendo all'utente di inserire un valore per volta fino a quando non viene inserito il valore zero. Successivamente, stampare gli 
    elementi mediante un altro metodo "stampaElementi()".
*/

#include <iostream>

#define MAX_N 100

using namespace std;

void leggiElementi(double vett[], int& dim){
    cout << "Inserire i valori dell'array(max 100 elementi):";
    double el;
    // vett=new double[];
    for(int i=0; i<MAX_N; i++){
        cin >> el;
        if(el!=0){
            vett[i]=el;
            dim++;
        }
        else{
            break;
        }
    }
}


void stampaElementi(double* vett, int dim){
    for(int i=0; i<dim; i++){
        cout << vett[i] << " ";
    }
}

int main(){
    double vett[MAX_N]={0};
    int dim=0;
    leggiElementi(vett,dim);
    // cout << dim;


    stampaElementi(vett,dim);
}