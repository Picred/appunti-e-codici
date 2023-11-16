#include<iostream>

using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        Point2D(): x(0), y(0) {}
        Point2D(int _x): x(_x), y(_x) {}
        double getX() const {return x;}
        double getY() const {return y;}
        Point2D sum(Point2D p) {
            return Point2D(x+p.x, y+p.y);
        }
        friend Point2D sum(Point2D p1, Point2D p2);
        friend Point2D operator+(Point2D p1, Point2D p2);
        friend Point2D operator-(Point2D p1, Point2D p2);
        friend Point2D operator-(Point2D p);
        // friend Point2D operator+(Point2D p1, int x);
};

class C {
    string s;
    int x;
    public:
        C(string _s, int _x) : s(_s), x(_x) {}
        string getS() {return s;}
        int getX() {return x;}
        friend C operator+(C c1, C c2);
        void print() {
            cout << s << ": "<<x << endl;
        }
};

C operator+(C c1, C c2) {
    return C(c1.s + "+" + c2.s, c1.x+c2.x);
}

void print(Point2D p) {
    cout << "(" << p.getX() << ", "<<p.getY() << ")"<<endl;
}

Point2D sum(Point2D p1, Point2D p2) {
    //return Point2D(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return Point2D(p1.x + p2.x, p1.y + p2.y);
}

Point2D operator+(Point2D p1, Point2D p2) {
    //return Point2D(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return Point2D(p1.x + p2.x, p1.y + p2.y);
}

Point2D operator-(Point2D p1, Point2D p2) {
    //return Point2D(p1.getX() + p2.getX(), p1.getY() + p2.getY());
    return Point2D(p1.x - p2.x, p1.y - p2.y);
}

Point2D operator-(Point2D p) {
    return Point2D(-p.x,-p.y);
}

// Point2D operator+(Point2D p1, int x) {
//     return Point2D(p1.x + x, p1.y + x);
// }

int main() {
    Point2D p1(3.2, 5.4);
    Point2D p2(3.5, 0.9);

    Point2D p3(p1.getX()+p2.getX(), p1.getY()+p2.getY());
    
    Point2D p4 = p1.sum(p2);
    Point2D p5 = sum(p1,p2); // p1 + p2

    Point2D p6 = p1 + p2;
    Point2D p7 = operator+(p1,p2);

    print(p1);
    print(p2);
    print(p3);
    print(p4);
    print(p5);
    print(p6);
    print(p7);

    C c1("A", 2);
    C c2("B", 3);

    C c3 = c1+c2;
    c1.print();
    c2.print();
    c3.print();

    Point2D p8 = p1 - p2;
    print(p8);

    Point2D p9 = -p1;
    print(p9);

    Point2D p10 = operator-(p1);
    print(p10);

    Point2D p11 = p1 + 2; // p1 + Point2D(2)
    Point2D p14 = 2 + p1; // Point2D(2) + p1
    Point2D p15 = 2.2 - p1; // Point2D(2) - p1
    print(p11);

    Point2D p12(5);
    Point2D p13 = 5;
}