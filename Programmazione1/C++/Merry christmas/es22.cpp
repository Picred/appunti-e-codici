/*
22.Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. NB: Si 
assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero.
*/

#include <iostream>
#include <string>

using namespace std;

bool fun(string **Q, int n){

    int count_vocali_max = 0, count_vocali_min = 0;

    string max_str = Q[0][0];
    string min_str = Q[0][0];

    //cerco stringa piu lunga
    for (int i=0;i<n;i++){
        if (Q[i][i].length()>max_str.length()){
            max_str=Q[i][i];
        }
    }
    cout << "stringa piu lunga:" << max_str << endl;

    for (int i=0; i<max_str.length();i++){   
        char s1=max_str[i]; 
        if(s1=='a' || s1=='A' || s1=='e' || s1=='E' || s1=='i' || s1=='I' || s1=='o' || s1=='O' || s1=='u' || s1=='U'){
            count_vocali_max++;
        }
    }
    
    
    //cerco stringa piu corta
    for (int i=0;i<n;i++){
        if (Q[i][i].length()<min_str.length()){
            min_str=Q[i][i];
        }
    }

    cout << "stringa NON piu lunga:" << min_str << endl;

    for (int i=0; i<min_str.length();i++){       
        char s1=min_str[i]; 
        if(s1=='a' || s1=='A' || s1=='e' || s1=='E' || s1=='i' || s1=='I' || s1=='o' || s1=='O' || s1=='u' || s1=='U'){
            count_vocali_min++;
        }
    }
    if(count_vocali_max<count_vocali_min){
        return true;
    }

    return false;
}




int main(){
    
    int n=3;
    
    string **D = new string *[n];
    for(int i=0;i<n;i++)
        D[i] = new string [n];

    D[0][0]="iushdjksdhg"; //principale, 2 vocali
    D[0][1]="hacker";
    D[0][2]="report";

    D[1][0]="twitch";
    D[1][1]="dioo";   //principale, 1 vocali
    D[1][2]="signori";
    
    D[2][0]="midissocio";
    D[2][1]="porcodio";
    D[2][2]="diocane"; //principale
    
    cout << fun(D,n) << endl;

    return 0;
}