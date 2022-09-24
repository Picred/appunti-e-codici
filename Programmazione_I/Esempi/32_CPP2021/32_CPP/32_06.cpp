#include <iostream>

using namespace std;

/* 
   Questo programma usa una funzione che 
   implementa la ricerca dicotomica.
*/


// Ricerca dicotomica o binaria
static int binarySearch( int array[], int length, int key ) 
  {
    int low = 0;            // limite sinistro
    int high = length - 1;  // limite destro
    int middle;             // centro

    while ( low <= high ) 
       {
         middle = ( low + high ) / 2;
            
         if ( key == array[ middle ] )  // trovato! 
              return middle;   
         else if ( key < array[ middle ] )   // else?!?
                   high = middle - 1;  // ricerca nella prima meta'
              else
                   low = middle + 1;   // ricerca nella seconda meta'
         }
         
      return -1;   // non trovato!
   }


int main()
{ 
   int numeri[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

   cout << "Risultati ricerche : " 
        << binarySearch (numeri, 8, 8) << "  " 
        << binarySearch (numeri, 8, 2) << "  " 
        << binarySearch (numeri, 8, 9) << "  " 
        << binarySearch (numeri, 8, 0) << endl;
        
   return 0;
}
