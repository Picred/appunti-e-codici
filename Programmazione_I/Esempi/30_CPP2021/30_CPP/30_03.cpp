#include <iostream>

#include <cstdlib>

using namespace std; 

/* 
* Puntatore a superclasse. Invocazione di metodo 
* overridden. 
* 
* Cosa accade con puntatori e reference 
* quando il tipo non e' noto a run-time? 
* 
* USO DELLA PAROLA VIRTUAL 
*/ 

class A{
  int x;

  public:
    A(){
      cout << "A()" << endl; 
      x = 10;
    }

   virtual void f() { cout << "A.f()" <<  endl;}
};

class B: public A{
  float y; 

  public:
    B(){ cout << "B()" << endl; }
    void f() { cout << "B.f()" << endl; }
};


class C: public A{
  float z; 

  public:
    C(){ cout << "C()" << endl; }
    void f() { cout << "C.f()" << endl; }
};

int main(){

  srand(time(0));

  //Il tipo e' noto a compile time..
  B b1; 
  cout << "1. b1.f()" << endl; 
  b1.f();

  //Il tipo e' noto a compile time..
  C c1; 
  cout << "2. c1.f()" << endl;
  c1.f();

  //puntatore al tipo base
  // tipo puntato da ptr non e' noto a compile-time
  A* ptr;
  if(rand()%2==0)
    ptr = new B(); 
  else
    ptr = new C();
  cout << "3. ptr->f()" << endl;
  ptr->f();

  //in questo caso?
  A* ptr1 = new C();
  ptr1->f();

  //reference al tipo base
  //analogamente, tipo ``puntato'' non e' noto a compile-time
  A &ref = *ptr; 
  cout << "4. ref.f()" << endl; 
  ref.f();
}
