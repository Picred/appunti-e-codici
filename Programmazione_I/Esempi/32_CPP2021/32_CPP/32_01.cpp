#include <iostream>

using namespace std;

/* 
  Ricerca lineare completa in uno array 
*/


int main()
{ 
   int A [100]; 
   int i = 0;      // indice dell'array
   int numero;     // contieneil valore da ricercare

   cout << "Inserisci il numero da ricercare (1..10) : ";
   cin >> numero;
   cout << endl;

   srand(time(0));
   while (i<100) 
      {
        A[i] = rand()%10 + 1;
        i++;     
      }
         
   i = 0;
   while (i<100) 
      {
        if (A[i] == numero) 
            cout << "Trovato nella posizione " << i << endl;
        i++; 
      }

    return 0; 
} // End main()
