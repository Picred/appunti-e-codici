#include <iostream>

using namespace std; 

/* Overloading vs ereditarieta' */ 

/* 
Quattro versioni di f(): 
- f(), f(int), f(double), f(int, int) in A

B eredita tutte le versioni di f(), risoluzione 
overloading avverra' come al solito, nello scope della 
classe A..

*/ 

class A{
  int x; 

  public:
    A(){
      x = 10; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    void f(int alpha){ cout << "A.f(int)" << endl;} //overloading f()
    void f(double alpha){ cout << "A.f(double)" << endl;} //overloading f()
    void f(int alpha, int beta){ cout << "A.f(int, int)" << endl;} //overloading f()
    int getX() { return x;}
};

class B: public A{
  float y; 

  public:
    void g() { cout << "B.g(), x=" << getX() << endl;}
};

int main(){
  A a; 
  B b;

  a.f(); // f() in A
  b.g(); // B ha suo metodo g() 
  b.f(); // A.f() 
  b.f(10); // A.f(int) 
  b.f(5.6); // A.f(double) 
  b.f(10, 7.5); // A.f(int, int) 
}
