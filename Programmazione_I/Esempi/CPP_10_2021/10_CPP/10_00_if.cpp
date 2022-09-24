#include <iostream>

using namespace std;

int main(){

  int a, b;
  a=10;
  b=20;

  if(a<b)
    cout << "a < b" << endl;

  else 
    cout << "a >= b" << endl;

  //boolean expression ?? 
  int c=5;
  if(c) //it means c!=0
    cout << "c!!!" << endl; 

  if(c!=0) //it means c!=0
    cout << "c!!!" << endl; 

  //OR
  if(c==0 || a<b) //L1
    cout << "c is zero, OR a less than b" << endl;

  else//???
    cout << "c not zero, OR a greater than b" << endl;

  //AND 
  if(c==0 && a<b) //both the conditions must e verified
    cout << "c is zero AND a is less than b!!" << endl;

  //NOT 
  if(!(c==0))
    cout << "c!!!" << endl; 

  //another way to write the logical expression L1
  if(!(c!=0 && a>=b))
    cout << "c is zero, OR a less than b" << endl;


  return 0;
}
