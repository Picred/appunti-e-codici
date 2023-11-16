/*
26.Scrivere un metodo che prenda in input una 
matrice quadrata Q di dimensioni n x n di puntatori a 
stringhe e due short m e k e restituisca il valore 
booleano true se la diagonale secondaria di Q contiene 
almeno m stringhe con un numero di vocali minore o 
uguale a k. NB: Si assuma m<=n.
*/

#include <iostream>
#include <string>

#define n 3

using namespace std;

bool fun(string *Q[n][n], short m, short k){
    int counter;
    int num_stringhe=0;
    
    for(int i=0;i<n;i++){   //scorro la diagonale secondaria 
    
        string s= *Q[i][n-1-i]; //[0][2] -> [1][1] -> [2][0]
        
        counter=0;
    

        for (int p=0; p<s.length(); p++){ //vedo o non vedo i caratteri delle stringhe
            if(s[p]=='a' || s[p]=='A' || s[p]=='e' || s[p]=='E' || s[p]=='i' || s[p]=='I' || s[p]=='o' || s[p]=='O' || s[p]=='u' || s[p]=='U'){
                counter++;
            }
            // cout << "contatore s[" << k << "]" << "in Q[" << i << "][" << n-1-i << "]:" << counter << endl; //debug
        }
            if (counter <= k ){
                num_stringhe++;
                // cout << "\nn stringhe" << num_stringhe << endl; //debug
            }
        
    }
    
    if (num_stringhe >= m){
        return true;
    } else {
        return false;
    }
}



int main() {

    string *Q[n][n];

    short numero_stringhe = 1;  //m

    short massimo_vocali = 2;   //k

    
    Q[0][0] = new string("b");
    Q[0][1] = new string("f");
    Q[0][2] = new string("tu");   //secondaria
    
    Q[1][0] = new string("g");
    Q[1][1] = new string("et");   //secondaria
    Q[1][2] = new string("g");
    
    Q[2][0] = new string("it");   //secondaria
    Q[2][1] = new string("zz");
    Q[2][2] = new string("ll");
    
    cout << fun(Q,numero_stringhe,massimo_vocali);

    return 0;
}