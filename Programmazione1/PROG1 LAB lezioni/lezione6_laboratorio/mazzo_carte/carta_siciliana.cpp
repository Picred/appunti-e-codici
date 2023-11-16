#include "carta_siciliana.h"
#include<string>

using namespace std;

CartaSiciliana::CartaSiciliana(short f, short s) : seme(s), figura(f) {}

short CartaSiciliana::getSeme() {return seme;}
short CartaSiciliana::getFigura() {return figura;}
string CartaSiciliana::nome() {
    // restituisce una stringa che indica la carta
    string s;

    switch(figura) {
        case ASSO:
            s+="asso";
            break;
        case DUE:
            s+="due";
            break;
        case TRE:
            s+="tre";
            break;
        case QUATTRO:
            s+="quattro";
            break;
        case CINQUE:
            s+="cinque";
            break;
        case SEI:
            s+="sei";
            break;
        case SETTE:
            s+="sette";
            break;
        case DONNA:
            s+="donna";
            break;
        case CAVALLO:
            s+="cavallo";
            break;
        case RE:
            s+="re";
            break;
        default:
            s+="figura sconosciuta";
            break;
    }

    s+=" di ";

    switch(seme) {
        case BASTONI:
            s+="bastoni";
            break;
        case SPADE:
            s+="spade";
            break;
        case COPPE:
            s+="coppe";
            break;
        case ORO:
            s+="oro";
            break;
        default:
            s+="seme sconosciuto";
            break;
    }
    return s;
}