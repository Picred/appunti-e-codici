#include <iostream>
using namespace std;

class A{
  int x; 
  //B b; 
  public:
    A(){
      x = 10; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    int getX() { return x;} 
};

class B: public A{
  float y; 

  public:
    using A::f;
    B() {y=18;}
    void g() { cout << "B.g(), y=" << y << endl;}
    //void f() { cout << "override di A.f(), x=" << getX() <<  endl;}
    void f(int x) { cout << "overloading di A.f(), x=" << getX()+x <<  endl;}
};

int main() {
    A a;
    a.f();

    B b;
    cout << b.getX() << endl;
    b.f(); //override
    b.g();

    cout << a.getX() << endl;

    //b.f(2);
    b.A::f(); //b.f();

}