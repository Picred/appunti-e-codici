
//CLASSI BASE VIRTUALI 

// Duplicazione di locazioni di memoria, ambiguita'

#include <iostream>

using namespace std;

class Base
  {
    protected:

       int x;

  }; //End class Base



class Derivata1 : public Base
  {
    protected:

       int y1;

  }; //End class Derivata1



class Derivata2 : public Base
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
	  //  x = i1;    // ERRORE DI COMPILAZIONE ... ambiguita'
	    Derivata1::x = i1;
	    y1 = j1;
	    Derivata2::x = i2;
	    y2 = j2;
	    z = k;
	    cout << &(Derivata1::x) << ", " << &(Derivata2::x) << ", " << Derivata1::x << ", " << Derivata2::x << endl;
	  }

       void Visualizza () const
	  {
	    cout << Derivata1::x << "  " << y1 << "  " << Derivata2::x << "  " << y2 << "  " << z << '\n';
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
