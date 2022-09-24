#include <iostream>
#include <cstdlib>

using namespace std;

class Lira
  {
    private :

       int valore;

    public :

       Lira (int v)   { valore = v; }

       friend float Convertitore (float, Lira &);
	   // In genere una funzione friend possiede un
	   // parametro costituito da un oggetto della
	   // classe che la contiene

  }; //End class Lira


float Convertitore (float coeff, Lira & l)
  { 
    return l.valore / coeff;     // La variabile "valore" e' privata !!!
  }


int main ()
  {
    Lira diecimila(10000);

    cout << "10.000 lire equivalgono a "
	 << Convertitore (1936.27, diecimila) << " euro\n";

   return EXIT_SUCCESS;
} 


//*****************************************************************
//*****************************************************************
