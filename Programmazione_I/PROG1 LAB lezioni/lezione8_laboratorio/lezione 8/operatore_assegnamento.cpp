#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() {return x;}
        double getY() {return y;}
        Point2D(const Point2D& p) {
            x=p.x;
            y=p.y;
            cout << "Costruttore di copia" << endl;
        }
        Point2D &operator=(Point2D& p) {
            x=p.x;
            y=p.y;
            cout << "Operatore ="<<endl;
            return *this;
        }
};

int main() {
    Point2D p1(2,3);
    Point2D p2(4,8);
    Point2D p3=p1; //costruttore di copia
    p3 = p2; //operatore =
}