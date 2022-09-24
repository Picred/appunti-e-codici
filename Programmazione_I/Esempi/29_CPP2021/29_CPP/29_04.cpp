#include <iostream>

using namespace std; 

/* Overloading vs ereditarieta' */ 

/* 
Quattro versioni di f(): 
- f(), f(int) in A
- f(int, int) ed f(double) in B!! 

Compilatore ``vede'' definizione di f(int, int) e f(double) in B. Dunque: 

- chiamata a funzione presente solo in A (es f()) non sara' risolta dal 
compilatore tramite regole di ereditarieta', ma mediante risoluzione 
overloading nello scope di B! f(int, int) e f(double) in B ``oscurano'' la 
famiglia di funzioni overloaded in A
- Di conseguenza una chiamata ad f() dara errore a compile-time! 
- Inoltre una chiamata a f(int) usera' f(double) definita in B! 

(vedi punti 1. e 2. nel main..)

*/ 

class A{
  int x; 

  public:
    A(){
      x = 10; 
    }

    void f() { cout << "A.f(), x=" << x <<  endl;}
    void f(int alpha){ cout << "A.f(int)" << endl;} //overloading f() in A
    int getX() { return x;}
};

class B: public A{
  float y; 

  public:
    void g() { cout << "B.g(), x=" << getX() << endl;}
    void f(double alpha){cout << "B.f(double)" << endl;} // definizione f(double) in B 
    void f(int alpha, int beta){ cout << "B.f(int, int)" << endl;} // overloading f in B
};

int main(){
  A a; 
  B b;

  a.f(); // f() in A, OK 
  b.g(); // g() in B, OK 
//  b.f(); // 1. ERRORE del compilatore, f() non e' nello scope di B...
  b.f(10); // 2. f(int) oppure f(double)? (argomento e' int, ma viene invocata f(double)) 
  b.f(10, 7.5); // f(int, int) definita in B, OK 
}
