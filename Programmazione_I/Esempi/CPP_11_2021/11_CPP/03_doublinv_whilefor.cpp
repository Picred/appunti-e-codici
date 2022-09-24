#include <iostream>

using namespace std;

/* Ad ogni aggiornamento della variabile balance, il programma stampa
  una linea di testo formata dal carattere '#' ripetuto 
tante volte quanti sono i multipli di 1000 del capitale accumulato
*/

int main()
{  
   const double RATE = 5;
   const double INITIAL_BALANCE = 10000;
   const double TARGET = 3 * INITIAL_BALANCE;

   double balance = INITIAL_BALANCE;
   int year = 0;

   while (balance < TARGET)
   {  
      year++;
      double interest = balance * RATE / 100;
      balance = balance + interest;
      //cout << "Balance: " << balance << endl;
      int n = (balance/1000);
      for(int i=0; i<n; i++)
	cout << '#'; 
      cout << endl;
   }

   cout << "The investment doubled after "
      << year << " years: " << balance << endl;

   return 0;
}
