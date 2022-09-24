#include<iostream>
using namespace std;

class IntPoint2D {
    int x, y;
    public:
        IntPoint2D(int _x, int _y) : x(_x), y(_y) {}
        int getX() {return x;}
        int getY() {return y;}
        friend ostream& operator<<(ostream &, IntPoint2D);
};

ostream& operator<<(ostream &s, IntPoint2D p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() {return x;}
        double getY() {return y;}
        operator IntPoint2D() {
            return IntPoint2D(int(x), int(y));
        }
        friend ostream& operator<<(ostream &, Point2D);
};

ostream& operator<<(ostream &s, Point2D p) {
    // inserisco una rapresentazione di p nel riferimento a ostream
    s << "(" << p.x << "," << p.y << ")";
    return s; //restituisco il riferimento
}

int main() {
    Point2D p(2.2,3.3);
    cout << p << endl;
    cout << IntPoint2D(p);
    IntPoint2D p2(2,3);
}