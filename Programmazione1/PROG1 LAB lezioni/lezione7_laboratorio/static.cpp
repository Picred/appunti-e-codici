#include<iostream>
using namespace std;

class Classe {
    int x;
    public:
        Classe() : x(0) {}
        Classe(int _x): x(_x) {}
        void setX(int _x) {x=_x;}
        int getX() const {return x;}
};

class Contatore {
    static int contatore; //variabile di isntanza, condivisa tra tutti gli oggetti
    int x; //variabile di istanza: ogni oggetto avrà la sua copia
    public:
        Contatore() : x(0) {contatore++;}
        Contatore(int _x) : x(_x) {contatore++;}
        int getX() const {return x;}
        void setX(int _x) {x=_x;}
        static int getCount() {return contatore;}
};

int Contatore::contatore = 0;

int fun() {
    static int c = 0;
    return ++c;
}

int main() {
    Classe o1(5);
    Classe o2(3);

    o1.setX(-8);

    cout << o2.getX() << endl;

    /*Contatore c1(1);
    Contatore c2(2);
    Contatore c3(3);

    cout << c1.getX() << endl;
    cout << c2.getX() << endl;
    cout << c3.getX() << endl << endl;

    cout << c1.getCount() << endl;
    cout << c2.getCount() << endl;
    cout << c3.getCount() << endl;*/

    /*cout << fun() << endl;
    cout << fun() << endl;
    cout << fun() << endl;*/

    cout << Contatore::getCount() << endl;
}