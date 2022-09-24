#include <iostream>

#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
  int a = 10;
  int b = 20;

  //A. pointer to a constant: the value of the pointer can change, 
  // but the data the pointer points to can change 
  const int *ptoconst = &a; // a cannot be modified, p is declared to point to a const

  //*p = 20; // Compilation ERROR! *ptr is declared a read-only!

  cout << *ptoconst << endl; // OK

  //B. constant pointer, the value of the pointer CANNOT change 
  //the data the pointer points to can change 
  int* const constptr = &a; // ptr is a (constant) pointer to the variable a 

  *constptr = 45; // OK
  //ptr = &b; //Compilation ERROR, ptr is read-only!

  //C. Both the pointer and the data the 
  const int * const const_ptr_toconst = &b;

  cout << *const_ptr_toconst << endl; // OK
  
  return 0;
}

