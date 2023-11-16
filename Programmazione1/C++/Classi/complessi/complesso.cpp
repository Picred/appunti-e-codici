#include <iostream>
#include "complesso.h"

using namespace std;

Complesso::Complesso(double r, double i){
    this->r=r;
    this->i=i;
}

void Complesso::stampa(){
    cout << r << "-" << i << endl;
}

double Complesso::getR(){return r;}
double Complesso::getI(){return i;}

double Complesso::somma(Complesso c1){
    r+=c1.getR();
    i+=c1.getI();
}

double Complesso::sottrazione(Complesso c1){
    r-=c1.getR();
    i-=c1.getI();
}

double Complesso::prodotto(Complesso c1){
    r*=c1.getR();
    i*=c1.getI();
}

double Complesso::divisione(Complesso c1){
    r/=c1.getR();
    i/=c1.getI();
}
