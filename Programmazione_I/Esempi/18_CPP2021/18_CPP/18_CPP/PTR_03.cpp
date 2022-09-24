#include <iostream>

using namespace std;

int main(){

  float c = 0.4;
  
  //pointers initialization
  float *ptr = NULL;

  if(!ptr)
    cout << "ptr is an invalid pointer!" << endl;

  else 
    cout << "ptr is not NULL!" << endl;
    
  ptr = &c;

  if(!ptr)
    cout << "ptr is an invalid pointer!" << endl;

  else 
    cout << "ptr is not NULL!" << endl;
  
  int *p;
//  p = &c; //won't work!! 
    
     

}
