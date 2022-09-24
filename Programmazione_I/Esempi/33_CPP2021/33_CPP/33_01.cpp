#include <iostream>

using namespace std; 

/* 
  In C++ la parola chiave struct permette di definire classi. Unica differenza: 
  - se usata la parola chiave struct, i membri unqualified saranno public! 
  - se usata la parola class, i membri unqualified saranno private!  
*/ 
struct Struct_Test{

  //unqualified == public! 
  int a; 
  float b; 
  string s;

  //No need to specify ``public:''

  Struct_Test(){
    cout << "COS" << endl; 
  }

  void print(){
    cout << "s=" << s << ", b=" << b << ", a=" << a; 
  }
}; 


class Class_Test{

  //unqualified == private! 

  int a; 
  float b; 
  string s;

  //must specify public: !  
  public: 

  //C++ 
  Class_Test(){
    cout << "COS" << endl; 
  }

  //C++ 
  void print(){
    cout << "s=" << s << ", b=" << b << ", a=" << a; 
  }
}; 

int main(){

  Class_Test cltest;  
  Struct_Test stest; 

//  cltest.a = 10; // ERR 

  stest.a = 10; 
  stest.s = "Hello World!"; 
}
