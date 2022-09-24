#include <iostream>
#include "distributore_bevande.h"

using namespace std;

  

int main()
{ 
   DistributoreBevande d;

   d.stato();
   cout << "Inserimento monete.\n";    
   d.inserisciMoneta(50);
   d.inserisciMoneta(50);

   cout << "Richiesto Caffè.\n"; 
   d.richiediBevanda(d.CAFFE);
   cout << endl;
   d.stato();
      
   cout << "Richiesto resto.\n"; 
   d.richiediResto();
   d.stato();
   
   cout << endl;
   
   return 0;

} // End main()

