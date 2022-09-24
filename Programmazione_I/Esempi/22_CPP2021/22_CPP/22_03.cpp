#include <iostream>
#include <ctime>

using namespace std; 

class A{
  
    int x, y;
  
    public: 

      A(int a, int b){
	x = a;
	y = b;
      }
      
      int getX(){
	return x; 
      }     

      int getY(){
	return y; 
      }     

      void setX(int a){
       x = a; 
      }

      void sety(int b){
       y = b; 
      }

}; 

int main(){
  
  //Ok, costruttore di conversione: {int,int}-> A(int,int) 
  A arr[10]={{1,2},{3,4},{5,6},{7,8},{9,10},{11,12},{13,14},{15,16},{17,18},{19,20}}; //OK
  //si provi:
//   A arr[10]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //NO!

  for(int i=0; i<10; i++)
    cout << arr[i].getX() << " " << arr[i].getY() << endl;  
    
}
