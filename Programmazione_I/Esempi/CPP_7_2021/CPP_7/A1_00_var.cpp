#include <iostream>

using namespace std;

int main(){

  //1-SIMPLE VARIABLE DEFINITIONS and initialization
  int a=-10;
  int b=25;
  int media1;
  float media2;

  //2-COMPILATION ERROR, bad values
  //int j="34"; 

  float k = 10.6; 

  cout << "k=" << k << endl;

  media1=(a+b)/2.0;
  media2=(a+b)/2.0;

  cout << "media1=" << media1 << endl;
  cout << "media2=" << media2 << endl;

  cout << "k=" << k << endl;

  //COMPILATION error, bad names for variables
  //int 6john = 10; // the name cannot start with a number!
  //int can volume; // the name cannot have any space!
  //float double=50.6; // we cannot use a reserved word!

  //int p = 10;
  //int ai = 56 * p;
  //ERROR at compile-time. The instruction above will give a compilation error. p should be defined before its use

  const int Z = 12;

  
  //Z=23; //Compilation error!
  
  int kk=10;
  kk++; // add 1 to kk
  kk--; // subtract 1 from kk 
  kk+=10; // add 10 to kk. 
  kk=kk+10; //same as above

  cout << "kk=" << kk << endl;

  cout << "(kk--)=" << (kk--) << endl;

  //cout << "(--kk)=" << (--kk) << endl;

  cout << "kk=" << kk << endl;

   return 0;

}
