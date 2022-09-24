#include <iostream>

#include <typeinfo> 

using namespace std; 

//RTTI (typeid) 

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
    void c() { cout << "C:c()" << endl; s="test"; }
};

int main(){

  A* ptr1 = new B(); 
  A* ptr2 = new C(); 

  //RTTI 
  if(typeid(*ptr1) == typeid(C)){
    cout << "Calling C::c() through pointer ptr1.." << endl; 
    ((C*) ptr1) -> c(); 
  }
  else if(typeid(*ptr2) == typeid(C)){
    cout << "Calling C::c() through pointer ptr2.." << endl; 
    ((C*) ptr2) -> c(); 
  }

  cout << typeid(*ptr2).name() << endl; 
}
