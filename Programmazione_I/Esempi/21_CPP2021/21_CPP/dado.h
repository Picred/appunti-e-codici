#ifndef DADO_H // Include guard. Vedi qui: https://it.wikipedia.org/wiki/Include_guard
#define DADO_H

#include <string>
using namespace std;


class Dado {
      
public:  //***************************

   Dado();

   Dado (time_t seed);  // altro costruttore, permette di inizializzare il generatore random

   //Cosa significa const dopo la dichiarazione del metodo? 
    //getUltimoLancio() NON potra' contenere codice che "modifica" oggetto
    //istanza di dado
   short int getUltimoLancio() const;  
   
   void effettuaLancio();
 
   void commentaLancio() const;  // anche questo e' const

   friend ostream &operator<< (ostream &stream, Dado d); //overloading operatore '<<'


private: //***************************
        
   short int valoreUltimoLancio; //membro privato, accessibile solo dal codice dei metodi della classe

};   // end class Dado

#endif
