#ifndef MONETA_H
#define MONETA_H

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


//************
class Moneta {
//************

public:  

   Moneta(); 
   
   void effettuaLancio();

   bool testa() const; //indica al compilatore che il metodo testa() non modifichera' lo stato dell'oggetto
 
   bool croce() const;

   char getFaccia() const;

   friend ostream &operator<< (ostream &stream, Moneta m);
   

private: 
        
   char ultimaFaccia;

};   // end class Moneta

#endif
