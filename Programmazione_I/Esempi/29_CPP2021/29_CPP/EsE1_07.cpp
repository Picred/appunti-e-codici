//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_07.cpp
//***   Data creazione : 12/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Costruttori e Distruttori (II)
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

       Vettore3D () : x(0), y(0), z(0)   {cout << "Costruttore Vettore3D!" << endl; }
       Vettore3D (float l, float m, float n) : x(l), y(m), z(n)   {cout << "Costruttore Vettore3D, con parametri!" << endl; }

       void Set_Nome (const char *str)  { strcpy (nome, str); }

       float Prima   () const     { return x; }
       float Seconda () const     { return y; }
       float Terza   () const     { return z; }

       void Visualizza () const   { cout << nome; }

  }; //End class Vettore3D



class Vettore4D : public Vettore3D
  {
    protected :

       float    w;

    public:

	//chiamata implicita a costruttore di deafult
       Vettore4D () : w(0)   {cout << "Costruttore Vettore4D! " << endl; }
      //chiamata esplicita a costruttore con parametri
       Vettore4D (float l, float m, float n, float o) :
		 Vettore3D(l,m,n), w(o)   {cout << "Costruttore Vettore4D, con parametri!" << endl; } // passaggio parametri al costruttore della classe base

       float Quarta () const     { return w; }

       void Visualizza () const
	   {
	     Vettore3D::Visualizza();
	     cout << " = ( " << x << ", "
		  << y << ", " << z << ", " << w << " )\n";
	   }

  }; //End class Vettore4D



int main ()
  {
    //costruttore base e derivata senza parametri e poi base e derivata con parametri
    Vettore4D a, b(1,2,3,4);

    a.Set_Nome ("a");
    b.Set_Nome ("b");

    a.Visualizza ();
    b.Visualizza ();
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
