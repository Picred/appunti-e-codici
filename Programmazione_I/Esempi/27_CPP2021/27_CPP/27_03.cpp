#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Complex
  {
    private:

       float Re;
       float Im;

    public:

      Complex (float a, float b)
	    {
	       cout << "Costruttore (" << a << ", " << b << ")\n";
	       Re = a;
	       Im = b;
	    }
	

  }; //End class Complex

int main ()
  {
    // alloca memoria per x e y e inizializza, OK
    Complex x(3.3, 5.0), y(2.7, 3.14);
    //oppure..
    Complex x1={3.3, 5.0}; 
    // Oppure...
    Complex z = Complex(2.0,2.0);

    //Complex z1={3.3}; //NO!
    //Complex z2(); //NO! Non c'e' piu il costruttore di default

    return EXIT_SUCCESS;
}
