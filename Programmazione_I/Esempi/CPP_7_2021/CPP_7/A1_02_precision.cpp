#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//FLOATING POINT NUMBERS 

int main(){

   //single vs double precision
  float b=5.123456789f;   //precisione singola

  cout << "b è in singola precisione, b=" << fixed << setprecision(6) <<b << endl;
   //8 cifre, arrotondamento
  cout << "b è in singola precisione, b=" << fixed << setprecision(8) <<b << endl;
  cout << "b è in singola precisione, b=" << fixed << setprecision(10) <<b << endl;
    
      /*
      cout << fixed << setprecision(k); --> print k digits after the decimal point      
      cout << setprecision(k); --> print k digits in overall
      cout << scientific << setprecision(k); --> print k digits in scientific notation
      */
   
  double c=0.123456789123456789123456; //precisione doppia 
  cout << "c è in doppia  precisione, c=" << fixed << setprecision(6) <<c << endl;
  cout << "c è in doppia precisione, c=" << fixed << setprecision(8) <<c << endl;
  cout << "c è in doppia precisione, c=" << fixed << setprecision(10) <<c << endl;
  cout << "c è in doppia precisione, c=" << fixed << setprecision(15) <<c << endl;
   //20 cifre, arrotodamento dopo la ?? cifra
  cout << "c è in doppia precisione, c=" << fixed << setprecision(20) <<c << endl;

   //4-Scientific notation
  double d=1E06; // scientific notation
  double e=2E-9; //scientific notation
  float f = 1.3E3; // scientific notation 
  cout << endl << scientific << setprecision(2) <<  "d=" << d << ",e=" << e << ", f=" << f << endl;

   //5-UNINITIALIZED variable (Warning at compile-time if you set the flag "-Wall"). What about the value of NI? 
  int ni; 
  cout << endl << "Var ni was not initialized, ni=" << ni << endl;

  //Constant values
  const int MY_CONSTANT=60;
  //kk=kk*MY_CONSTANT;

//  MY_CONSTANT=10; you cannot assign again a value to a constant
  //compiler error!

  cout << endl << "MY_CONSTANT=" << MY_CONSTANT << endl; 

   //1-Errori di rappresentazione (-->arrotondamento)
   double price = 4.35;
   int cents = 100 * price; // Should be 100 * 4.35 = 435
   cout << endl << price << " dollars in cents: " << cents << endl;  // Prints 434!
   
   // non è sempre quel che si vede ... 
   cout << 4.35 << " with 20 digits:"
        << setprecision(20) << 4.35 << endl << endl;

   cents=100000000 * price; 
   double aux=100000000 * price;
   cout << fixed << setprecision(20) << cents  << "   " << aux << endl << endl;

    //solution. Just add 0.5 to round to the nearest integer
    cout << setprecision(0) << "Cents():" << (4.35 * 100) << endl;
    //solution. Just add 0.5 to round to the nearest integer
    cout << setprecision(0) << "Cents(+0.5):" << (4.35 * 100 + 0.5) << endl;

  /*The binary representation of 4.35 is 
   100.01 0110 0110 0110 ...
   as there is not an exact representation of the number 0.35 in the binary system
   It is the same thing as for the decimal system, e.g. for the number 1/3=0.333333...

  Therefore, computing 4.35 * 100 in binary representation
  will be 110110010.11111111...
  an "infinite" number of literal 9 as decimal after 434
  434.999999...
  But the machine is able to represent only a finite   number of 1s.
  The results is 434.99999... which, if represented as integer will be 434!!  

   Why? The rounding to an integer discards the fractional part! 
   */
     
   /* Errori di approssimazione (troncamento)
    La radice di 2 è un numero irrazionale, la sua computazione sarà as un certo punto "troncata"
    quindi calcoliamo un valore troncato
   */
   double r = sqrt(2.0); //irrational number!
   cout << "sqrt(2) squared is not 2 but " << setprecision(20) << r * r << endl;

}
