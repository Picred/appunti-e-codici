#include <iostream>
#include <cstdlib>

using namespace std;

//OPERATORI FRIEND
class Vettore3D
  {
    private :

       float    x, y, z;

    public:

       Vettore3D (float l=0.0, float m=0.0, float n=0.0) :
	      x(l), y(m), z(n)  
          { cout << " COS ";}

       // float Prima   () const {return x;}
       // float Seconda () const {return y;}
       // float Terza   () const {return z;}

       void Visualizza (void) const
	   { cout << "( " << x << ", " << y << ", " << z << " )"; }

       friend Vettore3D operator + (const Vettore3D sx, const Vettore3D dx);
       friend Vettore3D operator - (const Vettore3D operando);
       friend Vettore3D operator * (const int coeff, const Vettore3D dx);
       friend Vettore3D operator * (const Vettore3D sx, const int coeff);

  }; //End class Vettore3D


// Operatore binario
Vettore3D operator + (const Vettore3D sx, const Vettore3D dx)
  {
    `return  Vettore3D (sx.x + dx.x,
		       sx.y + dx.y,
		       sx.z + dx.z
		      );
  }


// Operatore unario
Vettore3D operator - (const Vettore3D operando)
  {
    return  Vettore3D (-operando.x,
		       -operando.y,
		       -operando.z
		      );
  }


// Operatore binario con argomenti di tipo diverso
// Non necessario poiché interviene int->Vettore3D
Vettore3D operator * (const int coeff, const Vettore3D dx)
  {
    return  Vettore3D (coeff * dx.x,
		       coeff * dx.y,
		       coeff * dx.z
		      );
  }


// Operatore binario "*" overloaded
// Non necessario poiché interviene int->Vettore3D
Vettore3D operator * (const Vettore3D sx, const int coeff)
  {
    return  Vettore3D (coeff * sx.x,
		       coeff * sx.y,
		       coeff * sx.z
		      );
  }

//Le funzioni friend avranno 
//accesso ai membri privati degli oggetti.  

int main ()
  {
    Vettore3D a (1,2,3);
    Vettore3D b = -a;
    Vettore3D c;

    cout << "\n\n";

    
    (a+b).Visualizza();     cout << "  =  ";
    c = operator + (a,b);
    c.Visualizza();         cout << "\n\n";

    b = 3 * a;
    b.Visualizza();         cout << "  =  ";
    (a * 3).Visualizza();   cout << "\n\n";

    // DOMANDA : E' lecito scrivere quanto segue ?

    b = (30.7 + a);    b.Visualizza();
    cout << "\n\n";

//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************

