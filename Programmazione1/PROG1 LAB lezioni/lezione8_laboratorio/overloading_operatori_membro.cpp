#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(double _x) : x(_x), y(_x) {}
        double getX() {return x;}
        double getY() {return y;}
        Point2D operator+(Point2D a){ // this, a
            return Point2D(a.x+x, a.y+y);
        }
        Point2D operator-() {
            return Point2D(-x,-y);
        }
};

int main() {
    Point2D p1(2,3);
    Point2D p2(1,2);
    Point2D p3 = -(p1 + p2);
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;

    Point2D p4 = p1.operator+(p2);

    cout << "("<<p4.getX() << "," << p4.getY() << ")" << endl;
}