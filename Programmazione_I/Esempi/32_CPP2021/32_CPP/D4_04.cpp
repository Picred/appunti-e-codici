#include <iostream>
#include <cmath>

using namespace std;

/* 
   Questo programma costruisce un righello 
   con una doppia ricorsione. Ogni tacca viene 
   posta dividendo a meta' lo spazio a disposizione.
   La dimensione delle tacche decresce al decrescere 
   della scala considerata.    
*/


// il righello viene memorizzato nella porzione
// del vettore "riga" che va dall'indice "l" ad "r";
// il valore "h" rappresenta lo spessore della tacca
// sul righello.   
void righello ( int riga[], int l, int r, int h )
   {   
      if ( h > 0 )
         {  
            int m = (l+r) / 2; 
            riga[m] = h;
            righello (riga, l, m, h-1);
            righello (riga, m, r, h-1);
         }       
   }


// visualizza un righello
void visualizza ( int riga [], int length)
  {   
    for (int j = 1;   j < length;   j++)
      {
         for (int i = 1;   i <= riga[j];    i++)
             cout << "-";
          
         cout << endl;
      }
   }


int main()
{ 
   int tipiDiTacche = 3;
   int numeroTacche = (int) pow(2.0f, tipiDiTacche);
      
   int R[numeroTacche];
      
   righello (R, 1, numeroTacche, tipiDiTacche);
      
   visualizza (R, numeroTacche);  
 
   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
} // End main()
