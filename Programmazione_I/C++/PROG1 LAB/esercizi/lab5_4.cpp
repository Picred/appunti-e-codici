/*

Data una sequenza S di valori, una salita è una qualunque sottosequenza di elementi di S consecutivi 
e non-decrescenti. Scrivere un metodo che prenda come parametro 
formale un array S di long e restituisca l’indice del primo elemento della salita più lunga in S.

*/

#include <iostream>
#include <string>

using namespace std;

int foo(long *S, int n){
    int indice=0;
    int n_crescenti=0;
    int max_seq=0;

    for(int i=1; i<n; i++){
        if(S[i]-S[i-1]==0 || S[i]-S[i-1]==1 ){
            n_crescenti++;

                if(n_crescenti>max_seq){
                indice=i-n_crescenti;;
                max_seq=n_crescenti;
                // indice-=n_crescenti; //ricavo indice del primo elemento della salita piu lunga
            } 
        } 

        else{
            n_crescenti=0;
        }
        
    }

    return indice;
}

int main(){
    int n=10;

    long *S=new long[n];

    S[0]=0;
    S[1]=1;
    S[2]=2;
    S[3]=2;
    S[4]=3;
    S[5]=3;
    S[6]=2;
    S[7]=3;
    S[8]=4;
    S[9]=5;

    cout << foo(S,n)<< endl;

    return 0;
}
