/*
11.4
Codificare in linguaggio C++ un algoritmo che produca la
somma dei numeri interi dispari da 1 a 99, facendo uso del
costrutto for. Dalla somma vanno esclusi i numeri divisibili
per tre.
*/
#include <iostream>

using namespace std;

int main(){

    int somma=0;
    cout << "Somma dei dispari da 1 a 99, esclusi i divisibil per 3: " << endl;

    for (int i=1; i<100; i++){
        if (i%2==0 || i%3==0){
            continue;
        } else {
            somma+=i;
        }
    }
    cout << "La somma e': " << somma;
}