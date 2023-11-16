#include "conto.h"
#include<cstdlib>
#include<ctime>
#include<iostream>

#define imposta 34.20
#define mese 12.0

using namespace std;

//implemento costruttori

Conto::Conto(string s, int n, double g){
    proprietario=s;
    srand(time(0));

    numero_conto=n;

    giacenza=g;
}

Conto::Conto(string s, int n) : proprietario(s){
    numero_conto=n;

    giacenza=0.0;
}
//getter
string Conto::getProprietario(){return proprietario;}
double Conto::getGiacenza(){return giacenza;}
int Conto::getNumeroconto(){ return numero_conto;}

void Conto::preleva(double x){
    if(x>giacenza)
        cerr << "Non ci sono abbastanza fondi. Non prelevo nulla."<<endl;
    else 
        giacenza-=x;
}

void Conto::versa(double y){
    if(y<0)
        cerr << "Hai inserito un numero non valido"<<endl;
    else 
        giacenza+=y;
}

void Conto::paga_imposta(){
    if (giacenza<imposta)
        cerr << "Non ci sono abbastanza fondi per pagare l'imposta"<<endl;
    else
        giacenza-=imposta;
}

void Conto::paga_mese(){
    if(giacenza<mese)
        cerr << "Non ci sono abbastanza fondi per pagare il mese"<<endl;
    else
        giacenza-=mese;
}