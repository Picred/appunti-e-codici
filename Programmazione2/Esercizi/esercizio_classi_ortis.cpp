/*
Definire una classe Rettangolo con i seguenti requisiti funzionali:
• Attributi base e altezza privati, ma accessibili tramite getter/setter.
• Il costruttore prende la base e l’altezza come parametri, in alternativa
imposta due valori di default.
• Implementare delle funzioni membro pubbliche per il calcolo di area,
perimetro e diagonale
• Implementare una funzione membro che verifica se si tratta di un quadrato
Definire un metodo main() dove vengono istanziati alcuni oggetti Rettangolo
per testare le funzionalità della classe.
Hint: utilizzare in maniera opportuna i diversi modi per definire un costruttore
ed il qualificatore const.
*/


#include <cmath>
#include <iostream>

using namespace std;

class Rettangolo{
    private:
        double base;
        double altezza;
    public:
        Rettangolo(double b=0, double h=0) : base(b), altezza(h){}

        double area(){
            return base*altezza;
        }

        double perimetro(){
            return ((2*base)+(2*altezza));
        }

        double diagonale(){
            return sqrt((base*base)+(altezza*altezza));
        }

        bool is_quadrato(){
            return base==altezza;
        }

        void setBase(double b){ base=b;}
        void setAltezza(double h) {altezza=h;}

        double getBase(){ return this->base;}
        double getAltezza(){ return this->altezza;}
};

int main(){
    Rettangolo r1(2,2);
    Rettangolo r2(15,6);
    Rettangolo r3(0.1,0.2);

    cout << r1.getBase() << " " << r2.getBase() << " " << r3.getBase() << endl;

    cout << r1.area() << " " << r2.area() << " " << r3.area() << endl;

}