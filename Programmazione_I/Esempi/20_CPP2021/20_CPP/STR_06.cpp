#include <iostream>
#include <cstring> 
#include <cstdlib> 
#include <cstdio>

using namespace std;

int main(){
  
  const int a=123456;
  const int b = 100;
  
  char num[100];

  cout << "** Using sprintf() " << endl;  

  if(sprintf(num, "%d %d", a, b)<0)
    cout << "Error converting " << a << " as string" << endl;
  else
    cout << "String num: " << num << endl; 

  double x = 1234.2345;
  if(sprintf(num, "%d e' intero, mentre %.2f e %.4f sono in virgola mobile!", a, x, x)<0)
    cout << "Error converting " << a << " as string" << endl;
  else
    cout << "String num: " << num << endl; 

  //Remember you can use stringstream..

  return 0;
}
