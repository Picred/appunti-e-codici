#include <iostream>

using namespace std; 

/* Primo esempio di derivazione (classe derivata e classe madre) */

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
    void g() { cout << "B.g(), x=" << getX() << endl;}
};

int main(){

  A a; 
  B b;

  a.f(); // f() di A 
  b.g(); // B ha su metodo g()  
  b.f(); // f() di A, in quanto B eredita f() e non c'e' overriding 
  //a.g(); // ERRORE del compilatore

}
