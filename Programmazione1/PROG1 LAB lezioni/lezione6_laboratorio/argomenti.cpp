#include<iostream>

using namespace std;

int main(int argc, char *argv[]) {
    //argc sarà uguale al numero di argomenti specificati
    //argv[] è un vettore di stringhe (intese come char*)
    //contenenti i valori dei parametri
    
    //questo ciclo scorre e stampa gli argomenti
    for(int i=0; i<argc; i++)
        cout << "Argomento #"<<i<<": "<<argv[i]<<endl;
}