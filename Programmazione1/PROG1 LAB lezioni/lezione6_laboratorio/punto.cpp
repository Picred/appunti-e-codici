#include<cmath>
#include<iostream>
using namespace std;

class Punto2D {
    double x, y;
    public:
        //Punto2D() : x(0), y(0) {}
        Punto2D(double _x, double _y): x(_x), y(_y) {}
        double distanzaDalCentro() {return sqrt(x*x+y*y);}
        void stampa() {cout << "("<<x<<","<<y<<")"<<endl;}
};

int main() {
    Punto2D p(2,3);
    p.stampa();
    cout << endl;

    Punto2D punti[3] = {Punto2D(2,3),Punto2D(4,5),Punto2D(7,7)};

    for (int i=0; i<3; i++)
        punti[i].stampa();

    cout << endl;

    Punto2D punti2[3] = {{2,3},{4,5},{7,7}};
    for (int i=0; i<3; i++)
        punti2[i].stampa();

    cout << endl;

    // Punto2D punti3[3] = {{2,3},{4,5}};;

    // for (int i=0; i<3; i++)
    //     punti3[i].stampa();


    Punto2D *punti4[3];

    for(int i=0; i<3; i++)
        punti4[i] = new Punto2D(i,i+1);

    for (int i=0; i<3; i++)
        punti4[i]->stampa();
}