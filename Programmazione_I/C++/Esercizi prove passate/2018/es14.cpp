/*
Scrivere un metodo che preveda un parametro 
formale array monodimensionale S di n puntatori a stringhe, ed inoltre una
matrice C di caratteri distinti ed uno short k, 

e restituisca un array di 
n puntatori a stringhe in cui il generico elemento di
indice i contiene un puntatore alla i-esima stringa in S solo 
se questa contiene almeno k caratteri in C, altrimenti nullptr.
*/

#include<string>

using namespace std;

#define n 10

string** foo(string* S[n], char** C, short k){
    //controllo se i caratteri di C sono distinti?
    // dimensioni di C?
    string** Ret=new string*[n]; //array di puntatori creato!

    for (int i=0; i<n; i++){
        string parola = *S[i];
        // scorro la stringa 
            int counter;
        for (int j=0; j<parola.length(); j++){
            counter=0; // conto le corrispondenze
                if( parola.find(C[i][j]) != string::npos ){
                    counter++;
                }
                if(counter >= k){
                    Ret[i]=S[i];
                    break;
                }
        }
        if(counter<k)
            Ret[i]=nullptr;
    }
    return Ret;
}