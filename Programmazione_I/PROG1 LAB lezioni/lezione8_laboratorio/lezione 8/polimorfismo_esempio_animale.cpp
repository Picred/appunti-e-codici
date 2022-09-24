#include<iostream>
using namespace std;

class Animale {
    protected:
        string verso;
    public:
        void parla() {
            if(verso!="")
                cout << verso << endl;
        }
};

class Cane: public Animale {
    public:
        Cane() {verso="bau";}
};

class Gatto: public Animale {
    public:
        Gatto() {verso="miao";}
};

int main() {
    Animale *a;
    string animale = "gatto";

    if(animale=="gatto")
        a = new Gatto();
    else if(animale=="cane")
        a = new Cane();
    else
        a = new Animale();

    a->parla();
}