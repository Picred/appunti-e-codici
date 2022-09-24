#include <iostream>
#include <math.h>
#include <cstdlib>

#include "bersaglio.h"


Bersaglio::Bersaglio (int _dimensione)
  {
    dimensione = _dimensione; 
    raggio = dimensione / 4.0f; //raggio del cerchio piccolo
  }
  

int Bersaglio::getDim () const
  {
    return dimensione;
  }
  
  
short int Bersaglio::punteggio (Freccia F) const
  {
     if (distanza(F) > raggio)
        return 0;
     else 
        return 1;
  }
  
  
float Bersaglio::distanza (Freccia F) const
  {
    float xCentro = dimensione / 2.0f;
    float yCentro = dimensione / 2.0f;
  
    float d = (float) sqrt(
                 pow((F.getX()-xCentro),2)+
                 pow((F.getY()-yCentro),2));
        
    return d; 
  }


//******************************************************


Freccia::Freccia()
  {
    x=1E10f;
    y=1E10f;
  }
  
       
void Freccia::lancia(Bersaglio B)
  {
    x = (float)rand() / RAND_MAX * B.getDim();
    y = (float)rand() / RAND_MAX * B.getDim();

    // Riscrivere utilizzando <random> !
  }

  
float Freccia::getX () const
  {
    return x;
  }

  
float Freccia::getY () const
  {
    return y;
  }
