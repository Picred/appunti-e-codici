// Scrivere un metodo che prenda in input una matrice M di puntatori
// a stringhe n x m e un intero k. La funzione restituisca il valore booleano
// true se esistono almeno k stringhe palindrome.

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

bool fun(string* M[n][m], int k){

    int count_pal = 0;
    int conto=0;
    //scorro la matrice e prendo la stringa in considerazio
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string s = *M[i][j];
            
            conto=0;
            cout << endl;
            //scorro la stringa    
            for(int k=0; (k<s.length()) && (k <= n-k-1); k++){ // n=10 ->[0][9] [1][8] [2][7] [3][6] [4][5] -> [5][4] [][] [][] ............
                if(s[k] == (s[n-k-1]) ){     
                    conto++;    // AABBAB

                   cout << conto << endl; //probabile errore qui
                }
            }
            if (conto >= (s.length()/2))
                count_pal++;

                // cout << count_pal << endl;
        }
    }

    if(count_pal>=k)
        return true;
    else 
        return false;
}

int main(){

    string *M[n][m];

    int k = 2;

    M[0][0]=new string("aba");
    M[0][1]=new string("come");
    M[0][2]=new string("porcodio");

    M[1][0]=new string("ssccss");
    M[1][1]=new string("ciao");
    M[1][2]=new string("hello");

    cout << fun(M,k);
}