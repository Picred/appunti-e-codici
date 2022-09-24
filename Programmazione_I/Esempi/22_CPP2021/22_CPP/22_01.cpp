#include <iostream>
#include <ctime>

using namespace std; 

class A{
  
    int x;
  
    public: 
      //A() costruttore di default
      int getX(){
	return x; 
      }     

      void setX(int y){
       x = y; 
      }

}; 

int main(){
  
  A arr[10]; //OK costruttore senza paramemtri

  for(int i=0; i<10; i++){
    arr[i].setX(i+1); 
    cout << arr[i].getX() << endl; 
  } 
    
}
