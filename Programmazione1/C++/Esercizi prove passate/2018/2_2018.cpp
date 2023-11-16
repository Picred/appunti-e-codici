/*
Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M.
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define n 2
#define m 3

void foo(string* M[n][m]){
    bool palindrome=false;
    int counter=0;
    string stringa;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                for (int k=0; k< ( (*M[i][j]).length()); k++){
                    
                }
        }
}
}


//     scorro la matrice per colonna, quindi fisso la colonna e abbasso di righe
//     for (int j=0; j<m; j++){
//         for (int i=0; i<n; i++){
            
//             stringa = **M[i][j];

//                 for (int q=0; q < stringa.length(); q++){
//                     int l=1;
//                     int dim_stringa = stringa.length()-1;

//                     if ( stringa[q] == stringa[dim_stringa--]; && q != (q-l) ){
//                         counter++;
//                     }
//                     if (counter == n){
//                         return true;
//                     } else {
//                         counter=0;
//                     }
//                 l++;
//                 }
//         }
//     }
//     return false;
// }

// int main(){
//     int k=0;
// }