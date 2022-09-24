
#include <iostream>
#include <cstdlib>

using namespace std;


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

       friend ostream &  operator << (ostream & sx, const Complex & dx);
       friend istream &  operator >> (istream & sx, Complex & dx);

  }; //End class Complex


ostream &  operator << (ostream & sx, const Complex & dx)
  {
    return sx << dx.Re << "+" << dx.Im << "i";
    // stampa sullo standard output il numero complesso 
    //nella forma a+bi usando overloading dell'operatore ">>" 
    //gia' definito in ostream per tipi primitivi 
  }


istream &  operator >> (istream & sx, Complex & dx)
  {
    char c;
    sx >> dx.Re >> c >> dx.Im >> c; 
    // conserva il primo ed il terzo input nella parte reale ed immaginaria in opportune variabili, 
    //usando overloading dell'operator ">>" definito in istream per tipi primitivi 
    return sx;
  }


int main ()
  {
    Complex a(2.4, 3.7), b(3,4); 

    cout << "a=" << a << ", b=" << b << endl; 
    //equivalente a..
    //((((cout << "a=") << a) << ", b=") << b) << endl; 

    cout << "Inserisci un numero complesso nella forma algebrica a+bi:\n";
    cin >> a;
    cout << '\n' << a << '\n';
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }



//*****************************************************************
//*****************************************************************
