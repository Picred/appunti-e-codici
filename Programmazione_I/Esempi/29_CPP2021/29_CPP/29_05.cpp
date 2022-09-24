#include <iostream>

using namespace std; 

/* Overloading vs ereditarieta' */ 

/* 
Quattro versioni di f(): 
- f(), f(int) in A
- f(double) ed f(int, int) in B!! 

Usando operatore di risoluzione  di scope, 
e' possibile bypassare parzialmente il problema 
di 29_04.cpp. 

Tuttavia risoluzione overloading e' a cura del programmatore, 
che deve selezionare la versione corretta della funzione f(). 

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
    void g() { cout << "B.g(), x=" << getX() << endl;}
    void f(int alpha, int beta){ cout << "B.f(int, int)" << endl;} //overloading f()
    void f(double alpha){ cout << "B.f(double)" << endl;} //overloading f()
};

int main(){
  A a; 
  B b;

  a.f(); // f() in A, OK 
  b.g(); // g() in B, OK 
  b.A::f(); // 
  b.A::f(10); // 1. funzione f(int) in A, grazie ad operatore risoluzione di scope
  b.f(5.6); // 2. funzione f(double) in B, OK 
  b.f(10, 7.5); // f(int, int)  definita in B, OK 
}
