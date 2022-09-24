#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std; 

int main(){

  int x;
  double y; 
  float f; 

  const char *integer1 = "22aa1234";
  const char *integer2 = "1234";

  const char *floating_point_number = "1234.199456789"; 
  const char *floating_point_number2 = "1234.56789012345";

  //converte il numero intero, solo la prima cifra!
  cout << "The integer1 string is "     << integer1 << endl; 
  if(sscanf(integer1, "%1d", &x)<1)
    cerr << "Error parsing integer1 number" << endl;   
  else 
    cout << "The integer number is " << x << endl; 

  //converte il numero intero, le prime due cifre
  cout << "The integer1 string is "     << integer1 << endl; 
  if(sscanf(integer1, "%d", &x)<1)
    cerr << "Error parsing integer1 number" << endl;   
  else 
    cout << "The integer number is " << x << endl; 

  //le prime tre cifre di integer3
  cout << "The integer2 string is "     << integer2 << endl; 
  if(sscanf(integer2, "%3d", &x)<1)
    cerr << "Error parsing integer2 number" << endl;   
  else 
    cout << "The integer number is " << x << endl; 

  //float: lettura di 4 cifre (incluse le cifre a sinistra della virgola e la virgola!)
  cout << "The floating point number string is  "    << floating_point_number << endl; 
  if(sscanf(floating_point_number, "%4f", &f)<1) // f is ``floating point number'', i.e. float
    cerr << "Error parsing floating point number" << endl;   
  else 
    cout << "Read number " << f << endl;    

  //float: lettura di 10 cifre (incluse le cifre a sinistra della virgola!)
  cout << "The floating point number string is  "    << floating_point_number << endl; 
  if(sscanf(floating_point_number, "%10f", &f)<1) // lf is ``long floating point number'', i.e. double
    cerr << "Error parsing floating point number" << endl;   
  else 
    cout << "Read number " << setprecision(15) << f << endl;    

  //double: lettura di 16 cifre
  cout << "The floating point number2 string is  "    << floating_point_number2 << endl; 
  if(sscanf(floating_point_number2, "%16lf", &y)<1) // lf is ``long floating point number'', i.e. double
    cerr << "Error parsing floating point number" << endl;   
  else 
    cout << "Read number " << setprecision(15) << y << endl;    

}
