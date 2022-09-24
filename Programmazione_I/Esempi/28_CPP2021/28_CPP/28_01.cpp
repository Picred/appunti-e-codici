
#include <iostream>
#include <cstdlib>

using namespace std;

class Vettore3D
  {
    private :

       float    x, y, z;

    public:

       // Vettore3D ()   { x = y = z = 0.0; }
       Vettore3D (float l=0.0, float m=0.0, float n=0.0) : x(l), y(m), z(n)  
           { cout << " COS "; }

       float Prima   () const {return x;}
       float Seconda () const {return y;}
       float Terza   () const {return z;}

       void Visualizza (void) const
	   { cout << "( " << x << ", " << y << ", " << z << " )"; }

  }; //End class Vettore3D


// OPERATORE BINARIO -- NON MEMBRO, DUE ARGOMENTI
Vettore3D operator + (const Vettore3D sx, const Vettore3D dx)
  {
    return  Vettore3D (sx.Prima()+dx.Prima(), sx.Seconda()+dx.Seconda(), sx.Terza()+dx.Terza());
  }


// OPERATORE UNARIO -- NON MEMBRO, UN ARGOMENTO
Vettore3D operator - (const Vettore3D operando)
  {
    return  Vettore3D (-operando.Prima(),
		               -operando.Seconda(),
		               -operando.Terza()
		               );
  }

// OPERATORE BINARIO CON ARGOMENTI DI TIPO DIVERSO
// NON NECESSARIO POICHÉ INTERVIENE INT->VETTORE3D
Vettore3D operator * (const int coeff, const Vettore3D dx)
  {
    return  Vettore3D (coeff * dx.Prima() ,
		               coeff * dx.Seconda(),
		               coeff * dx.Terza()
		               );
  }

// OPERATORE BINARIO "*" OVERLOADED
// NON NECESSARIO POICHÉ INTERVIENE INT->VETTORE3D
Vettore3D operator * (const Vettore3D sx, const int coeff)
  {
    return  Vettore3D (coeff * sx.Prima() ,
		               coeff * sx.Seconda(),
		               coeff * sx.Terza()
		               );
  }

int main ()
  {
    Vettore3D a (1,2,3);

    // operatore unario
    Vettore3D b = -a;
    b.Visualizza();

    Vettore3D c;

    cout << "\n\n";

    //(a+b) oppure 
    //operator+(a,b)
    (a+b).Visualizza();     cout << "  =  "; // binario '+'
    c = operator+(a,b); // binario '+' invocazione,creazione oggetto e copia in c

    c.Visualizza();         cout << "\n\n";

    b = 3 * a; // operatore *, creazione oggetto e copia in b
    b.Visualizza();         cout << "  =  ";
    (a * 3).Visualizza();   cout << "\n\n";

    // DOMANDA : E' lecito scrivere quanto segue ?
    //SI, in questo caso il compilatore tentera' una "conversione" 
    //di 30.7 in Vettore3D mediante apposito costruttore. 
    //Il costruttore lo permette, avendo argomenti standard 

    b = (30.7 + a);    b.Visualizza();
    cout << "\n\n";

  //  system("PAUSE");    // ns. comodo!
    return 0;
  }


//*****************************************************************
//*****************************************************************
