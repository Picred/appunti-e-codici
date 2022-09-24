#include <iostream>

using namespace std; 

class Test{}; 

int main(){

  //myint as alias of int  (C++)
  using myint = int;  

  //MyTest alias of test; 
  using MyTest = Test; 

  //typedef is from C
  typedef Test MyTest1; 

  myint tr; 

}
