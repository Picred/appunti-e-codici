/*
Scrivere un metodo che prenda in input una
matrice di puntatori a stringhe S di dimensioni n×m,
una stringa x ed un array di double W di dimensione
m; il metodo restituisca un array di bool R di
dimensione m tale che 

l’i-esimo elemento di R sarà
true se e solo se il rapporto tra il numero di stringhe
della i-esima colonna di S delle quali x è sottostringa
ed il numero n è minore o uguale dello i-esimo
elemento di W. NB: Si presti attenzione alle stringhe
mancanti! 
*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;


bool* foo(string* S[n][m], string x, double W[m]){
    bool *R=new bool[m];

    int n_stringhe;
    double rapporto=0.0;
    //scorro le colonne di S
    int i;
    int k=0;
    for (int j=0; j<m; j++){
        n_stringhe=0;
        for (i=0; i<n; i++){
            string s=*S[i][j];
            if(s.find(x)!=string::npos){
                n_stringhe++;
            }
        
        }
        rapporto=static_cast<double>(n_stringhe)/n;
        if(rapporto<=W[j]){
            R[j]=true;
        } else {
            R[j]=false;
        }
    }
    return R;
}

int main(){
    string *S[n][m];

    double W[m];

    S[0][0] = new string ("ao");
    S[0][1] = new string ("ccc");
    S[0][2] = new string ("dd");

    S[1][0] = new string ("ao");
    S[1][1] = new string ("ff");
    S[1][2] = new string ("gg");

    string x = "ao";

    W[0]=0;
    W[1]=2;
    W[2]=0;

    bool *R = foo(S,x,W);

    for(int i=0;i<m;i++)
        cout << R[i] <<" ";

    return 0;
}