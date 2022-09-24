#ifndef DISTRIBUTORE_BEVANDE_H
#define DISTRIBUTORE_BEVANDE_H

#include <string>
#include "serbatoio.h"
#include "gestore_monete.h"

using namespace std;


//*************************
class DistributoreBevande {
//*************************

public:  

   static const short  CAFFE = 0;
   static const short  THE = 1;
   static const short  CIOCCOLATA = 2;
  
   DistributoreBevande();
   ~DistributoreBevande();

   int getCredito() const;
   void inserisciMoneta (int valore);
   void richiediBevanda (short bevanda);
   void richiediResto();
   void stato();
    
   friend ostream &operator<< (ostream &stream, 
                               DistributoreBevande &d);
   

private: 
           
   int   bustine [3];
   int   costo [3];
   float acqua [3];
      
   Serbatoio serbatoioAcqua;
   GestoreMonete *cassa;
   int credito;      


}; // End class DistributoreBevande


#endif
