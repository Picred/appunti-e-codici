#include <iostream>

using namespace std; 

class ClasseX{
  int x; 

  public: 
    ClasseX(int a){
      x = a;
    }

    int getX(){
      return x; 
    }
};

int main(){
  //int &rr = {1}; // NO! rr non e' const!
  const int &r = {1}; // OK: {1} rappresenta un rvalue

  const ClasseX &objRef = {1}; // OK: objRef e' const

  //ClasseX &objRef1 = {10}; // NO! si legga l'errore del compilatore..
  
}
