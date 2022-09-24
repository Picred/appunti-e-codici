#include <iostream>

#include <cstdlib>

using namespace std; 

/* 
* Puntatori e reference vs ereditarieta'. 
* A <-- (public) B
* A <-- (public) C
* B <-- (public) D
*  
* Se Y deriva pubblicamente X, allora
* Y e' effettivamente un sottotipo di 
* Y. E' possibile sostituire 
* tutte le istanze di X con istanze di Y 
* senza che il comportamento del 
* programma cambi. 
*/ 

class A{
  int x;

  public:
    A(){
      cout << "A()" << endl; 
      x = 10;
    }
};

class B: public A{
  float y; 

  public:
    B(){ cout << "B()" << endl; y=3.5; }
    void f() { cout << "B.f()" << endl; }
    void b() { cout << "b()" << endl; } 
};


class C: public A{
  float z; 

  public:
    C(){ cout << "C()" << endl; z=45.6;}

    void c() { cout << "c()" << endl; } 
};

class D: public B{
  char c; 
  public: 
    D(){ cout << "D()" << endl; c = 'x'; }

    void d() { cout << "d(), c=" << c << endl; } 
};

class X: protected A{
  char alpha; 
  public: 
    X(){ cout << "X()" << endl; alpha = 'w'; }

    void x() { cout << "x()" << endl; } 
};

int main(){

  A a; 
  B b; 
  C c; 
  D d; 
  
  X x; 

  A* ptr_a1 = &b; // ok, punt. a tipo base punta a oggetto di classe derivata B
  A* ptr_a2 = &c; // ok, punt. a tipo base punta a oggetto di classe derivata C

//   ptr_a2->c(); // 1. Compile-time ERROR! ptr_a2 e' di tipo A! No metodo c() 

//  A* ptr_x =    &x; // 2. Compile-time ERROR! X estende NON ``pubblicamente'' A (ma protected)! 

  A& ref_a1 = *ptr_a1;  // reference a tipo base alias di oggetto di classe derivata B che estende pubblicamente A
  A& ref_a2 = *ptr_a2;  // reference a tipo base alias di oggetto di classe derivata C che estende pubblicamente A

  B* ptr_b = &d; // puntatore OK, D e' classe derivata di B
  B& ref1_b = d; // reference OK, D e' classe derivata di B

//   ptr_b = &a; // 3. Compile-time error! a e' istanza di superclasse di B
//  B& ref2_b = a; // 4. Compile-time error!  a e' istanza di superclasse di B
}
