#include <iostream>
#include <cstring>


using namespace std;

class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (const Complex &);
       Complex (float, float);

       void Visualizza (void) const;

  }; //End class Complex


Complex::Complex (const Complex & c) :
	 Re(c.Re), Im(c.Im)
  {
    cout << "Costruttore di copia\n";
  }


Complex::Complex (float a, float b) :
	 Re(a), Im(b)
  {
    cout << "Costruttore Complex\n";
  }


void Complex::Visualizza (void) const
  {
    cout << Re << "+" << Im << "i\n";
  }


int main ()
  {
    Complex a(2.4, 3.7);
    Complex b = a; // usa il costruttore di copia!

    a.Visualizza ();
    b.Visualizza ();

    const Complex c = a;
	// c non puo' utilizzare metodi non-"const"
	
   return 0;
  }


//*****************************************************************
//*****************************************************************
