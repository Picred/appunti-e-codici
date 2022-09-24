#include <iostream>

using namespace std;


template <class T>
class Matrix
  {
    private :

      int rows,  cols;
      T * element;

    public :

      Matrix (int r=0, int c=0);
      Matrix (int r, int c, T value);
      Matrix (const Matrix<T> & m);
      ~Matrix ()                     { delete [] element; }

      int Rows () const   { return rows; }
      int Columns () const   { return cols; }

      T & operator ( ) (int i, int j) const;
      Matrix<T> & operator = (const Matrix<T> & m);
      Matrix<T>   operator + () const;
      Matrix<T>   operator + (const Matrix<T> & m) const;
      Matrix<T>   operator - () const;
      Matrix<T>   operator - (const Matrix<T> & m) const;
      Matrix<T>   operator * (const Matrix<T> & m) const;
      Matrix<T>   operator += (const T & x);

      void Show () const;

  }; // End class Matrix


template <class T>
Matrix<T>::Matrix (int r, int c)
  {
    if (r<0 || c<0)
       {
	     cout << "Indici errati\n";
	     return;
       }

    rows = r;
    cols = c;
    element = new T [r*c];
  }


template <class T>
Matrix<T>::Matrix (int r, int c, T value)
  {
    if (r<0 || c<0)
       {
	     cout << "Indici errati\n";
	     return;
       }

    rows = r;
    cols = c;
    element = new T [r*c];

    for (int i=0; i<rows*cols; i++)
       element[i] = value;
  }


template <class T>
Matrix<T>::Matrix (const Matrix<T> & m)
  {
    rows = m.rows;
    cols = m.cols;
    element = new T [rows*cols];

    for (int i=0; i<rows*cols; i++)
       element[i] = m.element[i];
  }


template <class T>
T & Matrix<T>::operator () (int i, int j) const
  {
    if (i<1 || i>rows || j<1 || j>cols)
       {
	     cout << "Indici errati";
	     exit (1);
       }

    return element [ (i-1)*cols + j - 1 ];
  }


template <class T>
Matrix<T>  Matrix<T>::operator + (const Matrix<T> & m) const
  {
    if ( rows != m.rows || cols != m.cols )
       {
	     cout << "Operazione non consentita\n";
	     return 0;
       }

    Matrix<T> result(rows, cols);

    for (int i=0; i<rows*cols; i++)
       result.element[i] = element[i] + m.element[i];

    return result;
  }


template <class T>
Matrix<T>  Matrix<T>::operator * (const Matrix<T> & m) const
  {
    if ( cols != m.rows )
       {
	     cout << "Operazione non consentita\n";
	     return NULL;
       }

    Matrix<T> result (rows, m.cols);
    int c1=0, c2=0, c=0;

    for (int i=1; i<=rows; i++)
       {
	     for (int j=1; j<=m.cols; j++)
	       {
	         T sum = element[c1] * m.element[c2];
	         for (int k=2; k<=cols; k++)
		       {
		         c1++;
		         c2 += m.cols;
		         sum += element[c1] * m.element[c2];
		       }
	         result.element[c++] = sum;
	         c1 -= cols-1;
	         c2 = j;
	       }
	     c1 += cols;
	     c2 = 0;
       }
    return result;
  }


template <class T>
void Matrix<T>::Show () const
  {
    for (int i=0; i<rows; i++)
       {
  	     for (int j=0; j<cols; j++)
	          cout << element[(i*cols)+j] << '\t';
	     cout << '\n';
       }
  }



int main ()
  {
    Matrix<int> A(2,3,1);
    cout << "A = \n";    A.Show();
    Matrix<int> B = A+A+A;
    B(1,1)=0;  B(2,3)=9;
    cout << "\nB = \n";
    B.Show();

    cout << endl;

 //   system("PAUSE");    // ns. comodo!
    return 0; 
  }


//*****************************************************************
//*****************************************************************

