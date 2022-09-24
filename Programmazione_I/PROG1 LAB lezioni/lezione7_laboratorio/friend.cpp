#include<iostream>
#include<cmath>
using namespace std;

class Point2D {
    private:
        double x, y;
    public:
        Point2D() : x(0), y(0) {}
        Point2D(double _x, double _y) : x(_x), y(_y) {}
        double getX() const {return x;}
        double getY() const {return y;}
        friend void normalize(Point2D &p);
        friend Point2D sum(Point2D p1, Point2D p2);
        Point2D sum2(Point2D p2){
            return Point2D(x+p2.x, y+p2.y);
        }
        //void setX(double _x) {x=_x;}
        //void setY(double _y) {y=_y;}
        /*void normalize() {
            double mod = sqrt(x*x + y*y);
            x/=mod;
            y/=mod;
        }*/
};

/*void normalize(Point2D &p) {
    //double mod = sqrt(p.x*p.x + p.y*p.y);
    double mod = sqrt(p.getX()*p.getX() + p.getY()*p.getY());
    p.setX(p.getX()/mod);
    p.setY(p.getY()/mod);
    //p.x/=mod;
    //p.y/=mod;
}*/

void normalize(Point2D &p) {
    double mod = sqrt(p.x*p.x + p.y*p.y);
    p.x/=mod;
    p.y/=mod;
}

Point2D sum(Point2D p1, Point2D p2) {
    return Point2D(p1.x+p2.x, p1.y+p2.y);
}

int main() {
    Point2D p(2.3,5.6);
    normalize(p);
    //p.normalize();
    cout << p.getX() << " - " << p.getY() << endl;

    Point2D p1(2,3);
    Point2D p2(4,5);
    Point2D p3 = sum(p1,p2);
    cout << p3.getX() << " - " << p3.getY() << endl;

    Point2D p4 = p1.sum2(p2);
    cout << p4.getX() << " - " << p4.getY() << endl;
}