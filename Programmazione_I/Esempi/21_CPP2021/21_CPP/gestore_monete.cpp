#include <iostream>
#include "gestore_monete.h"



GestoreMonete::GestoreMonete()
   {
      short i = 0;
      while ( i < TIPI_MONETE ) 
         deposito[i++] = 0;
      // Buona pratica di programmazione!
   }


   
short GestoreMonete::convertiValore (int valore)
   {
      switch (valore)
      {
         case 50 : return CINQUANTA;
         case 20 : return VENTI;
         case 10 : return DIECI;
         case  5 : return CINQUE;
         default : return -1;
      }
   }

   
short GestoreMonete::convertiMoneta (short moneta)
   {
      switch (moneta)
      {
         case CINQUANTA : return 50;
         case VENTI     : return 20;
         case DIECI     : return 10;
         case CINQUE    : return  5;
         default        : return -1;
      }
   }


   
bool GestoreMonete::depositaUnaMoneta (int valore)
   {   
      short moneta = convertiValore(valore);
      if (moneta == -1)
        {
          cout <<"Errore: Moneta mai coniata!\n";
          return false;
        }
      deposito[moneta]++;
      return true;
   }


bool GestoreMonete::depositaMonete (int quantita [])
   {
      short i = 0;
      while (i<TIPI_MONETE) 
        {
         if (quantita[i] > 0)  
            deposito[i] += quantita[i];
         i++;
        }        
      return true;  
   }
   
   
int GestoreMonete::getTotaleDepositato ()
   {
      short i = 0;
      int totale = 0;
      while (i<TIPI_MONETE)
        {         
          totale += deposito[i] * convertiMoneta(i);
          i++; 
        }
      return totale;
   }
   
   
bool GestoreMonete::prelevaUnaMoneta(int valore)
   {
      short moneta = convertiValore(valore);
      if (moneta == -1)
        {
          cout << "Errore: Moneta mai coniata!\n";
          return false;
        }
      if (deposito[moneta] <= 0)
        {
          cout << "Errore: Moneta esaurita.\n";
          return false;
        }
      deposito[moneta] --;  
      return true;
   }


int GestoreMonete::prelevaImporto(int importo)
   {
     int totale = getTotaleDepositato();
     int prelevato = 0; 

     if (importo > totale)
        {
          cout << "Errore: Importo non disponibile.\n";
          return 0;
        }
        
      short i=0;
      while (i<TIPI_MONETE)
        {        
          int valore = convertiMoneta(i);
          int daPrelevare = importo/valore;
          if ( deposito[i] < daPrelevare )
            {
              daPrelevare = deposito[i]; 
            }
          prelevato+= daPrelevare*valore;  
          importo-= daPrelevare*valore;
          deposito[i]-=daPrelevare;
          i++;  
        }
      
      if (importo != 0)
        {
          cout << "Attenzione: Non è possibile "
               << "restituire l'importo esatto.\n";
        }

      return  prelevato;
   }



int GestoreMonete::prelevaTutto()
   {
      int totale = getTotaleDepositato();
      int i=0;
      while (i<TIPI_MONETE)
         deposito[i++] = 0;
        
      return totale;
   }


      
ostream &operator<< (ostream &stream, GestoreMonete gm)
   {
      cout << "IL DEPOSITO contiene :\n";

      short i = 0;
      while (i < gm.TIPI_MONETE)
        {         
          int valore = gm.convertiMoneta(i);
          cout << gm.deposito[i]
               << " monete da " 
               << gm.convertiMoneta(i) 
               << " centesimi di euro.\n";
          i++; 
        }
      cout << "Per un totale di " 
           << gm.getTotaleDepositato()
           << " centesimi di euro.\n";         
           
      return stream;     
   }
   

