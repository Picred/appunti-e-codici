#include "ora.h"

#include <iostream>

using namespace std;

int main(){

    Ora t1(12,23,43);
    Ora t2(49,53,10);
    Ora t3;

    t1.orologio();
    t2.orologio();
    t3.orologio();

    t1.aumenta_tempo(t2);
    t3.aumenta_tempo(t2);

    cout << endl;

    t1.orologio();
    t3.orologio();

    cout << "Visualizzo in formato 12h" << endl;

    t1.orologio_12h();
    t3.orologio_12h();
}