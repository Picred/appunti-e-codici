#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct my_struct{
  int a; int b;
  float *ptr;
};

int main()
{
  struct my_struct s1;
  struct my_struct *s2 = &s1;
  
  s1.a = 20;
  s2->b= 10;

  //* e' operatore di "indirezione"
  //-> e' operatore 

  s1.ptr = new float;
  
  *s1.ptr= 20.2; // 
  cout << *s1.ptr << endl;
  
  *(s2->ptr)=10.5;  //A s2->ptr e' come (*s2).ptr ma piu' semplice da leggere
  cout << *s1.ptr << endl;

  *(*s2).ptr=10.5;   // equivalente ad A
  cout << *s1.ptr << endl;

}

