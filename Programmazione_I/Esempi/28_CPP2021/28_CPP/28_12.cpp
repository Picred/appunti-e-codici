#include <iostream>
#include <cstdlib>

using namespace std;

class Real{
  float real;
  public:
    Real(float x):real(x){ cout << "COS" << endl; }

    void visualizza(){
      cout << "Real: " << real << endl;  	
    }
};


class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (float a = 0.0, float b = 0.0) :  
            Re(a), Im(b)
	        { cout << "Costruttore\n"; }


       Complex (const Complex & c) :  
            Re(c.Re), Im(c.Im)
	        { cout << "Costruttore di copia\n"; }


      // operatore di conversione (Complex --> Real)
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

    Complex c(2.4, 3.7);
    
    Real re = c; //IMPLICITA 
    re.visualizza(); 

    Real r1 = (Real) c; //ESPLICITA 
    
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
