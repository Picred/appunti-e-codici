#include<iostream>
using namespace std;

// class Animale { //classe astratta
//     public:
//         virtual void parla() = 0; //metodo astratto / funzione virtuale pura
//         void corri() {
//             cout << "run run!" << endl;
//         }
// };

class Animale { //interfaccia
    public:
        virtual void parla() = 0; //metodo astratto / funzione virtuale pura
        virtual void corri() = 0;
        virtual void dormi() = 0;
};

class Cane: public Animale {
    public:
        void parla() {cout << "bau"<<endl;}
        void dormi() {}
        void corri() {}
};

class Gatto: public Animale {
    public:
        void parla() {cout << "miao"<<endl;}
        void dormi() {}
        void corri() {}
};

int main() {
    Animale *a = nullptr;
    string animale = "gatto";

    if(animale=="gatto")
        a = new Gatto();
    else if(animale=="cane")
        a = new Cane();
    else
        cerr << "permessi solo cane e gatto" << endl;

    if(a) {
        a->parla();
        //a->corri();
    }
}