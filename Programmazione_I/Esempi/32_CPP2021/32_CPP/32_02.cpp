#include <iostream>

using namespace std;

/* 
    Ricerca lineare in un array che si interrompe 
    alla prima concorrenza trovata.
*/

int main()
{ 
   int  A[100]; 
   int  i = 0;    // indice dell'array
   int  numero;   // contiene il valore da ricercare
   bool trovato = false; // esito della ricerca  

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
   while ((i<100)  && (!trovato)) 
      {
        if (A[i] == numero)   trovato = true; 
        i++;   // else ???
      }
         
   if ( trovato )  
        cout << "Trovato nella posizione " << (i-1) << endl;
   else
        cout << "Non esiste !" << endl;
      
    return 0; 
} // End main()
