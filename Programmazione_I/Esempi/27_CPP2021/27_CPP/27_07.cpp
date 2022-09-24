
#include <cstring>
#include <iostream>

using namespace std;


class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (float, float);

    void Visualizza ()
	  {
	    cout << Re << "+" << Im << "i\n";
	  }

  }; //End class Complex


//Lista di inizializzazione 
Complex::Complex (float a, float b) :	 Re{a}, Im{b}
  {
    cout << "Costruttore con inizializzazione di attributi\n";
  }


int main ()
  {
    Complex c(2.4,3.7);

    c.Visualizza ();
    return 0;
} // end main()

