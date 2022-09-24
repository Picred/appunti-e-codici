#include <iostream>
#include "moneta.h"

using namespace std;

/* 
  Conta il numero di 
  volte in cui esce testa ed 
  il numero di volte in cui esce croce. 
*/
int main()
{
    const int NUM_LANCI = 10;
    Moneta penny; 
    int testa = 0, croce = 0;
    int i = 0;
    
    srand(time(0));
    
    while ( i < NUM_LANCI )
      {
         penny.effettuaLancio();

         if ( penny.getFaccia() == 'T') 
            testa++;
         else
            croce++;

         cout << penny;
         i++;
      }

    cout << "Numero di lanci: " << NUM_LANCI << endl;
    cout << "Numero di teste: " << testa << endl;
    cout << "Numero di croci: " << croce << endl;

    return 0;
} // end main()
