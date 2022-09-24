#include <iostream>

using namespace std;

/* 
   Esempio di utilizzo del ciclo "for".
   
   L'istruzione di "debug" nel "for" non serve a nulla,
   se non a "seguire meglio" ed eventualmente correggere 
   l'esecuzione del codice.
   Se non utile, in un programma reale, andrebbe rimossa,
   infatti, essa richiede un accesso all'ouput per ogni ciclo
   rallentando di molto l'esecuzione del programma.
*/


int main()
{ 
   int sum = 0;  // somme parziali
   int current;
			
   for (current = 1;  current <= 10;  current++) 
     { 
       cout << "In questa esecuzione del ciclo il contatore vale : " << current << endl;

       sum += current; // aggiornamento accumulatore 
     } 
       
   cout << "La somma dei numeri da 1 a 10 è " << sum << endl; 
   
   system("PAUSE");
   return EXIT_SUCCESS;
}
