#include <iostream>

using namespace std; 

/* Overloading vs ereditarieta' */ 

/* 
Quattro versioni di f(): 
- f(), f(int) in A
- f(double) ed f(int, int) in B!! 

In questo caso e' stata usata la clausola using in 
apposita sezione di B! 

Con la clausola using all'interno di una apposita sezione 
della classe derivata, e' possibile ``forzare'' il compilatore
ad includere, nello scope della classe derivata, 
anche le funzioni definite nella classe base che non 
sono state riscritte (overridden) nella classe derivata. 

*/ 

class A{
  int x; 

  public:
    A(){
      x = 10; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    void f(int alpha){ cout << "A.f(int)" << endl;} //overloading f()
    int getX() { return x;}
};

class B: public A{
  float y; 

  public:
    using A::f; //Clausola using per ``ereditare'' funzioni overloaded in A 
    void g() { cout << "B.g(), x=" << getX() << endl;}
    void f(int alpha, int beta){ cout << "B.f(int, int)" << endl;} //overloading f()
    void f(double alpha){ cout << "B.f(double)" << endl;} //overloading f()
};

int main(){
  A a; 
  B b;

  a.f(); // f() in A, OK 
  b.g(); // g() in B, OK 
  b.f(); // 1. funzione f() di A, OK (grazie a linea 40)
  b.f(10); // 2. funzione f(int) in A, OK (grazie a linea 40)
  b.f(5.6); // 3. funzione f(double) in B, OK 
  b.f(10, 7.5); // f(int, int)  definita in B, OK 
}
