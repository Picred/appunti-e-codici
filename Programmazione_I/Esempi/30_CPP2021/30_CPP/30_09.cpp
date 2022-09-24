#include <iostream>

using namespace std; 



class A{
  public:
    virtual void foo() { cout << "A::foo()" << endl; }
};

class B: public A{
  public:
    void foo() { cout << "B::foo()" << endl; }
    void b() { cout << "B::b()" << endl; }
};


class C:public A{
  string s; 

  public:
    void foo() { cout << "C::foo()" << endl; }
    void c() { 
      cout << "C::c()" << endl; 
      s="test";
    }
};

int main(){

  A* ptr1 = new B(); 
  A* ptr2 = new C(); 

  //dynamic_cast 
  C* ptr_c1 = dynamic_cast<C*>(ptr1); 

  cout << "Trying to call C::c() through pointer ptr_c1.." << endl; 
  if(ptr_c1)
    ptr_c1->c(); 
  else
    cerr << "WARN: no any pointer to object of type C..(ptr_c1)" << endl; 

  //dynamic_cast 
  C* ptr_c2 = dynamic_cast<C*>(ptr2); 

  cout << "Trying to call C::c() through pointer ptr_c2.." << endl; 
  if(ptr_c2)
    ptr_c2->c(); 
  else
    cerr << "WARN: no any pointer to object of type C..(ptr_c2)" << endl; 

}
