#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(double _x) : x(_x), y(_x) {}
        double getX() const {return x;}
        double getY() const {return y;}
        Point2D &operator++() { //prefisso
            x++; //decrementa
            y++;
            return *this; //passa un riferimento a se stesso (modificato)
        }
        Point2D operator++(int) { //postfisso - parametro dummy "int" per distinguere dal caso prefisso
            Point2D aux = *this; //crea una copia
            x++; //incrementa se stesso (non la copia)
            y++;
            return aux; //passa la copia non aggiornata
        }

        friend Point2D &operator--(Point2D&); //prefisso
        friend Point2D operator--(Point2D&, int); //postfisso - con parametro dummy
        friend ostream& operator<<(ostream&, Point2D);
        
};

ostream& operator<<(ostream &s, Point2D p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

Point2D &operator--(Point2D& p) { //prefisso
    p.x--;
    p.y--;
    return p;
}

Point2D operator--(Point2D& p, int) { //postfisso - con parametro dummy
    Point2D aux = p;
    p.x--;
    p.y--;
    return aux;
}

int main() {
    Point2D p(2,3);
    cout << p << endl;
    cout << ++p << endl;
    cout << p++ << endl;
    cout << p << endl<<endl;

    cout << --p << endl;
    cout << p-- << endl;
    cout << p << endl;
}