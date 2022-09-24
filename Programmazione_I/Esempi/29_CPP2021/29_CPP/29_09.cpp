#include <iostream>

using namespace std; 

/* 
Specificatori di accesso nella derivazione. 

PRIVATE
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

class B: private A{
  //private 
  float y; 

  //getX() e g() private in B! 

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

      g(alpha);// OK, g() e' protected in A, quindi accessibile
      return y + alpha + getX(); 
    }    
};

class C: public B{
  
    double c; 
    
    //getX() e g() NON accessibili in C
    //in quanto private in B  

    public:
      C(){
	// c = ((double) getX()) + 0.5;  // NO! getX() private in B!
	c = 12.5; 
      }

      void print(){
	// int tmp = getX(); // NO! gtX() private in B! 
	cout << "c=" << c  << endl;
      }
};

int main(){
  A a; // base 
  B b; // private A -> b
  C c; // public B -> C 

  //a.g(10); // Compile-time error! g() protected in A..
  //b.g(10); // Compile-time error! g() protected anche in B..

  cout << a.getX() << endl; // OK, getX() public in A..
  //cout << b.getX() << endl; //Compile-time error! getX() e' protected n B...

  cout << b.getSum() << endl; 
  cout << b.getSum(15) << endl;

  //azione di print() e' ristretta a propri campi
  //in quanto le caratteristiche di A sono 
  //ORA TUTTE INACCESSIBILI IN C IN QUANTO PRIVATE IN B 
  c.print(); 
}
