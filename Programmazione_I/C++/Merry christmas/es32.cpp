/*
Scrivere un metodo che prenda in input una
matrice quadrata di puntatori a stringhe e due caratteri
c1 e c2. Calcolare O1 come numero di occorrenze del
carattere c1 che figurano nella diagonale principale.
CalcolareO2 come numero di occorrenze del carattere
c2 che che figurano nella secondaria. Restituire il
rapportoO1/O2. NB: si faccia attenzione alle stringhe
mancante
*/

#include <iostream>



using namespace std;

#define n 3

double foo(string* A[n][n],char c1, char c2){
    int O1=0; //occorrenze di c1 nella principale
    int O2=0; //occorenze di c2 nella secondaria
    //scorro le diagonali
    for (int i=0, j=n-1; i<n , j>=0; i++){
        auto found_principale = (*A[i][i]).find(c1);
        if(found_principale!=string::npos){
            O1++;
        }
        auto found_secondaria= (*A[i][j-i]).find(c2);
        if (found_secondaria!=string::npos){
            O2++;
        }
    }
    double rapporto = static_cast<double>(O1)/O2;

    return rapporto;
}

//CONTROLLARE 
int main(){
    // int n=3;

    string *A[n][n];

    A[0][0]=new string("kaka"); //principale //a=2
    A[0][1]=new string("vmfdovmi");
    A[0][2]=new string("bbb"); //secondaria b=3 

    A[1][0]=new string("porco");
    A[1][1]=new string("aaanjifbbb"); //principale a=3 //secondaria b=3
    A[1][2]=new string("mis");

    A[2][0]=new string("lolb"); //secondaria b=1
    A[2][1]=new string("casa");
    A[2][2]=new string("lola"); //principale a=1
    // O1= a = 4 O2=b=7  O1/O2=0.85
    char c1='a';
    char c2='b';
    
    double rapporto=foo(A,c1,c2);
    cout << "rapporto=" << rapporto;
}