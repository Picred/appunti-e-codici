#include<iostream>
using namespace std;

namespace geometric {
    class Rectangle {
        double base;
        double height;
        public:
            Rectangle(double b, double h) :base(b), height(h) {}
            double area() {return base*height;}
    };
    
    class Square {
        double side;
        public:
            Square(double s) : side(s) {}
            double area() {return side*side;}
    };
    
    class Circle {
        double r;
        public:
            Circle(double _r): r(_r) {}
            double area() {return 3.14*r*r;}
    };
}


namespace geometric2 {
    class Rectangle {
        double base;
        double height;
        public:
            Rectangle(double b, double h) :base(b), height(h) {}
            double area() {return base*height;}
            double perimeter() {return base*2+height*2;}
    };
}

/*using geometric::Square;
using geometric::Circle;
using geometric2::Rectangle;*/

using namespace geometric;

int main() {
    cout << 2;

    geometric2::Rectangle r(2,2);
    Square s(2);
    Circle c(4);

    cout << r.perimeter();
}