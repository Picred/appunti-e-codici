/* 
es2
Si costruisca una classe Rectangle che metta a disposizione metodi per calcolare perimetro e area. 

Si modifichi la classe Cicle (si veda l’esercizio precedente) 
inserendo un metodo encloses che prende in input un oggetto di classe Rectangle e
restituisce true se il rettanglo è completamente contenuto all’interno del cerchio.
*/

#include <cmath>

class Rectangle {
    private:
        double base;
        double altezza;
        double diagonale;
    public:
        
        double get_diagonale(){
            return diagonale;
        }

        void set_values(double b, double h){
            base=b;
            altezza=h;
            diagonale= sqrt((base*base)+(altezza*altezza));
        }

        double perimetro(){
            return (2*base)+(2*altezza);
        }
        
        double area(){
            return base*altezza;
        }

};