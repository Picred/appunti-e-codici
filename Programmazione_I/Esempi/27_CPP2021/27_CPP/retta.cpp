#include <iostream>

using namespace std;

/* 
  Questa classe contiene costruttori overloaded
*/

//***********
class Retta {
//***********

// tra le molte possibili descrizioni di una retta
// la descrizione "interna" e privata che la nostra 
// implementazione adotta è quella della equazione cartesiana
// A x + B y + C =0
// variabili di istanza sono dunque A,B, C

private:
     
   double A, B, C;
 

public:
  
  
  Retta(double coeffX, double coeffY, double tNoto); 
  Retta(double X1, double Y1, double X2, double Y2); 
  Retta(int X1, int Y1, double m); 

friend ostream &operator<< (ostream &stream, Retta r);

}; 
       
// primo costruttore: assegniamo A, B e C
//3 double! 
Retta::Retta(double coeffX, double coeffY, double tNoto)
  {
   A= coeffX;
   B=coeffY;
   C=tNoto;
  }
  
// secondo costruttore: assegniamo due punti e ricaviamo 
// i coeff. della equazione cartesiana
//4 double! 
Retta::Retta(double X1, double Y1, double X2, double Y2)
   {
     if (X1==X2) // trattiamo a parte il caso di 
                 // retta parallela all'asse y
	     {
	       A=1;
           B=0;
	       C=-X1;
	      }
     else if (Y1==Y2) //retta parallela al'asse x
          {
            A=0;
	        B=1;
	        C=-Y1;
          }
     else // caso generale dalla geometria sappiamo 
          // che è A=(y1-y2), B=(x2-x1) 
          //       C=-x2*(y1-y2)+y2*(x1-x2);
	      {
            A=Y1-Y2;
	        B=X2-X1;
	        C=-X2*(Y1-Y2)+Y2*(X1-X2);
          }
   }
  
// terzo costruttore: assegniamo un punto ed un 
// coefficiente angolare e calcoliamo A, B e C
//due int e 1 double! 
Retta::Retta(int X1, int Y1, double m)
   {
     // dalla geometria A=m, B=-1, C=-mX1+Y1
     A= m;
     B=-1;
     C=-m*X1+Y1;
   }
 	    



ostream &operator<< (ostream &stream, Retta r)
   {
     stream << "La retta ha equazione cartesiana: \n"
            << "\t " << r.A << " X + " 
            << r.B << " Y + " 
            << r.C << " = 0\n"
            << "Ha coefficiente angolare m = "
            << (-r.A/r.B) << "\n\n"; // se B è zero?
     return stream;     
   } 		 


int main()
{
  // costruzione retta mediate coordinate di due suoi punti
  Retta r1(0.0, 0.0, 10.0, 20.0); 
  
  // costruzione retta mediate coordinate di un suo punto 
  // (a coordinate int) e coeff.angolare (double)
  Retta r2(0, 0, 2.0);  
  
  // costruzione retta mediate i coefficienti 
  // dell'equazione cartesiana
  Retta r3(2.0, -1.0, 0.0);     
  
  // stampa informazioni sulle rette definite
  cout << r1 << r2 << r3;
    
  return 0;
} // End main()
