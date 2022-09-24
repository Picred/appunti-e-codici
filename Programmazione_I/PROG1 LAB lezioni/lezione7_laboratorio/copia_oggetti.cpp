#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double a, double b) : x(a), y(b) {
            cout << "Costruttore" << endl;
        }
        Point2D(Point2D &p) : x(p.x), y(p.y) { //costruttore di copia
            //codice custom
            cout << "costruttore di copia"<<endl;
        }
        double getX() const {return x;}
        double getY() const {return y;}
        void setX(double a) {x=a;}
        void setY(double b) {y=b;}
};

int main() {
    Point2D p1(3,2);
    Point2D p2(4,5);

    cout << p1.getX() << ", "<<p1.getY() << endl;
    cout << p2.getX() << ", "<<p2.getY() << endl;

    p2=p1; //copia automatica membro a membro di C++
    p1.setX(-2);
    cout << p2.getX() << ", "<<p2.getY() << endl;

    Point2D p3 = p2; // dichiara p3 e copia p2 in p3
    cout << p3.getX() << ", "<<p3.getY() << endl;
    Point2D p4(p2); // dichiara p4 e copia p2 in p4
    cout << p4.getX() << ", "<<p4.getY() << endl;
}