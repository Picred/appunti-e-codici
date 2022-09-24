#include "bagno.h"
#include "stanza.h"
#include <iostream>

using namespace std;


Bagno::Bagno(double a, double b) : base(a), altezza(b){}

double Bagno::superficieBagno(){
    return base*altezza;
}

void Bagno::sommarioBagno(){
    cout << "La/Il " << s1 << "ha dimensioni: " << superficieBagno()<<"m quadrati."<<endl;
}