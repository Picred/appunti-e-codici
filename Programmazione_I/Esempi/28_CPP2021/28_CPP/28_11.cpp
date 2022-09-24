#include <iostream>
#include <cstdlib>

// CONVERSIONI IMPLICITE

using namespace std;

class Real{
  float real;
  public:
    Real(float x):real(x){ cout << "COS" << endl; }

    void visualizza(){
      cout << "Real: " << real << endl;  	
    }
};

//OPERATORE DI CONVERSIONE Complex -> Real
//OPERATORE DI CONVERSIONE Complex -> Double
class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (float a = 0.0, float b = 0.0):
            Re(a), Im(b)
	        { cout << "Costruttore\n"; }


       Complex (const Complex & c) :  
            Re(c.Re), Im(c.Im)
	        { cout << "Costruttore di copia\n"; }


      // OPERATORE DI CONVERSIONE (COMPLEX --> DOUBLE)
      //a. oggetto --> tipo primitivo 
       operator double () const    
         { 
           cout << "overload cast\n";
           return  Re; 
         }

      // OPERATORE DI CONVERSIONE (COMPLEX --> REAL)
      //b. oggetto X --> oggetto Y 
       operator Real () const    
         { 
           cout << "overload cast to Real\n";
           return  Real(Re); 
         }


       void Visualizza (void) const
	  { cout << Re << "+" << Im << "i\n"; }

  }; //End class Complex




int main ()
  {
    int i = 2;
    double x = 3.3;
    Complex c(2.4, 3.7);

    x = x + c;  //operatore di conversione..
    cout << "x = " << x << '\n';

    x = c * i; // doppia conversione, c <-- double, i<--double
    cout << "x = " << x << '\n';
    
    Real re = c; 
    re.visualizza(); 

    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
