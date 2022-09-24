/*
19.10
Un santone induista si trova nella regione indiana del
Rajasthan, quest'ultima simulata con una matrice
quadrata di boolean in cui il valore true indica la
presenza di un libro sacro. 
Scrivere un metodo che
prenda in input una matrice di boolean e restituisca il
numero di libri raccolti dal santone che, partendo dal
centro della regione, esegue un movimento casuale
unitario alla volta in una delle quattro direzioni prima
che egli sia traviato dalle usanze oltre colonne. 
*/ 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 3 //dimensioni della matrice quadrata

int libri_raccolti(bool campo[N][N]);

int main (){
    int libri=0;
    bool campo[N][N]={};

    libri = libri_raccolti(campo);
    cout << libri;
}

int libri_raccolti(bool campo[N][N]){
    srand (time(0));

    bool bulean;

            for (int i=0; i<N; i++){
                for (int j=0; j<N; j++){
            
            int numero_casuale = rand()%4;            
            
            if(numero_casuale<=2){
                bulean=true;
            } 
            else {bulean=false;}        
            
                campo[i][j]=bulean;
                cout << campo[i][j] << " ";
                } cout << endl;
            }
    // ricavo posizione centrale
    int o = N/2;
    int c = N/2;
    int libri=0;
    // al centro c'è già true?
    if (campo[o][c]==true){
        libri++;
    }

    int numero_casuale;
            while ( o<N && o>=0 && c<N && c>=0 ){
                    numero_casuale = rand()%4;
                
                if (numero_casuale==0)
                    o--;
                if (numero_casuale==1)
                    c++;
                if (numero_casuale==2)
                    o++;
                if (numero_casuale==3)
                    c--;
                
                if (campo[o][c]==true){
                    campo[o][c]==false;
                    libri++;
                }
                cout << "Posizione [" << o << "][" << c << "]" << endl;  
                cout << "libri:" << libri << endl;  
            }
    cout << "Sei stato traviato oltre colonna" << endl;
    return libri;
}