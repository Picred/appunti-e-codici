#include <iostream>

using namespace std;

int main(){

  int a, b, c, min;

  a=10;
  b=20;
  c=15;

  if(a<b)
    cout << "min(a,b)=" << a << endl;
  else 
    cout << "min(a,b)=" << b << endl; 
  
  //Conditional operator
  //Find the minimum among two numbers
  min = (a<b ? a : b);
  cout << "min(a,b) is " << min << endl;
  cout << "min(a,b) is " << (a<b ? a : b) << endl;
//  cout << 3 << endl;
//  cout << b << endl;

  //a,b,c
  if(a<b)
    if(a<c)
      cout << "Min(a,b,c)=" << a << endl;
    else      
      cout << "Min(a,b,c)=" << c << endl;
  else 
    if(b<c)      
      cout << "Min(a,b,c)=" << b << endl;
    else  
      cout << "Min(a,b,c)=" << c << endl;
    

  //conditional operator 
  //find the minimum among three numbers
  min = ( a<b ? (a < c ? a : c) : (b<c ? b : c) );

  cout << "min(a,b,c) is " << min << endl;

  //no min variable, just cout statement!
  cout << "min(a,b,c) is " << (a<b ? (a < c ? a : c) : (b<c ? b : c)) << endl;

  return 0;  
}
