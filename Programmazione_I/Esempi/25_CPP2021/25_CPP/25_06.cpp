#include <iostream>

using namespace std;

class Euro;

class Lira
  {
    private :
       int valore;

    public :
       Lira (int v)   { valore = v; }
       friend void Convertitore (float, Lira &, Euro &, Dollaro &);
  }; //End class Lira

class Euro
  {
    private :

       int valore;

    public :

       Euro (int v)   { valore = v; }

       friend void Convertitore (float, Lira &, Euro &, Dollaro &);

  }; //End class Euro

class Dollaro
  {
    private :

       int valore;

    public :

       Dollaro (int v)   { valore = v; }

       friend void Convertitore (float, Lira &, Euro &, Dollaro &);

  }; //End class Euro

void Convertitore (float coeff, Lira & l, Euro & e, Dollaro & d)
  {
    cout << l.valore / coeff << " euro  e  "
	 << e.valore * coeff << " lire\n";
  }


int main ()
  {
    Lira diecimila(10000);
    Euro dieci(10);

    cout << "10.000 lire  e  10 euro equivalgono rispettivamente a\n";
    Convertitore (1936.27, diecimila, dieci);

//   system("PAUSE");    // ns. comodo!
   return 0;
} // End main()


//*****************************************************************
//*****************************************************************
