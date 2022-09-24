
//Classi virtuali 
#include <iostream>


using namespace std;

class Base
  {
    protected:

       int x;

  }; //End class Base



class Derivata1 : virtual public Base
  {
    protected:

       int y1;

  }; //End class Derivata1



class Derivata2 : virtual  public Base
  {
    protected:

       int y2;

  }; //End class Derivata2



class Derivata : public Derivata1, public Derivata2
  {
    protected:

       int z;

    public:

       void Set (int i1, int j1, int i2, int j2, int k)
	  {
	    x = i1;            // Non e' piu' ambiguo. Derivata eredita x 
			      //una sola volta
 	    Derivata1::x = i1; // stessa locazione di memoria di x
	    y1 = j1;
	    Derivata2::x = i2; // stessa locazione di memoria di x. Ultima modifica di x!
	    y2 = j2;
	    z = k;

	    cout << &(Derivata1::x) << ", " << &(Derivata2::x) << ", " << Derivata1::x << ", " << Derivata2::x << endl;
	  }

       void Visualizza () const
	  {
	    cout << "x=" << x << ", Derivata1::x= "  << Derivata1::x << ", y1=  " << y1 << "  "
		 << ", Derivata2::x=" << Derivata2::x << ", y2=" << y2 << ",z=  " << z << '\n';
	  }

  }; //End class Derivata



int main ()
  {
    Derivata d;

    d.Set (1,2,3,4,5);
    d.Visualizza ();
    
    return 0;
  }


//*****************************************************************
//*****************************************************************
