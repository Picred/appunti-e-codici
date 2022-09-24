#include <iostream>

using namespace std;

/* 
   Questo programma esegue una ricerca lineare 
   con sentinella in un array che si interrompe alla prima 
   occorrenza trovata
*/



int main()
{ 
   int  A[100+1]; // Locazione per la sentinella
   int  i = 0;    // indice dell'array
   int  numero;   // contiene il valore da ricercare
   bool trovato = false; // esito della ricerca  

   cout << "Inserisci il numero da ricercare (1..10) : ";
   cin >> numero;
   cout << endl;

   srand(time(0));
   while (i<100) 
      {
        A[i] = rand()%10000 + 1;
        i++;     
      }
      
   A[i] = numero;   // la sentinella !
         
   i = 0;
   while (A[i] != numero)    i++;
       
   // while (A[i++] != numero);    Funziona ? 
       
            
   if ( i != 100 )  
        cout << "Trovato nella posizione " << i << endl;
   else
        cout << "Non esiste !" << endl;
        
    return 0; 
} // End main()
