#ifndef GESTORE_MONETE_H
#define GESTORE_MONETE_H

#include <string>

using namespace std;


//*******************
class GestoreMonete {
//*******************

public:  
  
   GestoreMonete();

   bool depositaUnaMoneta (int valore);
   bool depositaMonete (int quantita []);
   int  getTotaleDepositato();
   bool prelevaUnaMoneta(int valore);
   int  prelevaImporto(int importo);
   int  prelevaTutto();
    
   friend ostream &operator<< (ostream &stream, GestoreMonete gm);
   

private: 
        
   static const short TIPI_MONETE = 4;

   static const short CINQUANTA = 0;
   static const short VENTI     = 1;
   static const short DIECI     = 2;
   static const short CINQUE    = 3;
   
   int deposito [TIPI_MONETE];

   short convertiValore (int valore);
   short convertiMoneta (short moneta);


}; // End class GestoreMonete


#endif
