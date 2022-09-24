//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_01.cpp
//***   Data creazione : 05/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Derivazioni (I)
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;

const int Dimensione = 20;


class Vettore3D
  {
    private :

       char  nome[Dimensione+1];

    protected :

       float    x, y, z;

    public:

       void Set (float l, float m, float n)
	   { x = l;  y = m;  z = n; }

       void Set_Nome (char *str)  { strcpy (nome, str); }

       float Prima   () const     { return x; }
       float Seconda () const     { return y; }
       float Terza   () const     { return z; }

       void Visualizza () const   { cout << nome; }

  }; //EndG class Vettore3D


//derivazione con modificatore accesso PUBLIC!
class Vettore4D : public Vettore3D
  {

    protected :

       float    w;

    public:

	//ATTENZIONE: x,y,z sono protected in Vettore3D, quindi 
	//accesso possibile da questa classe derivata 
	//con QUALUNQUE modificatore di accesso 
	//anche se specifica accesso classe fosse private..
       void Set (float l, float m, float n, float o)
	   { x = l;  y = m;  z = n;  w = o; }

       float Quarta () const     { return w; }

       void Visualizza () const
	   {
	     // cout << nome;   // Errore di compilazione ...
	     Vettore3D::Visualizza();
	     cout << " = ( " << x << ", "
		  << y << ", " << z << ", " << w << " )\n";
	   }

  }; //End class Vettore4D



int main ()
  {
    Vettore4D a;

    a.Set (1,2,3,4);
    a.Set_Nome ("V1");
    a.Visualizza ();


    cout << "Singole componenti : "
	 << a.Prima() << ", " << a.Seconda() << ", "
	 << a.Terza() << ", " << a.Quarta()  << "\n\n";

    //risolutore di scope, invocazione del metodo Set della classe Vettore3D
    a.Vettore3D::Set (-1,-2,-3);
    a.Visualizza ();

      //w protected in Vettore4D, x private in Vettore4D..
    a.w = a.x;   //  Doppio errore di compilazione ...
    
//    system("PAUSE");    // ns. comodo!
    return 0;
  }


//*****************************************************************
//*****************************************************************
