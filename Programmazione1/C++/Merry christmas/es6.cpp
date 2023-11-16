/*
Scrivere un metodo che prenda come parametro formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le desinenze di due caratteri delle stringhe 
sulla faccia superiore del cubo C.
*/

#include <iostream>
#include <string>
using namespace std;

#define n 3
#define t 4 //cubo, 4 facce
string funzione(string S[t][n][n]){
    //dovrei scorrere le dimensioni del cubo però mi chiede una faccia, quindi fisso k=0 (a piacere)
    string desinenze;
    string parola;
    string finale;
        for (int i=0; i<n; i++){ //scorro le matrici della faccia 0 (esse sono 0,1,2,3)
            for(int j=0; j<n; j++){
                parola=S[0][i][j];
                finale=parola.substr(parola.length()-1);
                desinenze+=finale+" "; //aggiungo la desinenza e uno spazio alla stringa da restituire
            }
        }
    return desinenze;
}


int main(){
    string S[t][n][n]= {"abba","cane","abb","acc","acd","ace","ao","af","ag",\
                        "ofc","pd","po","ca","di","gm","fi","bo","pc",\
                        "abbas","abbas","abcxb","dcs","fvsd","56165","asjj","afjg","adfbgcv","ofccvb","pdt","portg","ca23",\
                        "digb","gmm","fiz","bonnb","pcp"};

    string desinenze_parole;

   desinenze_parole=funzione(S);

    cout << desinenze_parole;

    return 0;
}