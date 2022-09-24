#include <iostream>

using namespace std;

/* 
   Questo programma risolve il problema
   della Torre di Hanoi mediante una funzione 
   definita con una doppia ricorsione.
*/



// Trova le mosse necessarie per spostare "n" dischi
// dal palo "sorgente" al palo "destinazione" 
// usando il palo d'appoggio "temporaneo"
void hanoi ( int n, int sorgente, 
                    int temporaneo, 
                    int destinazione )
   {   
      if (n==1)
         {   
            cout << sorgente << " --> " << destinazione << endl;
            return;
         }  // else ???
      hanoi(n-1, sorgente,   destinazione, temporaneo);
      hanoi(1,   sorgente,   temporaneo,   destinazione);
      hanoi(n-1, temporaneo, sorgente,     destinazione);
   }

   
// Conta le mosse necessarie per la Torre di Hanoi.
// L'input e' identico a quello della funzione precedente  
int conta ( int n, int sorgente, 
                   int temporaneo, 
                   int destinazione )
   {   
      if (n==1)  return 1;
      
      return 
         (
          conta(n-1, sorgente, destinazione, temporaneo) +
          conta(1,   sorgente, temporaneo, destinazione) +
          conta(n-1, temporaneo, sorgente, destinazione) 
         );
   }
   

int main()
{ 
  int dischi = 5;
   
  hanoi (dischi, 1, 2, 3);
      
  cout << "Il numero minimo di mosse per " 
       << "spostare " << dischi << " dischi e' "  
       << conta(dischi, 1, 2, 3) << endl;
            
  system("PAUSE");    // ns. comodo!
  return 0;
} // End main()
