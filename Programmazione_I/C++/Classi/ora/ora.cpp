#include "ora.h"
#include<iostream>

using namespace std;

Ora::Ora() : ora(0), minuti(0), secondi(0){}
Ora::Ora(int o, int m, int s) : ora(o), minuti(m), secondi(s){}

void Ora::orologio_12h(){
    while (ora>12)
        ora-=12;
    while (minuti>60){
        minuti-=60;
        ora++;
    }
    while (secondi>60){
        secondi-=60;
        minuti++;
    }
    cout << ora << ":" << minuti << ":" << secondi << endl;
}

int Ora::getOra(){return ora;}
int Ora::getMin(){return minuti;}
int Ora::getSec(){return secondi;}

void Ora::aumenta_tempo(Ora o1){
    ora+=o1.getOra();
    minuti+=o1.getMin();
    secondi+=o1.getSec();
}

void Ora::orologio(){
    //stampo orario
    cout << ora << ":" << minuti << ":" << secondi << endl;
    
}