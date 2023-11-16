/*
Scrivere un metodo che prenda in input una matrice quadrata M di short e restituisca il valore booleano
true se M è una matrice triangolare inferiore o superiore
*/

#include <iostream>

using namespace std;

/*
1 0 0   A[i][j] tali che i<j
4 2 0
3 5 8

i 0 0 0  1 1 1 inferiore 
j 0 1 2  1 1 2 inferiore
*/

#include <iostream>

using namespace std;

#define n 3

bool funzione(short M[n][n]){
    bool triangolare_inferiore=true;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
                    if (M[i][j] != 0){
                        triangolare_inferiore=false;
                    }
            
        }
    }
    if(triangolare_inferiore){
        return true;
    }

    bool triangolare_superiore=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
                    if (M[i][j] != 0){
                        triangolare_superiore=false;   
            }
        }
    }
    return triangolare_superiore;

}

int main(){
    short A[n][n]={ {1,0,5},
                    {2,3,0},
                    {4,5,4} };
    
    bool a=funzione(A);
    if(a){
        cout << "triangolare";
    } else {
        cout << "non triangolare";
    }
    return 0;
}