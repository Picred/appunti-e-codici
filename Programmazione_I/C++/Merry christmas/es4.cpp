/*
Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni nm, due short a
e b, ed una stringa s. Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna
stessa. PS: Si assuma 0 < a b < n. 
*/

#include <iostream>
#include <string>

#define n 3
#define m 3

using namespace std;

bool foo(string* P[n][m], short a, short b, string s){
    
    int contatore=0;

        for (int j=0; j<m; j++){
            for (int i=0; i<n; i++){

                // sono in posizione [i] [j] che contiene un indirizzo
                // cout << "contatore=" << contatore << endl;
                if ( (*P[i][j]).find(s) < (*P[i][j]).length()-1 )
                    contatore++;

                // cout << "contatore dopo ++ =" << contatore << endl;
   
                if (contatore>=a && contatore <=b)
                    return true;    
            }
            contatore=0;
        }
    return false; // errore, non ritorna false
}


int main(){ //test funzione
    string* P[n][m];

    P[0][0]=new string("ciao");
    P[0][1]=new string("cane");
    P[0][2]=new string("gatto");

    P[1][0]=new string("caoi");
    P[1][1]=new string("topone");
    P[1][2]=new string("pippo");
    
    P[2][0]=new string("tao");
    P[2][1]=new string("ness");
    P[2][3]=new string("aabbcc");
    
    short a=4; short b=10; string s="zxc";

    bool check = foo(P,a,b,s);
    cout << check;

    // return 0; //errore non stampa il falso
}