#include <iostream>
#include "complesso.h"

using namespace std;

int main(){
    Complesso c1(53.89,75.90);
    Complesso c2(7.11,4.10);

    c1.stampa();
    c2.stampa();

    c1.sottrazione(c2);
    c2.sottrazione(c1);

    c1.stampa();
    c2.stampa();

    c1.prodotto(c2);
    c2.divisione(c1);
    
    c1.stampa();
    c2.stampa();
}