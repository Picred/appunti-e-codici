#include <iostream>
#include "moneta.h"
#include <cstdlib>


Moneta::Moneta()
{
    effettuaLancio(); 
}

void Moneta::effettuaLancio ()
   {
     short faccia = (short) (rand()%2);

      if (faccia == 0) 
	ultimaFaccia = 'T';
      else ultimaFaccia = 'C';
   }

bool Moneta::testa() const
   {
//      ultimaFaccia = 'C'; // darebbe errore in fase di compilazione, il metodo e' const
      if (ultimaFaccia == 'T')
         return true;
      else 
         return false;
   }
   
bool Moneta::croce() const
   {
      return  !testa();
   }
   
char Moneta::getFaccia () const
   {
      return  ultimaFaccia;
   }
   
      
ostream &operator<< (ostream &stream, Moneta m)
   {
      if (m.ultimaFaccia == 'T')
           stream << "TESTA" << endl;
      else
           stream << "CROCE\n";
      return stream;     
   }
   

