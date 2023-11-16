/*
Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S di dimensioni n × n di puntatori a interi
senza segno, un double w ed uno short k (si assuma k < n). 
Il metodo restituisca il valore booleano true se esistono almeno k
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi della colonna stessa sia minore o uguale a
w. NB: si presti attenzione ai numeri mancanti.
*/



bool foo(unsigned int*** S,int n, double w, short k){
    int counter;
    //scorro per colonna
    for (int j=0; j<n; j++){
        double media=0.0;
        counter=0;
        for(int i=0; i<n; i++){
            if(S[i][j]!=nullptr){
                media+=(double)(*(S[i][j]));
            }
        }
        if( (media/n) <= w)    
            counter++;
        if(counter>=k){
            return true;
        }
    }
    return false;
}

/*
Scrivere un metodo che prenda in input una matrice A di stringhe di dimensioni n × m ed una matrice B di puntatori a
stringhe di dimensioni m × l. Il metodo restituisca un vettore di booleani C di dimensione l in cui 
cj = true se e solo se `e
possibile trovare almeno una stringa, nella colonna j −esima di B (sia bkj ), la quale sia sottostringa della corrispondente stringa
presente nella riga j − esima di A (sia ajk). Si assuma n ≥ l. NB: si presti attenzione alle stringhe mancanti in B.
*/

#include <string>
using namespace std;

#define n 4
#define m 6
#define l 2

bool* foo2(string A[n][m],string* B[m][l]){
    bool* C=new bool[l];

    //scorro per colonne B e, invertendo j e i scorro per righe A
    for(int j=0; j<l; j++){
        for(int i=0; i<m; i++){
            if(B[i][j] != nullptr){ //Punta a qualcosa?
                if(A[j][i].find(*(B[i][j]) ) != string::npos){ //A[j][i] perchè A si deve scorrere per riga e non per colonna come B
                    C[j]=true;
                    break;
                }
            }
        }
    }
    return C;
}