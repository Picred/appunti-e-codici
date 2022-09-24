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

void print(const Classe &o) {
    cout << o.getX() << endl;
}

void print_ptr(Classe *o) {
    cout << o->getX() << endl;
    o->setX();
}

int main() {
    Classe o;
    Classe &ref_o = o;
    Classe *ptr_o = &o;

    Classe o2(-2);

    ref_o.setX(2);

    cout << o.getX() << endl;
    cout << ref_o.getX() << endl;
    cout << ptr_o->getX() << endl;

    ptr_o = &o2;
    o.setX(-18);
    cout << ptr_o->getX() << endl;

    ref_o = o2; // *ptr_o = o2;
    o.setX(-18);
    cout << ref_o.getX() << endl;

    //Classe &r; //errore

    int x = 8;
    const int &r = x;
    cout << r << endl;

    //r=-2; //errore

    const Classe &ref = o;

    cout << ref.getX() << endl;

    print(ref);
}