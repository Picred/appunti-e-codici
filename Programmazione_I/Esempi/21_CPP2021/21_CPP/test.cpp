#include "frazione.h"
#include <iostream>

using namespace std; 

int main(){
  
//  Frazione frazioni[10]; 

  //1 
  Frazione frazioni[3] = {Frazione(2,5),Frazione(3,4),Frazione(6,7)}; 

  //2
  Frazione frazioni1[3] = {{2,5}, {2,5}, {2,5}};

  //3
  Frazione *frazioniPtr[10];
  for(int i=0; i<10; i++)
    frazioniPtr[i] = new Frazione(i+2, i+1); 
}
