#include <iostream>
#include "distributore_bevande.h"



DistributoreBevande::DistributoreBevande()
: serbatoioAcqua(10,10)
   {
     int monete [] = {5,10,20,10};
          
     bustine[0] = 50;
     bustine[1] = 25;
     bustine[2] = 10;

     costo[0] = 40;
     costo[1] = 70;
     costo[2] = 120;
     
     acqua[0] = 0.1f;
     acqua[1] = 0.6f;
     acqua[2] = 0.55f;                 

     cassa = new GestoreMonete();  
     cassa->depositaMonete(monete);     
     credito = 0;
   }

DistributoreBevande::~DistributoreBevande()
   {
     cout << "DISTRUTTORE";
      delete cassa;
   }


int DistributoreBevande::getCredito() const
  {
     return credito; 
  }   

  
void DistributoreBevande::inserisciMoneta (int valore)
  {                   
     if (cassa->depositaUnaMoneta(valore))
       {
         credito+=valore;
         cout << "CREDITO : " 
              << getCredito() 
              << " cent.\n";    
       }
     else
       {
         cout << "La moneta non è stata "
              << "riconosciuta ed è stata restituita.\n";
       }
   }
   
   
void DistributoreBevande::richiediBevanda (short bevanda)
   {
      int resto = getCredito() - costo[bevanda];
      
      if (resto < 0)
         cout << "Credito insufficiente.\n";
      else if (bustine[bevanda] <= 0)
         cout << "Bevanda esaurita.\n";
      else if (serbatoioAcqua.getCapacita() < acqua[bevanda])
         cout << "Acqua insufficiente.\n";
      else
         {
            serbatoioAcqua.preleva(acqua[bevanda]);
            bustine[bevanda]--;
            credito = resto;
            cout << "Bevanda erogata.\n";
         }         
   }


void DistributoreBevande::richiediResto()
   {           
      int resto = cassa->prelevaImporto(getCredito());
      
      cout << "Ritirare il resto di " 
           << resto 
           << " cent nell'apposito raccoglitore.\n";
         
      if (getCredito() != resto)
         {
           cout << (getCredito()-resto) 
                << " cent non erogabili!";
         }
      credito -= resto;
   }


void DistributoreBevande::stato()
   {
      cout << "INFORMAZIONI DI SERVIZIO\n";
      cout << (*cassa);
      
      cout << "\nBustine per : caffè("
           << bustine[CAFFE] 
           << "), the("
           << bustine[THE]
           << "), cioccolata("
           << bustine[CIOCCOLATA] << ")."; 
      
      cout << "\nACQUA nel serbatoio: " 
           << serbatoioAcqua.getQuantita()
           << " litri.\n\n";

      cout << "****************************\n"
           << "*          DISPLAY         *\n"
           << "****************************\n" 
           << (*this) 
           << "****************************\n"
           << endl;
   }
   
      
ostream &operator<< (ostream &stream, DistributoreBevande &d)
   {
     // Il secondo parametro è passato per &;
     // bisognerebbe definire il costruttore di copia  

      cout << "Il distributore fornisce:\n"
           << "    1) Caffe : " 
           << d.costo[d.CAFFE] << " cent\n" 
           << "    2) The   : " 
           << d.costo[d.THE] << " cent\n" 
           << "    3) Cioccolata : " 
           << d.costo[d.CIOCCOLATA] << " cent\n" 
           << "CREDITO: " 
           << d.getCredito() << " cent.\n"; 
          
      return stream;     
   }
   

