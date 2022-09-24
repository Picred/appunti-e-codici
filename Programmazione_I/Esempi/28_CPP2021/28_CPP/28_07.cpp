//Operatore '[]'
#include <iostream>
#include <cstdlib>

using namespace std;

const int Dimensione = 10;

class Array
  {
    private :

       float  A[Dimensione];

    public:

      Array();

      //OPERATORE INDICIZZAZIONE - DEVE ESSERE MEMBRO! 
       float  &operator [] (const int);
	void stampa(); 

  }; //End class Array

Array::Array(){
  
      for(int i=0; i<Dimensione; i++) 
	A[i] = 0;
}

  void Array::stampa(){
      cout << "---" << endl;
      for(int i=0; i<Dimensione; i++)
	cout << A[i] << endl;
      cout << "---" << endl;
  }

//OPERATORE INDICIZZAZIONE! 
float  & Array::operator [] (const int indice)
  {
    if (indice < 0 || indice > Dimensione-1)
      {
	    cout << "Modulo\n";
      }
    return A[indice % Dimensione];
  }



int main ()
  {
    Array a;
    int i=3;

    a.stampa();

    a[i++]  = 3.14;  // a[3] = 3.14. L'operatore [] restituisce una reference, quindi assegnamento e' valido
    //se il prototipo fosse stato float operator[] (const int i), allora nessun assegnamento sarebbe permesso 
    //in quanto il tipo restituito non e' un L-value, ma un R-value 
    // float b = a[i++];

    a[--i+1] = a[3]; // a[4]=a[3]

    a.stampa();
    cout << a[3] << "   " << a[13] << "\n\n"; // operatore modulo

    a[23] = 0.0;
    cout << a[3] << "   " << a[13] << '\n';
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
    
  }


//*****************************************************************
//*****************************************************************
