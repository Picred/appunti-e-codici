#include <iostream>

using namespace std;

void f1(int &a){
  a = 10;
}

void f2(int *p){
  *p = 45;
}

void foo1(int *a){
  a[4] = 20;
}

int main(){
  
  int a = 2;
  int *ptr = &a; 
  //p stores the address of a
    
  int arr[5] = {1,2,3,4,5};
  
  ptr = arr; 
  //ptr stores the address of the first element of arr

  cout << a << endl; //2
  f1(a);
  cout << a << endl; //10 

  f2(&a);    
  cout << a << endl; //45 

  cout << arr[4] << endl;
  foo1(arr);
  cout << arr[4] << endl;     

  int c[20];
  //array are pointer constants
  //arr = &a; //ERR compilation 
  //arr = c; //ERR
     
}
