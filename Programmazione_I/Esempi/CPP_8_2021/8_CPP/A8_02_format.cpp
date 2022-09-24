#include <iostream>
#include <iomanip>

using namespace std;

int main(){

   float a=12.3456789848484;
   float b = 12.3;

  cout << "The number 12.3456789848484  printed with default settings: " << a << endl;
  
  cout << "Now the precision is set as 7 : " << setprecision(7) << a  << endl;

  cout << "Now the precision is set as 7 (+ flag fixed) :" << fixed << setprecision(7) << a  << endl;

  cout << "The number 12.3  printed with setprecision(5) and scientific:" << scientific << setprecision(5) << b << endl;

  //cout << "The number b (still) printed in scientific notation: " << b << endl;

  //let's RESET the default flags
  cout << "The number a printed with default flags: " << defaultfloat << a << endl;

  cout << "The number a printed with setw(20)" << setw(20) << a << endl;

     
}
