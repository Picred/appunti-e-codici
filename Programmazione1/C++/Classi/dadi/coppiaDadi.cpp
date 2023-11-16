#include "dado.h"
#include "coppiaDadi.h"
#include<iostream>

using namespace std;

CoppiaDadi::CoppiaDadi(){
    d1.lanciaDado();
    d2.lanciaDado();
}
void CoppiaDadi::lanciali(){
    
    d1.lanciaDado();
    d2.lanciaDado();
}

void CoppiaDadi::vediDadi(){
    cout << d1.getValore() << "-" << d2.getValore() << endl;
}