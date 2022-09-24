
#include <iostream>
#include <cstdlib>

using namespace std;

class Real{
  float real;
  public:
    Real(float x):real(x){ cout << "COS Real()" << endl; }

    float visualizza(){
      cout << "real: " << real << endl; 
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


      // operatore di conversione (Complex --> double)
       operator double () const    
         { 
           cout << "overload cast (Complex --> double)\n";
           return  Re; 
         }

      // operatore di conversione (Complex --> Real)
	operator Real () const 
	  {	    
	    cout << "overload cast (Complex --> Real)\n";
	    return Real(Re); 
	  }
       void Visualizza (void) const
	  { cout << Re << "+" << Im << "i\n"; }

  }; //End class Complex




int main ()
  {
    int i = 2;
    double x = 3.3;
    Complex c(2.4, 3.7);

    x = x + c;  //operatore di conversione (conversione implicita)
    cout << "x = " << x << '\n';

    x = c * i; // doppia conversione, c <-- double, i<--double (conversione implicita)
    cout << "x = " << x << '\n';
  
  
    Real re = c; //operatore di conversione da Complex a Real (conversione implicita)
    re.visualizza(); 

    Real r = c + 1.0; //operatore di conversione Complex --> double, poi costruttore Real(float) 
    r.visualizza();
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }

