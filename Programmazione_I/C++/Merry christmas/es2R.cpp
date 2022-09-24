/*
Due stringhe si dicono sorelle se hanno lo stesso numero di vocali. 
Scrivere un metodo che prenda in input una matrice A di puntatori a stringhe, e restituisca un boolean che indichi se esiste una
colonna di A in cui sono puntate almeno due stringhe sorelle.
*/
#include <iostream>
#include <string>

using namespace std;

bool sorelle(string ***A, int n, int m){
    //sorelle==stesso numero di vocali
    //visito la matrice di puntatori e valuto il contenuto di esse
    
    // bool verifica=false;
    int vocali_s1;
    int vocali_s2;
    for (int j=0; j<m; j++){
        for (int i=0; i<n; i++){
            string s1= *A[i][j];
            //scorro i caratteri della stringa
            vocali_s1=0;
            for (int k=0; k<s1.length(); k++){ //vedo quante vocali ho nella stringa attuale
                if(s1[k]=='a' || s1[k]=='A' || s1[k]=='e' || s1[k]=='E' || s1[k]=='i' || s1[k]=='I' || s1[k]=='o'|| s1[k]=='O' || s1[k]=='u' || s1[k]=='U'){
                    vocali_s1++;
                }
            }
            //confronto la stringa attuale con le successive
            
            for (int q=i+1; q<n; q++){
                string s2 = *A[q][j];
                vocali_s2=0;
                //scorro i caratteri di s2 e vedo le vocali
                for (int u=0; u<s2.length(); u++){
                    if (s2[u]=='a' ||s2[u]=='A' ||s2[u]=='e' ||s2[u]=='E' ||s2[u]=='i' ||s2[u]=='I' ||s2[u]=='o' ||s2[u]=='O' ||s2[u]=='u' ||s2[u]=='U'){
                        vocali_s2++;
                    }
                    if (vocali_s1==vocali_s2){
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

int main(){
    //inizializzo dinamicamente la matrice di puntatori a stringhe da passare alla funzione
    int n=3;
    int m=3;

    string ***A=new string**[n];
    for (int i=0; i<n; i++){
        A[i]=new string*[m];
        for (int j=0; j<m; j++){
            A[i][j]=new string[255];
        }
    }
    *A[0][0]="taaa";
    *A[0][1]="tevb";
    *A[0][2]="hsg";

    *A[1][0]="ts";
    *A[1][1]="te";
    *A[1][2]="ffvuu";

    *A[2][0]="tr";
    *A[2][1]="ptrz";
    *A[2][2]="vvvu";
    //stampa errata
    cout << "Ci sono almeno 2 stringhe sorelle? " << sorelle(A,n,m);
}