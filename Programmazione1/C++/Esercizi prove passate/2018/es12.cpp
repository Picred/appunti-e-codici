/*
Scrivere un metodo che preveda un parametro formale matrice quadrata di stringhe di dimensioni n x n,
uno short k ed una stringa s, e restituisca un array di n puntatori a stringhe in cui il 
generico elemento di indice i contiene la 
i-esima stringa della diagonale secondaria se questa ha lunghezza maggiore o 
uguale a k e inizia con la stringa s, altrimenti la
corrispondente stringa della diagonale principale.
*/
#include <string>

using namespace std;

string** foo(string** A,int n,short k, string s){
    //inizializzo B da tornare
    string** B = new string*[n];
        for(int i=0;i<n;i++){
            B[i]=new string[n];
        }

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){ //verifico lunghezza stringa e il suo inizio
            if( ( (A[i][n-1-i]).length() >= k ) &&  ((A[i][n-1-i]).find(s)==0) ){
                B[i][j]=A[i][n-1-i];
            } //se la stringa in A inisia con s, il metodo .find mi dá indice 0 che é la prima corrispondenza nella stringa
            
            else {
                B[i][j]=A[i][i];
            }
        }
    }
    return B;
}