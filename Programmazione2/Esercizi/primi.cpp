/*
    Esercizio: definire un metodo che stampa tutti i numeri primi fino a n

3 metodi:
*/

#include <iostream>

using namespace std;

void numeriprimi_1(int n){
    
    for(int i=2; i<=n; i++){
        bool is_prime=true;
        for(int j=2; j<i/2; j++){
            if (i%j==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime){
        cout << i  << " e' primo" << endl;
    }
    }
}

int main(){
    numeriprimi_1(20);
}