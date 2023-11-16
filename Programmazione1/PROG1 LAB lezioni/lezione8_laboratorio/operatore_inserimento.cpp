#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() {return x;}
        double getY() {return y;}
        friend ostream& operator<<(ostream &, Point2D);
};

ostream& operator<<(ostream &s, Point2D p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

int main() {
    Point2D p(2,3);
    cout << p << " " << 5 << " " << p;
}