#include <iostream>
#include <cstdlib>

using namespace std;

//OPERATORI INCREMENTO / DECREMENTO
class Vettore3D
  {
    private :

       float    x, y, z;

    public:

       Vettore3D (float l=0.0, float m=0.0, float n=0.0) :
	      x(l), y(m), z(n)  
          { cout << " COS ";}

       void Visualizza (void) const
	   { cout << "( " << x << ", " << y << ", " << z << " )"; }

      //COMPILATORE OPERA DISTINZIONE TRA OPERATORE PREFISSO E POSTFISSO 
      //CON APPOSITA SINTASSI
        
	   Vettore3D &operator ++ ();  // prefisso: ++a
       Vettore3D operator ++(int); // postfisso: a++; argomento "dummy" necessario per distinguere postfisso da prefisso), per overloading
  
       friend Vettore3D & operator -- (Vettore3D &);        // prefisso: --a
       friend Vettore3D operator -- (Vettore3D &, int);   // postfisso: a--; int e' "dummy"

  }; //End class Vettore3D


// Operatore unario PREFISSO implementato come membro
Vettore3D &Vettore3D::operator ++ ()
  {
    x++; 
    y++;
    z++;
    return *this; //OK, i tre numeri risulteranno incrementati, rest. una copia
  }


// Operatore unario POSTFISSO implementato come membro
Vettore3D Vettore3D::operator ++ (int) // int - parametro ``dummy'' si usa per distinguere le due versioni 
  {
    Vettore3D aux = *this; //aux e' una copia 
    x++; // incremento
    y++;
    z++;
    return aux; // x,y e z in aux sono invariati
  }

//PREFISSO puo' restituire reference all'oggetto stesso
// Operatore unario PREFISSO implementato come "friend"
Vettore3D &operator -- (Vettore3D & operando)
  {
    operando.x--;
    operando.y--;
    operando.z--;
    return  operando;
  }


//POSTFISSO non puo' restituire reference all'oggetto, ma restituire una copia
// Operatore unario POSTFISSO implementato come "friend"
Vettore3D operator -- (Vettore3D & operando, int) //int parametro dummy, si usa per distinguere le due versioni
  {
    Vettore3D aux = operando;
    operando.x--;
    operando.y--;
    operando.z--;
    return aux;
  }


int main ()
  {
    Vettore3D a (1,1,1);
    Vettore3D b, c;

    cout << "\n\n";

    a.Visualizza();    b.Visualizza(); // a:(1,1,1), b:(0,0,0)
    cout << "\n\n";
    b = --a; // prefisso
    a.Visualizza();    b.Visualizza(); // a:(0,0,0) b:(0,0,0)
    cout << "\n\n";
    b = a--; //postfisso
    a.Visualizza();    b.Visualizza(); // a:(-1,-1,-1) b:(0,0,0)
    cout << "\n\n\n";

    cout << "b=(++a)++ ...\n";
    b = (++a)++; 
    a.Visualizza();    b.Visualizza();
    cout << "\n\n";

    cout << "b=(--a)-- ...\n";
    b = (--a)--; 
    a.Visualizza();    b.Visualizza();
    cout << "\n\n";

    //cout << "b=(a--)-- Questo ?? \n";
    //b=(a--)--;
    //ERR compilazione, (a--) non e' una reference, ma  
    //a.Visualizza();    b.Visualizza();
    //cout << "\n\n";
    
//    system("PAUSE");    // ns. comodo!
    return 0;
  }




//*****************************************************************
//*****************************************************************
