#include <iostream>
#include "conto_corrente.h"


ContoCorrente::ContoCorrente (string nominativo, 
                              long numero, 
                              double primoDeposito)
   {
      nominativoCliente = nominativo;
      numeroDiConto = numero;
      saldo = primoDeposito;
   }

      
void ContoCorrente::setNominativo (string nominativo)
   {
      nominativoCliente = nominativo;
   }

   
string ContoCorrente::getNominativo() const
   {
      return nominativoCliente;
   }

   
long ContoCorrente::getNumeroDiConto() const
   {
      return numeroDiConto;
   }

   
double ContoCorrente::getSaldo() const
   {
      return saldo;
   }

   
void ContoCorrente::deposita (double valore)
   {
      if (valore <= 0)  
      {
         cout << "ERRORE: La cifra deve "
              << "essere positiva.\n";
      }
      else
         saldo = saldo + valore - COSTO_OPERAZIONE;
   }

   
void ContoCorrente::preleva (double valore)
   {
      if (valore <= 0)  
      {
         cout << "ERRORE: La cifra deve "
              << "essere positiva.\n";
      }
      else
         if (valore > saldo)
         {
            cout << "ERRORE: Il saldo del "
                 << "conto corrente è insufficiente.\n";
            cout << "Conto: " << numeroDiConto << endl
                 << "Richiesto: " << valore << endl
                 << "Disponibile: " << saldo << endl << endl;
         }
         else
            saldo = saldo - valore - COSTO_OPERAZIONE;
   }

   
double ContoCorrente::maturaInteressi()
   {
      const double PERCENTUALE_INTERESSE = 2.35; 

      saldo += (saldo * PERCENTUALE_INTERESSE / 100);
      
      return saldo;
   }

         
ostream &operator<< (ostream &stream, ContoCorrente c)
   {
      cout << c.numeroDiConto << "\t"  
           << c.nominativoCliente  
              << "\t" << c.getSaldo()  
              << "\t euro.";
         
      cout  << endl << endl;  
      return stream;     
   }
   
