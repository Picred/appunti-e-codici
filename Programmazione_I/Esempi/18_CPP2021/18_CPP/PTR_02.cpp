#include <iostream>

using namespace std;

int main(){
  
  int vals[] = {4,3,2,1};
  
  int *ptr = vals;
  ptr++;

  cout << *ptr <<  endl; // print 3

  ptr+=2;
  cout << *ptr <<  endl; // print 1

  ptr-=1; // now point to 2 
       
}
