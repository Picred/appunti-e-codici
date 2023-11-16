/*
Si costruisca una classe Cerchio che metta a disposizione metodi per calcolare il perimetro e l’area.

dall esercizo successivo:
Si modifichi la classe Cicle (si veda l’esercizio precedente) 
inserendo un metodo encloses che prende in input un oggetto di classe Rectangle e
restituisce true se il rettanglo è completamente contenuto all’interno del cerchio.
*/
#include <iostream>
#include <cmath>
#include "rettangolo.h"

using namespace std;

#define pi M_PI
class Cerchio {
    
    private:
        double raggio;
    public:
        bool encloses(Rectangle rettangolo){
            //il rettangolo e inscritto in un cerchio se la sua diagonale/2 e uguale al raggio
            if ( (rettangolo.get_diagonale()/2) == raggio){
                return true;
            } else {
                return false;
            }
        }
        void set_raggio(double r){
            raggio=r;
        }
        double perimetro(){
            return (2*pi*raggio);
        }
        double area(){
            return pi*(raggio*raggio);
        }
};

//test classe e metodi
/* int main(){
    Cerchio c;

    c.set_raggio(3);

    cout << c.perimetro() << " e " << c.area();
    
}
*/