
#include <cstring>
#include <iostream>

using namespace std;

class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex ()
	  {
	    cout << "Costruttore di default\t";
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

       void Visualizza ()
	  {
	    cout << Re << "+" << Im << "i\t";
	  }

  }; //End class Complex



int main ()
  {
    Complex *ptr;

    cout << "Oggetti dinamici :\n";

    ptr = new Complex;
    ptr = new Complex(3.3);
    ptr = new Complex(2.7, 3.14);

    cout << "\n\nArray A :\n";

    Complex A [4]; // Il costruttore di default è necessario
		   // Viene eseguito a partire dall'indice 0
		   // Non inizializzato se non c'è alcun costruttore

    cout << "\n\nArray B :\n";

    Complex B [6] = { 2.3,
		      Complex(1.1),
		      Complex(),
		      Complex(2.5,3.2)
		    };

    cout << "\n\nArray dinamico di oggetti :\n";

    Complex *p = new Complex [4];
	// Valgono le stesse osservazioni formulate per l'array "A"

    p -> Visualizza();
    (p+1) -> Visualizza();
    p[2].Visualizza();
    (*(p+3)).Visualizza();

    delete [] ptr;

    cout << "\n\nArray dinamico bidimensionale di oggetti :\n";

    Complex (*p2) [3] = new Complex [2][3];
	// 2 righe e 3 colonne
	// Attenzione alle parentesi (...) !!!

    p2[1][2].Visualizza();  
    cout << endl;

    delete [] p2;

    return 0;
} // end main()

