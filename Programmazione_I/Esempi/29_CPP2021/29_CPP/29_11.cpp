#include <iostream>

using namespace std; 

/* 
Lista di inizializzazione per passaggio di parametri 
a costruttori classe base; 

Costruttori e distruttori. 
*/ 

class A{
  int x;
  void add(int z) { x+=z; }

  public:
/*    A(){ //costruttore di default
      cout << "A()" << endl;
      x = 10;
    }*/
    A(int v){ //costruttore con un parametro 
      cout << "A(int)" << endl; 
      x = v; 
    }


    ~A(){
      cout << "~A()" << endl; 
    }

    int getX() { cout << "A.getX()" << endl; return x;}

  protected: 
    void g(int alpha){ cout << "A.g()" << endl; add(alpha);}
};

class B: public A{
  float y; 

  public:
    B(float v): y(v), A((int) (v+0.5)){ // lista di inizializzazione
      cout <<  "B(float)" << endl; 
      //y = v;
    }

    B(){ // invocazione automatica costruttore di default
      cout << "B()" << endl; 
      y = 0.5; 
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
      return y + alpha + getX(); 
    }    

    ~B(){
      cout << "~B()" << endl; 
    }
};

int main(){  
  B b1;
  B b2(14.6); 
}
