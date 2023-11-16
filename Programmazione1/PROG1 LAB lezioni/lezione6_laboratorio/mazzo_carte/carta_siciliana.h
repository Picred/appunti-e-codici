#ifndef CARTA_SICILIANA_H
#define CARTA_SICILIANA_H

#include<string>

#define BASTONI 11
#define COPPE 12
#define ORO 13
#define SPADE 14

#define ASSO 1
#define DUE 2
#define TRE 3
#define QUATTRO 4
#define CINQUE 5
#define SEI 6
#define SETTE 7
#define DONNA 8
#define CAVALLO 9
#define RE 10

using namespace std;

class CartaSiciliana {
    short seme;
    short figura;
    public:
        CartaSiciliana(short, short);
        short getSeme();
        short getFigura();
        string nome();
};
#endif