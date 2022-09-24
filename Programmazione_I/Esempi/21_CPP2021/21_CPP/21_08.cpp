#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "bersaglio.h"

using namespace std;

int main()
{
   const int NUM_LANCI = 1000000;  
   srand(time(0));
       
   Bersaglio b(10);
   Freccia   f;     // Attenzione a non scrivere "f();" !
   
   int totalePunti = 0;
   int i = 0;
   
   while (i<NUM_LANCI) 
     {
        f.lancia(b);
        totalePunti += b.punteggio(f);
        i++;
     }
   cout << "Hai totalizzato " << totalePunti  
        << " punti su " << NUM_LANCI << " lanci.\n\n";
    
   return 0;

} // End main()
