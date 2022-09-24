/*
Scrivere un metodo che prenda in input una matrice A ed un array B entrambe di float,
e restituisca un boolean che indichi se esiste in A una coppia di elementi verticali 
contigui la cui somma è pari alla somma di due elementi qualsiasi in B.

N.B. : Non è possibile utilizzare array ausiliari.
*/

#include <iostream>
using namespace std;


#define n 2
#define m 3
#define l 9

bool foo(float A[n][m], float B[l]){
    //devo scorrere per colonna e per ogni coppia contigua devo verificare corrispondenze in B

    for(int j=0; j<m;j++){
        for(int i=1; i<n;i++){
            float el1=A[i-1][j];
            float el2=A[i][j];
            float sommaA = el1+el2;
            //Somma elementi contigui di A va confrontata con la somma di due elementi qualsiasi in B
            //scorro B e ogni elemento lo confronto con tutto l'array
            for(int x=1; x<l; x++){
                float elArray2=B[x];
                for(int y=0; y<l; y++){
                    float elArray1=B[y];
                    float sommaArray=elArray1+elArray2;
                        //controllo se le due somme sono uguali
                        if(sommaA==sommaArray){
                            return true;
                        }
                }
            }
        }
    }
    return false;
}

int main(){
    float A[n][m];
    float B[l]={1.5, 2.5, 3.5, 4, 5, 6.5, 7, 8.5, 9.5};

    A[0][0]=8;  A[0][1]=0.5;  A[0][2]=0.45;
    A[1][0]=1.0;  A[1][1]=12.4;  A[1][2]=12.0;

    cout << foo(A,B);

    return -69; //qualcosa non va nell'output
}