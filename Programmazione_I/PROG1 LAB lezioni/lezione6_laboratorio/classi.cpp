#include<iostream>
using namespace std;

class Rectangle {
  private:
    int width, height;
    //int width, height; //Rectangle r;
    //width=0;
    //height=0;

    //Rectangle r;
    //int width = 0;
    //int height = 0;
    void setValues (int, int);
  public:
    Rectangle();
    Rectangle(int);
    Rectangle(int, int);
    int area ();
    //void setWidth(int);
    //void setHeight(int);
    int getWidth();
    int getHeight();
};

int Rectangle::getWidth() {
    return width;
}

int Rectangle::getHeight() {
    return height;
}

// void Rectangle::setWidth(int x) {
//     width = x;
// }

// void Rectangle::setHeight(int x) {
//     height = x;
// }

Rectangle::Rectangle() : width(0), height(0) {}

Rectangle::Rectangle(int s) {
    setValues(s, s);
}

Rectangle::Rectangle(int w, int h) {
    setValues(w, h);
}

int Rectangle::area() {
    return width * height;
}

void Rectangle::setValues (int w, int h) {
    width=w;
    height=h;
}


int main() {
    Rectangle r = {3, 2};
    Rectangle s(2);
    Rectangle r0;
    //int f();
    cout << r.area() << endl;
    //r.setValues(6, 7);
    cout << s.area() << endl;
    cout << r0.area() << endl;

    cout << r.getWidth() << endl;
}