#include <iostream>

using namespace std; 

/* 
Specificatori di accesso nella derivazione. 

PUBLIC 
*/ 

class A{
  int x;
  void add(int z) { x+=z; }

  public:
    A(){
      x = 10; 
    }
    int getX() { cout << "A.getX()" << endl; return x; }

  protected: 
    void g(int alpha){ cout << "A.g()" << endl; add(alpha);}
};

class B: public A{
  float y; 

  public:
    B(){
      y = 20;
    }

    int getSum(){
      cout << "B.getSum()" << endl;
      return getX() + y; 
      //return x  + y; // Compile-time error! x e' private in A 
    }

    int getSum(int alpha){
      cout << "B.getSum(alpha)" << endl;

      /* Compile-time error! 
      *  add() private in A, quindi non accessibile in B..
      */ 
      //add(alpha); 

      g(alpha);// OK, g() e' protected in A
      return y + getX(); 
    }    
};

int main(){
  A a; 
  B b;

  //a.g(10); // Compile-time error! g() protected in A..
  //b.g(10); // Compile-time error! g() protected anche in B..

  cout << a.getX() << endl; 
  cout << b.getX() << endl; 

  cout << b.getSum() << endl; 
  cout << b.getSum(15) << endl;   
}
