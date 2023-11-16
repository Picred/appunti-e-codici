/*
es12 natale!
Scrivere un metodo che prenda come parametri
formali una matrice A di stringhe ed uno short w, e
restituisca in output un bool che indichi 

se esiste una
riga di A in cui siano presenti almeno due stringhe
consecutive in cui i primi w caratteri della prima
stringa siano uguali agli ultimi w caratteri della
seconda stringa (nello stesso ordine).
*/

#include <iostream>
#include <string>

#define n 3
#define m 2

using namespace std;

bool fun(string A[n][m], short w){

    //scorro le righe della matrice
    for (int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            string s1= A[i][j-1];
            string s2= A[i][j];
            string caratteri_s1= s1.substr(0,w);
            string caratteri_s2= s2.substr((s2.length()-w));

            if (caratteri_s1==caratteri_s2){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string A[n][m];

    A[0][0]="aaawwwa";
    A[0][1]="svfda";

    A[1][0]="iiiigerry";
    A[1][1]="svfdaaa";

    A[2][0]="cutello";
    A[2][1]="gmfnh";

    short w=3;
    cout << fun(A,w);

    return 0;
}