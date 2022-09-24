#include <iostream>
#include <iomanip>

using namespace std;

int main(){

   float a=12.3456789848484;
   float b = 12.3;

  cout << "The number 12.3456789848484  printed with default settings:" << a << endl;
  cout << "Now the precision is set as 7:" << setprecision(7) << a  << endl;
  cout << "Now the precision is set as 7:" << fixed << setprecision(7) << a  << endl;

  cout << "The number 12.3  printed with setprecision(5) and scientific:" << scientific << setprecision(5) << b << endl;
     
}
