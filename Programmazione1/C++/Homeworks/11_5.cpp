/*
11.5
Codificare in linguaggio C++ un algoritmo che stampi a ritroso i numeri pari minori o uguali a mille; Il loop deve comunque
terminare se la somma dei numeri precedentemente stampati
`e maggiore o uguale a centomila.
*/
#include <iostream>

using namespace std;

int main (){

    int somma=0;
    for (int i=1000; i>=0; i--){
        if (i%2!=0){
            continue;
        } else {
            somma+=i;
            cout << somma << endl;
        }
        if (somma>=100000){
            break;
        }
    }
}