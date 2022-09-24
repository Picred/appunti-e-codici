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

       Complex ()
	  {
	    cout << "Costruttore di default\n";
	    Re = 0.0;
	    Im = 0.0;
	  }

       Complex (float a)
	  {
	    cout << "Costruttore con un parametro\n";
	    Re = a;
	    Im = 0.0;
	  }

       Complex (float a, float b)
	  {
	    cout << "Costruttore con due parametri\n";
	    Re = a;
	    Im = b;
	  }

  }; //End class Complex


int main ()
  {
    Complex x; // costruttore base
    Complex y(3.3); //secondo costruttore 
    Complex W(2.7, 3.14); // terzo construttore

    return 0;
} 

