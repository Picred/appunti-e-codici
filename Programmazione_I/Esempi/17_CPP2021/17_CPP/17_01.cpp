#include <iostream>

using namespace std; 

int main(){
  
  int num = 10; 
  int *p = &num;
  
  int *g;

  int *v = NULL;
  int *w = nullptr;   //C++11
  double *l = NULL;

  cout << " p=" << p << "\n &num=" << &num << "\n\n num=" << num << "\n *p=" << *p << endl;  

  cout << "\nv=" << v << ", w=" << w << endl;

  *p = 35; 
  v = w = p; 
  //v = p; 
  //w = p; 
  
  *v = 20; 

  cout << "\nnum=" << num << " *p=" << *p << endl; 
  
}
