#include<iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle(int w, int h) : width(w), height(h){}
    int getWidth() {return width;}
    int getHeight() {return height;}
    void setWidth(int w) {width=w;}
    void setHeight(int h) {height=h;}
    int area() {return (width*height);}
};

int main() {
    int x = 0;
    int *y = new int(0);

    cout << x << endl;
    cout << *y << endl;

    Rectangle r1(2,3);
    Rectangle *r2 = new Rectangle(2,3);

    cout << r1.area() << endl;
    cout << (*r2).area() << endl;
    cout << r2->area() << endl;
}