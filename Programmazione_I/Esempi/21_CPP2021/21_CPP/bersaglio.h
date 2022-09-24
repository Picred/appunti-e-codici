#ifndef BERSAGLIO_H
#define BERSAGLIO_H

#include <string>
using namespace std;

class Freccia;



//***************
class Bersaglio {
//***************

public:  

   Bersaglio(int _dimensione);
   int getDim () const;
   short int punteggio (Freccia F) const;
   

private: 
        
   int   dimensione;
   float raggio;

   float distanza (Freccia F) const;

};   // End class Bersaglio



//*************
class Freccia {
//*************

public:  
              
   Freccia();
   void lancia(Bersaglio B);
   float getX () const;
   float getY () const; 


private:
  
   float x, y;

}; // End class Freccia


#endif
