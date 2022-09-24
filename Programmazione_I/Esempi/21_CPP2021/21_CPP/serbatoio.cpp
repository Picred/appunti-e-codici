#include <iostream>
#include "serbatoio.h"

/*
  Tre costruttori. 
*/
Serbatoio::Serbatoio (float _capacita): Serbatoio(_capacita, 0, "NO_NAME")
   {
//      capacitaTotale   = _capacita;
 //     quantitaPresente = 0; // valore di default
  //    name = string("NO_NAME");
   }


Serbatoio::Serbatoio (float _capacita,
		      float _quantita): Serbatoio(_capacita, _quantita, "NO_NAME")
   {
//      capacitaTotale   = _capacita;
 //     quantitaPresente = _quantita;
  //    name = string("NO_NAME");
   }

Serbatoio::Serbatoio (float _capacita,float _quantita, string name)
   {
      cout << "Costruttore serbatoio..." << endl; 
      capacitaTotale   = _capacita;
      quantitaPresente = _quantita;
      this->name = name; 
   }
  
   
float Serbatoio::getCapacita () const
   {
      return  capacitaTotale;
   }
 
   
float Serbatoio::getQuantita () const
   {
      return  quantitaPresente;
   }
 
   
void Serbatoio::deposita (float _quantita)
   {
      quantitaPresente += _quantita; 
      if (quantitaPresente > capacitaTotale)
         {      
            cout << "Serbatoio " << name << ",  ATTENZIONE: "
                 << "Il liquido e' traboccato!\n";
            quantitaPresente = capacitaTotale;
         }
   }

   
float Serbatoio::preleva (float _quantita)
   {
      float quantitaPrelevata;
      
      if (quantitaPresente >= _quantita)
         {
           quantitaPrelevata = _quantita; 
           quantitaPresente -= _quantita;
         } 
      else
         {
           cout << "ATTENZIONE: " 
                << "La quantità richiesta non"
                << " è presente all'interno"  
                << " del serbatoio!\n";
           quantitaPrelevata = quantitaPresente;
           quantitaPresente  = 0;
         }
         
      return  quantitaPrelevata;
   }

 
float Serbatoio::svuotaTutto ()
   {
      float quantitaPrelevata = quantitaPresente;
      quantitaPresente = 0;
      return quantitaPrelevata;
   }
   
void Serbatoio::riempiTutto ()
   {
      quantitaPresente = capacitaTotale;
   }
   
bool Serbatoio::pieno () const
   {
      return (quantitaPresente == capacitaTotale);
   }
      
bool Serbatoio::vuoto () const
   {
      return (quantitaPresente < LIMITE_INFERIORE);
   }
   
bool Serbatoio::piuDiMeta () const
   {
      return (quantitaPresente > capacitaTotale / 2.0);
   }

string Serbatoio::getName() const
  {
    return name;
  }
   
ostream &operator<< (ostream &stream, Serbatoio s)
   {
      cout << "Il serbatoio " << s.getName() << " contiene " 
           << s.getQuantita() 
           << " litri su " << s.getCapacita() 
           << " di capacita'. STATO: ";
      
      if (s.quantitaPresente < s.capacitaTotale * 0.1)
         cout << "Allarme ROSSO.";
      else if (s.quantitaPresente < s.capacitaTotale * 0.25)
         cout << "Allarme Giallo.";
      else
         cout << "Normale.";
         
      cout  << endl;  
      return stream;     
   }
