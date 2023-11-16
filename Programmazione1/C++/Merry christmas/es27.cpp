/*
27.Scrivere un metodo che prenda come parametro 
formale una matrice A n × m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti).
*/

#include <iostream>
#define n 2
#define m 3

using namespace std;

bool fun(int *A[n][m]){
    int count_elementi = 0;

    //scorro la matrice e prendo l'elemento attuale
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num_attuale= (*A[i][j]);
            //confronto l'elemento attuale con tutti gli altri.
            for (int a=0; a<n; a++){    
                for(int b=0; b<m; b++){
                        if (num_attuale== (*A[a][b]) ){
                            count_elementi++;
                        }
                }

            }
            //sottraggo 1 perchè ci sarà un numero che verrà confrontato con se stesso ad ogni ciclo del for più esterno
             count_elementi--;
        }
            
    }

    
    if(count_elementi >= 2)
        return true;
    else  
      return false;

}

int main(){

    int *A[n][m];

    A[0][0]= new int(196);
    A[0][1]= new int(116);
    A[0][2]= new int(186);

    A[1][0]= new int(146);
    A[1][1]= new int(17);
    A[1][2]= new int(16);

    cout << fun(A);

    return 0;
}