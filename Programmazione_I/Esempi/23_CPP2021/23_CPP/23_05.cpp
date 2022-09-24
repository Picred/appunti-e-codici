#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int test(int x){
  cout << x << endl; 
//  int x;  // NO!  
  {
    int x=10; // ok ridefinizione di x in blocco 
    double y = 5*x;
    cout << x << endl; 
    return (int) y;
    }
}


int main()
{ 
   int  unInt = 47;
     
   // Qual e' il ciclo di vita delle seguenti variabili ? 

   {
      int a = 2,  b;  
        
      b = (int) sin(a);
         
      {
	//a e b visibili
         int c = 5; //c e' definita e visibile solo in questo blocco
         int d = a + c; //stessa cosa per d
         int a=100;          // OK RIDEFINIRE A! 
	  //a locale a questo blocco oscura a del blocco superiore
         cout << a << endl;  
      }
      
//       a += c;   // Errore di compilazione
                      // "c" non e' visibile
        
      a += unInt; 
   }
      
   for (int i=3;  i<7;  i+=2)
      {
         int inutile;   // Ciclo di vita ?
         inutile+=2;
         cout << i << " (" << inutile << ")\n";
         i--;        // (Pessima idea ... 
      }
         
    // unInt = i;    // Errore di compilazione
                    // "i" non e' visibile
          
    test(-10); 

} // End main()
