#include <iostream>
#include "moneta.h"

using namespace std;


int main()
{
    //numero di volte consecutive per testa o croce 
   const int GOAL = 3;

         int cont1 = 0, //contatore testa o croce
             cont2 = 0;

   Moneta moneta1; //due monete, vedi class moneta
   Moneta moneta2;
      
   srand(time(0));
 
  //finche' sia la prima che la seconda moneta non hanno fatto 
  //una sequenza di tre testa o croce consecutivi
   while (cont1 < GOAL && cont2 < GOAL) 
      {
         moneta1.effettuaLancio(); // lancio
         moneta2.effettuaLancio();

         cout << "Moneta 1: " << moneta1; // overloading operatore << 
         cout << "Moneta 2: " << moneta2 << endl;

         if (moneta1.getFaccia() == 'T')
             cont1++;
         else
             cont1 = 0;
         
         cont2 = (moneta2.testa() ? cont2+1 : 0); // operatore condizionale, testa
      }

   if (cont1 < GOAL)
      cout << "Vince la moneta 2";
   else 
    if (cont2 < GOAL)
      cout << "Vince la moneta 1";
    else
      cout << "Pari!";
            
   cout << endl;

   //system("PAUSE"); sui sistemi windows OK 
} // end main()
