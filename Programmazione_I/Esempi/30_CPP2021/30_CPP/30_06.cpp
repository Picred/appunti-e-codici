
#include <iostream>

using namespace std;



class Figura
  {
    protected:

       double  x, y;

    public:

	//valore standard per b permette set(a) per cerchio! 
       void Set (float a, float b = 0.0)   { x = a;  y = b; }

       virtual void Area ()
	  { cout << "Non definita per questa classe\n"; }

  }; //End class Figura


class Triangolo : public Figura
  {
    public:

       void Area ()
	  {
	    cout << "Triangolo  : base = " << x << " altezza = " << y << '\n';
	    cout << "             Area = " << (x*y)/2 << "\n\n";
	  }

  }; //End class Triangolo


class Rettangolo : public Figura
  {
    public:

       void Area ()
	  {
	    cout << "Rettangolo : base = " << x << " altezza = " << y << '\n';
	    cout << "             Area = " << x*y << "\n\n";
	  }

  }; //End class Rettangolo


class Cerchio : public Figura
  {
    public:

       void Area ()
	  {
	    cout << "Cerchio    : raggio = " << x << '\n';
	    cout << "             Area = " << 3.14 *x*x << "\n\n";
	  }

  }; //End class Cerchio

int main ()
  {
    Figura     *ptr;
    Triangolo  t;
    Rettangolo r;
    Cerchio    c;

    ptr = & t;
    ptr -> Set (3.7, 9.2);
    ptr -> Area ();

    ptr = & r;
    ptr -> Set (3.7, 9.2);
    ptr -> Area ();

    ptr = & c;
    ptr -> Set (1.0);
    ptr -> Area ();
    
    return 0;
  }


//*****************************************************************
//*****************************************************************
