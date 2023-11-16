/*
20.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensione n x m, 
una stringa s1 ed uno short k, e restituisca la 
percentuale di stringhe, tra quelle presenti nelle prime 
k colonne di S, che siano piu lunghe di s1. NB: si 
assuma k<=m.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define n 2
#define m 3

double funzione(string* S[n][m], string s1, short k){
    double per=0, count_tot = n*m, countstr=0;


    for(int j=0; j<k; j++){
        for (int i=0;i<n;i++){
            if((*S[i][j]).length()>s1.length())
                countstr++;
        }
    }


    per=(countstr/count_tot)*100;
    
    return per;
}


int main(){ 
    string *S[n][m];
    
    string s1("ciao");

    short k = 2;

    S[0][0] = new string("gabriele");
    S[0][1] = new string("andrei");  
    S[0][2] = new string("alessia");

    S[1][0] = new string("porcodio");
    S[1][1] = new string("cutello");  
    S[1][2] = new string("gmf");

    double percentuale;

    percentuale=funzione(S,s1,k);

    cout << fixed <<setprecision(2) << percentuale<<" %" << endl;

    return 0;
}