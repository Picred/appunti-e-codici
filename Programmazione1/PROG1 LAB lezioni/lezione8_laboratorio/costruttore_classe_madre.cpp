#include<iostream>
using namespace std;

class A{
  protected:
    int x; 
    //B b; 
  public:
    A() {}
    A(int _x){
      x = _x; 
      cout << "costruttore di A"<<endl;
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    int getX() { return x;} 
};

class B: public A{
  float y; 

  public:
    //B(int x, float _y) : A(x) {y=_y;}
    B(int _x, int _y) : y(_y) {x=_x;}
    void f() {cout << "override di A.f(), x="<< getX() <<endl;}
    void g() { cout << "B.g(), y=" << y << endl;}
};

int main() {
    B b(2, 3.2);
    b.f();
    b.g();
}