/*Scrivere un metodo che prenda in input una
matrice M di puntatori a double di dimensione n × m e
due interi a e b e restituisca un array unidimensionale
di booleani di lunghezza 2m tale che 

l’elemento dell’array di posizione 2i contiene True se e solo se la
media dei soli elementi della colonna i-esima di M
compresi tra a e b(estremi inclusi) è maggiore di
(a+b)/2.
Gli elementi dell’array di indice dispari devono 
essere inizializzati a False. NB: Si presti attenzione ai
numeri mancanti!*/

#include <iostream>
#define n 3
#define m 2

using namespace std;

bool* foo(double* M[n][m], int a, int b){
    bool *C=new bool[(2*m)];
    double media=0.0;
    double counter=0.0;
    //inizializzo a false tutti gli elementi di posto dispari dell'array
    for (int i=0; i<(2*m);i++){
        C[i]=false;
        i++;
    } // 0 . 0 . 0 . 0 . 0 ......

    // for (int i=0; i<(2*m);i++){
    //     cout << "array dispari" << C[i] << "i= " << i;
    //     i++;
    // }
    // cout << endl << endl;
    
    
    int indice_array=1;
    for (int j=0; j<m; j++){
        counter=0;
        cout << endl;
        for (int i=0; i<n; i++){
            if ( (*M[i][j])>=a && (*M[i][j])<=b){
                counter+=(*M[i][j]);
            } 
        // cout << "counter= " << counter << endl;
        }
        
        media=static_cast<double>(counter)/n;

        // cout << "media:" << media << endl;
        // cout << "a+b/2:" << (static_cast<double>(a)+b)/2<< endl; 
            
            if(media > ((static_cast<double>(a)+b)/2) ){
                C[indice_array]=true;
            } else {
                C[indice_array]=false;
            }
            indice_array+=2;
    }

    return C;
}

int main(){
    int a=2;
    int b=6;
    double *M[n][m];

    M[0][0]=new double(5.3);
    M[0][1]=new double(5.9);

    M[1][0]=new double(3.1);
    M[1][1]=new double(5.9);

    M[2][0]=new double(5.3);
    M[2][1]=new double(5.4);

    bool *C;

    C=foo(M,a,b);

    //stampo array
    for (int i=0; i<(2*m);i++){
        cout << C[i] << " ";
    }

    return 0;
}