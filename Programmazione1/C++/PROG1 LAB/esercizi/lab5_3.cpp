/*

Scrivere un metodo che prenda come parametro formale una matrice S di 
dimensione n × m di stringhe ed una stringa X, e restituisca una stringa di ‘*’ la 
cui lunghezza è pari al numero di stringhe in S 
contenenti la sottostringa X. N.B.: Non è possibile usare substr.

*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

string fun(string S[n][m], string X){
    int counter = 0;
    
    
    for(int i = 0; i < n; i++){
        for ( int j = 0; j<m; j++){
            if(S[i][j].find(X)!=string::npos)
                counter++;
        }
    }
    
    char* ret=new char[counter];
    for(int i = 0; i < counter; i++){
        ret[i]='*';
    }
    return ret;
}

int main(){
    string Q[n][m];
    string M("iao");
    
    Q[0][0]="ciao";
    Q[0][1]="cogliao";
    Q[0][2]="diocesi";

    Q[1][0]="comeva";
    Q[1][1]="iao";
    Q[1][2]="lunediaoesame";

    string l= fun(Q,M);
    cout << l<< endl;

    //****
}