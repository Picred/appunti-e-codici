#include <iostream>

#include <cstdlib>

using namespace std; 

/* 
* virtual vs costruttori e distruttori 
* 
* 
*/ 

class A{
  protected: 
    string s;
    string* str = new string(); 

  public:
    //virtual A() // Compile-time error! Il costruttore non puo' essere dichiarato 
		  //virtual..
    A(string k){
      cout << "A(" << k << ")"<<  endl; 
       s = k;
    }

    //distruttore classe base
    virtual ~A(){
      cout << "~A(" << s << ")"<<  endl; 
      delete str; 
    }

   virtual void f() { cout << "A[s=" << s << "].f()" <<  endl;}
};

class B: public A{
  
  public:
    B(string s): A(s){ cout << "B(" << s << ")" << endl; }
    ~B() { cout << "~B(" << s << ")" << endl; } 
    void f() { cout << "B[s=" << s << "].f()" << endl; }
};


class C: public A{
  float z; 

  public:
    C(string s): A(s){ cout << "C(" << s << ")" << endl; }
    ~C() { cout << "~C(" << s << ")" << endl; } 
    void f() { cout << "C[s=" << s << "].f()" << endl; }
};

int main(){

  srand(time(0));

  cout << "START stack allocation object B.." << endl; 
  B b1("b1"); 
  cout << "END stack allocation object B..\n" << endl; 

  cout << "START stack allocation object C.." << endl; 
  C c1("c1"); 
  cout << "END stack allocation object C..\n" << endl; 

  //puntatore al tipo base
  // tipo puntato da ptr non e' noto a compile-time
  A* ptr;
  if(rand()%2==0){
    cout << "START Dynamic allocation object B (ptr)" << endl; 
    ptr = new B("ptr");
    cout << "END Dynamic allocation object B\n" << endl << endl; 
    }
  else{
    cout << "START Dynamic allocation object C (ptr)" << endl;
    ptr = new C("ptr");   
    cout << "END Dynamic allocation object C\n" << endl << endl;
  }

  cout << "Stack allocation object B, variable of type A (slicing).." << endl; 
  //viene creato un oggetto da copiare in a..
  A a = B("a");
  cout << "END Stack allocation object B, variable of type A" << endl << endl; 

  cout << "START assigning to a variable of type A object b1 (B)" << endl; 
  cout << "NO ANY costructor is invoked here, only memberwise copy.." << endl;  
  A a1 = b1; //copia della sola parte della classe A, le informazioni di B si perdono
  cout << "END assigning to a variable of type A object b1 (B)" << endl << endl; 

  cout << "Stack allocation object B, variable of type B.." << endl; 
  B b = B("b"); 
  cout << "END Stack allocation object B, variable of type B" << endl << endl; 

  cout << "START Destroying ptr.." << endl; 
  //Il compilatore dara un WARNING! 
  //Infatti il distruttore della classe base non e' stato dichiarato virtual, 
  //quindi sara' invocato SOLO il distruttore della classe base...
  delete ptr; // chiamate a distruttori classe base e/o classe derivata ? 
  //in assenza di virtual, unica chiamata: distruttore della classe base
  cout << "END Destroying ptr\n" << endl << endl;

  cout << "END MAIN (start destroying local data..)" << endl; 
}
