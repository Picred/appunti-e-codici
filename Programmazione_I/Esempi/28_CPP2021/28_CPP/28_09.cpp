//NEW e DELETE
#include <iostream>
#include <cstdlib>

using namespace std;

class Vettore3D
  {
    private :

       float    x, y, z;

    public:

       Vettore3D (float l=0.0, float m=0.0, float n=0.0) :
	       x(l), y(m), z(n)  
           { cout << "COS\n";}

       ~Vettore3D ()   { cout << "DIS\n";}

       void * operator new    (size_t);
       void   operator delete (void *); 

       void Visualizza (void) const
	      { cout << "( " << x << ", " << y << ", " << z << " )\n"; }

  }; //End class Vettore3D


void * Vettore3D::operator new (size_t size)
  {
    cout << "Overloading di new\n";
    return  malloc (size);
  }


void Vettore3D::operator delete (void * ptr) 
  {
    cout << "Overloading di delete\n";
    free (ptr);
  }



int main ()
  {
    Vettore3D a (1,2,3);
    Vettore3D * p;

    cout << "\n";

    p = new Vettore3D (4,5,6);

    p -> Visualizza();
    delete p;

    cout << "Fine main\n";
    
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
