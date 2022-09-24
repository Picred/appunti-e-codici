#include <iostream>

using namespace std; 

/* Primo esempio di derivazione + overriding metodi  */

class A{
  int x; 

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
    void f() { cout << "B.f(), x=" << getX() << endl;}
};

int main(){

  A a; 
  B b;

  a.f(); // f() di A 
  b.g(); // B ha suo metodo g()  
  b.f(); // f() fornita da B -- overriding
  //a.g(); // ERRORE del compilatore

}
