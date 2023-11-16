#include<iostream>
using namespace std;

class A{
  protected:
    int x; 
    //B b; 
  public:
    A(int _x){
      x = _x; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    int getX() { return x;} 
};

class B: public A{
  float y; 

  public:
    B(int x, float _y) : A(x) {y=_y;}
    void f() {cout << "override di A.f(), x="<< getX() <<endl;}
    void g() { cout << "B.g(), y=" << y << endl;}
};

int main() {
    A *a = new A(5);
    a->f();
    B * b = new B(2, 3);
    b->f();

    A *ab = new B(2,3);
    //B *ba = new A(2);

    ab->f();

    a = b;
    b->f();
    a->f();
}