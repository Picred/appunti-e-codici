#include "stanza.h"
#include <iostream>

using namespace std;

Stanza::Stanza(string s,double x, double y){
    nome=s;
    lunghezza=x;
    larghezza=y;
}

double Stanza::superficieStanza(){
    return lunghezza*larghezza;
}

void Stanza::sommarioStanze(){
    cout << "La/Il " << nome << "ha dimensioni: " << superficieStanza()<<"m quadrati."<<endl;
}