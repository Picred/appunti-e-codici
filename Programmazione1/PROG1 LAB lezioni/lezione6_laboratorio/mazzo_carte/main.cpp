#include "mazzo_siciliano.h"
#include "carta_siciliana.h"
#include<iostream>

using namespace std;

int main() {
    MazzoSiciliano m;
    for(int i=0; i<45; i++) {
        CartaSiciliana *c = m.pescaCarta();
        if(c)
            cout << "Carta numero " << (i+1) << ": "<< c->nome()<<endl;
        else
            cout << "Carte esaurite"<<endl;
    }
}