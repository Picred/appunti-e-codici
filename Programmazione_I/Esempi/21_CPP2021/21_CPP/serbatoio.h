#ifndef SERBATOIO_H
#define SERBATOIO_H

#include <string>
using namespace std;


//***************
class Serbatoio {
//***************

public:  

   Serbatoio (float _capacita);
   Serbatoio (float _capacita, float _quantita);
   Serbatoio (float _capacita, float _quantita, string name);
   
   float getCapacita () const;
   float getQuantita () const;
   void  deposita (float _quantita);
   float preleva (float _quantita);
   float svuotaTutto();
   void  riempiTutto();
   bool  pieno() const;
   bool  vuoto() const;
   bool  piuDiMeta() const;
  string getName() const;

   friend ostream &operator<< (ostream &stream, Serbatoio s);
   
private: 
        
   float capacitaTotale;
   float quantitaPresente;
   string name;

   static constexpr  float LIMITE_INFERIORE = 0.01f;

};   // end class Serbatoio

#endif
