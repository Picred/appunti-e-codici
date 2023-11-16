/*
Due stringhe si dicono simili se esse coincidono in almeno p posizioni, dove p è la metà (troncata) 
della lunghezza della stringa più corta. (Es.: Le stringhe “abcdefabcdef ” e “zbcaafacz” sono simili 
perché coincidono agli indici 1,2,5,6 ed è p=4). 
Scrivere un metodo che prenda in input una matrice A 
di puntatori a stringhe, e restituisca un boolean che indichi se esiste una colonna di A in cui sono 
presenti almeno due stringhe simili.
N.B.: Attenzione alle eventuali stringhe mancanti in A (con puntatore a null).
*/

#define n 3
#define m 4
#include <string>
#include <iostream>

using namespace std;


bool foo(string* A[n][m]){

    int p=0;

    for (int j=0; j<m;j++){
        for(int i=1;i<n;i++){
            string s1=*A[i][j];
            for(int k=i-1;k>=0;k--){
                if (A[i][j] && A[k][j]){
                    string s1=*A[k][j];
                    if(s2.length() >= s1.length()){
                        p=s1.length()/2; //troncamento implicito
                        int lunghezza =  s1.length();
                    } else {
                        p=s2.length()/2; //troncamento implicito
                        int lunghezza =  s2.length();
                    }
                    int counter=0;
                    for(int l=0; l<lunghezza;l++){
                        if(s1[l]==s2[l]){
                            counter++;
                        }
                    }
                    if(counter>=p){
                        return true;
                    }
                }
            }  
        }
    }
    return false;
}

int main(){

    // string *A[n][m];

    string*** A=new string**[n];

    for(int i=0;i<n;i++){
        A[i]=new string*[m];
    }

    *A[0][0] = "ttabr";
    *A[0][1] = "atraatt";
    *A[0][2] = "bbaap";
    *A[0][3] = "ataratat";

    *A[1][0] = "att";
    *A[1][1] = "tr";
    *A[1][2] = "spqr";
    *A[1][3] = "atatar";

    *A[2][0] = "ttr";
    *A[2][1] = "rrtr";
    *A[2][2] = "aprt";
    *A[2][3] = "rtar";

    cout << foo(A) << endl;

    //non compila
}