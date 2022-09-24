#include <iostream>

using namespace std; 

int main(){
  
  int v[] = {10, 20, 30, 40}; 
  int *p = v; 

  cout << " v=" << v << "\n p=" << p << "\n\n v[2]=" << v[2] << "\n p[2]=" << p[2] <<  "\n\n (v+2)=" << (v+2) << "\n (p+2)=" << (p+2) <<  "\n\n";  

  cout << " (v+sizeof(int))=" << (int *) ((unsigned long int) v + sizeof(int)) << "\n (p+1)=" << (p+1) <<  endl; 
  
  p[1]=100;
  cout << v[1];
}
