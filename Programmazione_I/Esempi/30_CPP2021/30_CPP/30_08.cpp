#include <iostream>

using namespace std; 

class A{
  public:
    virtual void foo() { cout << "A::foo()" << endl; }
};

class B: public A{
  public:
    void foo() { cout << "B::foo()" << endl; }
    void b() { cout << "B:b()" << endl; }
};


class C:public A{
  string s; 

  public:
    void foo() { cout << "C::foo()" << endl; }
    void c() { cout << "C:c()" << endl; s="test";}
};

int main(){

  A* ptr = new B(); 

  cout << "try with static-cast.." << endl; 
  C* ptr_c = static_cast<C*>(ptr); 
  ptr_c -> c(); 

  cout << "try with c-style type cast.." << endl; 
  //cosa avviene ? 
  ((C*) ptr)->c();

}
