#include <iostream>
#include <cstdlib>

using namespace std;

//OPERATORI FRIEND VS NON-FRIEND

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

      //a.operator+(b) 
       Vettore3D operator + (const Vettore3D); //binario un argomento + this
      //a.operator-()
       Vettore3D operator - (); // unario, no argomenti +  this
      //a.operator*(int)
       Vettore3D operator * (const int); // binario un argomento + this
	//operator*(int, Vettore3D)
       friend Vettore3D operator * (const int, const Vettore3D); //OK, friend, va passato il parametro oggetto

  }; //End class Vettore3D


// Operatore binario
Vettore3D Vettore3D::operator + (const Vettore3D dx)
  {
    return  Vettore3D (this->x + dx.x,
		       this->y + dx.y,
		       this->z + dx.z
		      );
  }


// Operatore unario
Vettore3D Vettore3D::operator - ()
  {
    return  Vettore3D (-x, -y, -z);
  }


// Operatore binario con argomenti di tipo diverso
// Non necessario!
Vettore3D Vettore3D::operator * (const int coeff)
  {
    return  Vettore3D (coeff * x,  coeff * y,  coeff * z);
  }


// Operatore binario "*" overloaded implementato come "friend"
//Necessario!
Vettore3D operator * (const int coeff, const Vettore3D dx)
  {
    return  Vettore3D (coeff * dx.x,
		       coeff * dx.y,
		       coeff * dx.z
		      );
  }



int main ()
  {
    Vettore3D a (1,2,3);
    Vettore3D b = -a;
    Vettore3D c;

    cout << "\n\n";

    (a+b).Visualizza();     cout << "  =  ";
    c = a.operator+ (b);
    c.Visualizza();         cout << "\n\n";

    b = 3 * a;
    b.Visualizza();         cout << "  =  ";
    (a * 3).Visualizza();   cout << "\n\n";

    // DOMANDA : E' lecito scrivere quanto segue ?

    b = (a + 30.7); // equivale a a.operator+(30.7), applicata la conversione 30.7 --> Vettore3D
    b.Visualizza();         cout << "\n\n";

    // OSSERVAZIONE : L'esecuzione sarebbe piu' efficiente se non
    //      fosse presente la conversione implicita dell'operando.
    //      In generale, quando si progetta una classe bisogna
    //      definire esplicitamente tutte quelle combinazioni di
    //      operandi che si verificano frequentemente.i

  //  b = 30.7 + a;//   Errore di compilazione ...  
    //                   bisogna impiegare un opportuno operatore
    //                   "friend" o non-membro.

//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }

