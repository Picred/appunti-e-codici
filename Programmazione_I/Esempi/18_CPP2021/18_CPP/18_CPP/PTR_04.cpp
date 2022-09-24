#include <iostream>

using namespace std;

int main(){
  
  int a, b;

  int *p1=&a, *p2=&b;

  cout << " p1 is " << (p1==p2 ? " not different " : " different ") << "from p2" << endl; 

  p1 = &b;

       
  cout << " p1 is " << (p1==p2 ? " not different " : " different ") << "from p2" << endl; 

}
