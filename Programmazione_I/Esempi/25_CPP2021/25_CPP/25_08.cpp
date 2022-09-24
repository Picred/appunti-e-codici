
#include <iostream>

using namespace std;


class Euro;

class Lira
  {
    private :

       int valore;

    public :

       Lira (int v)   { valore = v; }

       friend class Euro; //La classe euro e' dichiarata friend della classe Lira

  }; //End class Lira


class Euro
  {
    private :

       int valore;

    public :

       Euro (int v)   {valore = v;}

       void Convertitore (float, Lira &); // il metodo Convertitore non e' friend per Lira..

  }; //End class Euro


void Euro::Convertitore (float coeff, Lira & l)
  {
    cout << valore * coeff << " lire  e  " // .. ma Convertitore e' metodo di Euro, friend di Lira...
	 << l.valore / coeff << " euro\n";
  }


int main ()
  {
    Lira diecimila(10000);
    Euro dieci(10);

    cout << "10 euro  e  10.000 lire  equivalgono rispettivamente a\n";
    dieci.Convertitore (1936.27, diecimila);

//   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
} // End main()


//*****************************************************************
//*****************************************************************

