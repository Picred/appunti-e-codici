/*

Scrivere un metodo che prenda come parametro formale una matrice S 
di dimensione n×m di stringhe ed una stringa X, e modifichi con un ‘*’ 
e delle stringhe in S ogni carattere contenenti la sottostringa X. N.B.: Non è possibile usare substr.

*/

#include <iostream>
#include <string>

#define n 2
#define m 3

using namespace std;

void fun(string S[n][m], string X){
    
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            string s = S[i][j];
                if(s.find(X) != string::npos){
                    
                    int index=s.find(X);
                    for(int q=index; q<X.length()+index; q++){ 
                        S[i][j][q]='*';
                    }
                }
                
        }
        
    }

}

int main(){

    string M("iao");
    
    string Q[n][m];

    Q[0][0]="ciao"; //c***
    Q[0][1]="cogliao";  //cogl***
    Q[0][2]="diocesi";  //diocesi

    Q[1][0]="comeva";   //comeva
    Q[1][1]="iao";  //***
    Q[1][2]="lunediaoesame";     //lunediesame
    
    
    fun(Q,M);

    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){

            cout << Q[i][j] << endl;
        }
        cout << endl;

        return 0;
    }


}

