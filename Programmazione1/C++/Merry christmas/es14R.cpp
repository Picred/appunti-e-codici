/*
Scrivere un metodo che prenda come parametri
formali una matrice A di stringhe ed un intero k, e
restituisca in output una copia di A in cui tutte le
stringhe della colonna k-esima siano state epurate
dalle lettere non italiane. 
*/

#include <iostream>
#include <string>

using namespace std;
#define n 3
#define m 3

string** foo(string A[n][m],int k){
    string**S=new string*[n];
    //inizializzo matrice da restituire
    
    for(int i=0;i<n;i++){
        S[i]=new string[m];
        for (int j=0; j<m; j++){
            S[i][j]="";
        }
    }

    string C="abcdefghilmnopqrstuvzABCDEFGHILMNOPQRSTUVZ";
    //scorro la matrice
        for(int i=0;i<n;i++){
            string stringa=A[i][k];
            //scorro la stringa
            // for (int p=0; p<stringa.length();p++){
            int len=stringa.length();
            int p=0;
            do{
                   if(C.find(stringa[p])==string::npos){
                    //    cout<<p;
                        stringa.erase(p,1);
                        len--;
                        A[i][k]=stringa;
                    }
                    
                    p++;
                   
            } while(p<len);
        }
        //inizializzo la nuova matrice S
        for (int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                S[i][j]=A[i][j];
            }
        }
        return S;
}



int main(){
    
    string **S;
    int k=2; //indice colonna interessata
    string A[n][m]={{"porco",       "dio",      "orkkso"},
                    {"cutejjo",     "orso",     "orkso"},
                    {"farinejja",   "kazzo",   "jeansks"} };
    S=foo(A,k);
    // osephine , orso , eanss
    for(int i=0;i<n;i++){

         for(int j=0;j<m;j++){
                cout<<S[i][j]<<" ";
         }
         cout<<endl;
    }

    //non cancella le lettere straniere vicine fra loro, ma cancella quelle che distano di almeno 2 posti fra loro.

    return 0;
}