
#include <iostream>

using namespace std;


//entita' generica
class Figura
  {
    protected:

       double  x, y;

    public:

       void Set (float a, float b)   { x = a;  y = b; }

       virtual void Area ()
	  { cout << "Non definita per questa classe\n"; }

  }; //End class Figura


//entita' specifica: triangolo
class Triangolo : public Figura
  {
    public:

       void Area ()
	  {
	    cout << "Triangolo  : base = " << x << " altezza = " << y << '\n';
	    cout << "             Area = " << (x*y)/2 << "\n\n";
	  }

  }; //End class Triangolo

//ancora un'altra derivazione: rettangolo
class Rettangolo : public Figura
  {
    public:

       void Area ()
	  {
	    cout << "Rettangolo : base = " << x << " altezza = " << y << '\n';
	    cout << "             Area = " << x*y << "\n\n";
	  }

  }; //End class Rettangolo



int main ()
  {
    Figura     *ptr;
    Triangolo  t;
    Rettangolo r;

    ptr = &t; //triangolo
    ptr -> Set (3.7, 9.2); // base e altezza
    ptr -> Area ();

    ptr = & r;
    ptr -> Set (3.7, 9.2);
    ptr -> Area ();
    
    return 0;
  }


//*****************************************************************
//*****************************************************************
