#include <iostream>
#include <cstdlib>
#include "dado.h"
#include <ctime>

Dado::Dado()
{
    cout << "Dado()" << endl; 
    srand(time(0)); // usa un seme di default
    effettuaLancio();
}

Dado::Dado(time_t seed) // il costruttore ha lo stesso nome della classe
{
    srand(seed);
    effettuaLancio(); 
}

void Dado::effettuaLancio ()
   {
      valoreUltimoLancio = //accesso ad una variabile che rappresenta parte dello stato dell'oggetto
          (short) (1 + rand()%6);
   }

short int Dado::getUltimoLancio () const
   {
      //commentaLancio(); metodo const, invocazione ok
      //valoreUltimoLancio = (1 + rand()%6); // non permesso
      //effettuaLancio(); // metodo non const, invocazione non permessa
      return  valoreUltimoLancio;
   }

void Dado::commentaLancio () const
   {
      string Str="";
      short valoreCasuale = (short) (rand()%5);

      switch (valoreCasuale)
        {
          case 0 :
             Str = "E' stato un ottimo lancio!";
             break;
          case 1 :
             Str = "Il dado non si e' neache mosso...";
             break;
          case 2 :
             Str = (string)"Che ti e' successo? " + (string) "Ti vedo deperito...";
             break;
          case 3 :
             Str = "Potevi fare meglio!";
             break;
          case 4 :
             Str = (string) "Non avevo mai visto " +
                   "un dado acrobatico!";
             break;
        }
      cout << Str << endl << endl;  
   }

ostream &operator<< (ostream &stream, Dado d)
   {
      stream << "Il dado attualmente presenta la faccia "
             << d.getUltimoLancio() << ".\n";
      return stream;  
   }   
