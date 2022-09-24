//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_03.cpp
//***   Data creazione : 12/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Derivazioni (III)
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>
#include <cstring>
#include <cstdlib>

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

  }; //End class Vettore3D



class Vettore4D : private Vettore3D     // Derivazione "private"
  {
    protected :

       float    w;

    public:

      //x,y,z  diventano private
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



//accesso invariato per membri protected e public
//i membri private di Vettore4D vengono ereditati 
//ma non sono accessibili dalla classe
class Derivata :  public Vettore4D
  {
    public:

       void Prova (float o)
	   {
	     // x = 5.0;   // Errore di compilazione ... x e' PRIVATE per Vettore4D, inaccessibile a Derivata
	     // cout << Vettore4D::Prima();   // Errore di compilazione ...
	    //prima() era public per Vettore3D, ma e' private per Vettore4D..
	     w = o;
	   }

  }; //End class Derivata



int main ()
  {
    Vettore4D a;

    a.Set (1,2,3,4);
    // a.Set_Nome ("V1");   // Errore di compilazione ...
    a.Visualizza ();

    // cout << a.Prima() << a.Seconda() << a.Terza();
    // Triplo errore di compilazione ...

    cout << a.Quarta()  << "\n\n";

    // a.Vettore3D::Set (-1,-2,-3);   // Errore di compilazione ...

    // a.w = a.x   //  Doppio errore di compilazione ...

    Derivata b;
    b.Prova (3.14);
    cout << b.Quarta() << "\n\n"; //

//   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
  }

//*****************************************************************
//*****************************************************************
