
// CONVERSIONI ESPLICITE vs CONVERSIONI IMPLICITE 

#include <iostream>
#include <cstdlib>

using namespace std;


class Complex
  {
    private :

       float Re;
       float Im;

    public:

	//gli argomenti standard permettono le conversioni..vedi main
       Complex (float a = 0.0, float b = 0.0) :  
           Re(a), Im(b)
	       { cout << "Costruttore\n"; }


       Complex (const Complex & c) :  
           Re(c.Re), Im(c.Im)
	       { cout << "Costruttore di copia\n"; }


       Complex operator + (const Complex & dx)
	  {
	    return Complex(Re+dx.Re,  Im+dx.Im);
	  }


       void Visualizza (void) const
	  { cout << Re << "+" << Im << "i\n"; }

  }; //End class Complex




int main ()
  {
    Complex a(2.4, 3.7);
    Complex b = a; // ;costruttore di copia
    //b = c; // overloading operatore = oppure 

    a.Visualizza ();
    b.Visualizza ();

    b = Complex(2.0);          // Conversione ESPLICITA double -> Complex  (costruttore!)
    b = (Complex) 2.0;         // Conversione ESPLICITA, equivalente a: Complex(2.0) (costruttore!)
    b = 2.0;                   // Conversione IMPLICITA, equivalente a: Complex(2.0) (costruttore!)

    cout << "-------------\n";
    b = a + (Complex) 3.2;     // Conversione ESPLICITA, equivalente a: a+Complex(3.2)
    b = a + 3.2;               // Conversione IMPLICITA, equivalente a: a+Complex(3.2)
    b = a + 5;                 // Doppia conversione IMPLICITA, equivalente a: a.operator+(Complex(5.0))
			      // ((int) 5 --> (double) 5.0) e poi Complex(5.0)

//    b = 3.2 + a;//    Errore di compilazione ... equivalente a: ??? 
    //non esiste una funzione operator+ con due argomenti (non membro)!
    cout << "\n\n";
  
    return EXIT_SUCCESS;    
  }


//*****************************************************************
//*****************************************************************
