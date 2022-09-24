#include <iostream>
#include <cstdlib>

using namespace std;

const int rows = 2,   cols = 3;


class Matrix
  {
    private :

      float element [rows] [cols];

    public :
      Matrix (float value = 0.0);

    float  &  operator () (int i, int j);
//      float    operator () (int i, int j);// a(1,2) a.operator(1,2)
      Matrix & operator =  (const Matrix & m); //NON const
      Matrix   operator +  (const Matrix & m) const; //BINARIO
      Matrix   operator -  () const; // UNARIO
      Matrix   operator -  (const Matrix & m) const;
      Matrix   operator *  (const Matrix & m) const;
      Matrix   operator += (const float & x);
      bool     operator == (const Matrix &m);

      void Show () const;

  }; // End class Matrix


//Costruttore
Matrix::Matrix (float value)
  {
    for (int i=0; i<rows; i++)
	    for (int j=0; j<cols; j++)
	      element [i] [j] = value;
  }


//Indicizza elemento i,j
float & Matrix::operator () (int i, int j)
//float  Matrix::operator () (int i, int j)
  {
    cout << "Indicizzazione overloaded\n";

    return  element [i] [j];
  }


bool Matrix::operator == (const Matrix &m){
  for(int i=0; i<rows; i++)
    for(int j=0; j<rows; j++)
      if(this->element[i][j] != m.element[i][j])
	return false;
  return true; 
}


//somma di due matrici, 
Matrix  Matrix::operator + (const Matrix & m) const
  {
    Matrix result;

    cout << "Operator +!" << endl;

    for (int i=0; i<rows; i++)
	    for (int j=0; j<cols; j++)
	      result.element[i][j] = element[i][j] + m.element[i][j];

    return result;
  }


void Matrix::Show () const
  {
    for (int i=0; i<rows; i++)
       {
	  for (int j=0; j<cols; j++)
	       cout << element[i][j] << '\t';
	       cout << '\n';
       }
  }



int main ()
  {
    Matrix A(1); // matrice fatta di soli 1, 2x3
    cout << "A = \n";    A.Show();

    Matrix C(2); 
    C.Show(); 

    cout << "(A==C)" <<  (A==C) << endl; 

    Matrix B = A+A+A; // due invocazioni ! 
    cout << "B = \n";    B.Show();

    cout << "B(0,0) = " << B(0,0) << "    B(1,2) = " << B(1,2) << endl;

    // Cosa bisogna modificare per poter scrivere (?):
    //
                    B(1,2)=9;      // Errore di compilazione ...

    cout << B(1,2) <<  endl;
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************

