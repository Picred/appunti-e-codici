#include <iostream>

using namespace std;

/* 
   Questo programma esegue una ricerca lineare 
   in un array ordinato in senso crescente
   che si interrompe se :
      1) non esiste il valore ricercato,
      2) si trova il valore ricercato,
      3) si sta esaminando un elemento 
	maggiore del valore ricercato.
*/

int main()
{ 
   int  A[100]; 
   int  i = 1;    // indice dell'array
   int  numero;   // contiene il valore da ricercare
   bool trovato   = false;  // esito della 2)  
   bool trovabile = true;   // esito della 3)

   cout << "Inserisci il numero da ricercare (1..10) : ";
   cin >> numero;
   cout << endl;

   srand(time(0));  
   A[0] = 1;  
   while (i<100) 
      {
        A[i] = A[i-1] + (rand()%2 + 1);
        i++;     
      }
             
   i = 0;
   while ( (i<100) && (!trovato) && trovabile ) 
      {
        if (A[i] == numero)   trovato   = true;
        if (A[i] > numero)    trovabile = false;
        i++;
      }
                     
   if ( trovato )  
        cout << "Trovato nella posizione " << (i-1) << endl;
   else
        cout << "Non esiste (" << A[i-1] << ")!" << endl;
        
   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
} // End main()
