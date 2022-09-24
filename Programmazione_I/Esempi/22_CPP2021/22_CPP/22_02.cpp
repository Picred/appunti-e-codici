#include <iostream>
#include <ctime>

using namespace std; 

class A{
  
    int x;
  
    public: 

      A(int y){
	x = y; 	
      }
      
      int getX(){
	return x; 
      }     

      void setX(int y){
       x = y; 
      }

}; 

int main(){
  
  //Ok, costruttore di conversione: int-> A(int) 
  A arr[10]={1,2,3,4,5,6,7,8,9,10}; //OK 
  //si provi: 
 // A arr[10]={1,2,3} ;
  // il compilatore non forzera' ulteriori inizializzazioni a zero come fa per i tipi primitivi

  for(int i=0; i<10; i++)
    cout << arr[i].getX() << endl;   
    
}
