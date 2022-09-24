#include <iostream>

using namespace std;

class Euro;

class Lira
  {
    private :

       int valore;

    public :

       Lira (int v)   { valore = v; }

       void Convertitore (float, Euro &);

  }; //End class Lira


class Euro
  {
    private :

       int valore;

    public :

       Euro (int v)   { valore = v; }

       friend void Lira::Convertitore (float, Euro &);

  }; //End class Euro


void Lira::Convertitore (float coeff, Euro & e)
  {
    cout << valore / coeff << " euro  e  "
	 << e.valore * coeff << " lire\n"; // attributo valore privato! 
  }


int main ()
  {
    Lira diecimila(10000);
    Euro dieci(10);

    cout << "10.000 lire  e  10 euro equivalgono rispettivamente a\n";
    diecimila.Convertitore (1936.27, dieci);

//   system("PAUSE");    // ns. comodo!
   return 0;
} // End main()


//*****************************************************************
//*****************************************************************
