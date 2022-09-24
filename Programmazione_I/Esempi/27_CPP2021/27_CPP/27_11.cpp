#include <cstring>
#include <iostream>

using namespace std;


class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (const Complex &); // costruttore di copia
       Complex (float, float);

       void Visualizza (void) const;

  }; //End class Complex


Complex::Complex (const Complex & c) :
	 Re(c.Re), Im(c.Im)
  {
    cout << "Costruttore di copia per Complex\n";
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


class Coppia
  {
    private :

       Complex primo;
       Complex secondo;

    public :

       Coppia (const Coppia &);
       Coppia (float, float);

       void Visualizza (void) const;

  };  //End class Coppia


// costruttori di copia in cascata
Coppia::Coppia (const Coppia & co) :
	primo(co.primo), secondo(co.secondo) 
  {
    cout << "Costruttore di copia per Coppia\n";
  }


Coppia::Coppia (float a, float b) :
	primo(a, b),  secondo(a+1, b+1)

  {
    cout << "Costruttore Coppia\n";
  }


void Coppia::Visualizza (void) const
  {
    primo.Visualizza ();
    secondo.Visualizza ();
    cout << '\n';
  }


int main ()
  {
    Coppia a(2.4, 3.7);
    Coppia b = a; // costruttore di copia

    a.Visualizza ();
    b.Visualizza ();
    
   return 0;
  }
