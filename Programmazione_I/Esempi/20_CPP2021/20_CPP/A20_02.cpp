#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std; 

int main(){ 

  cout << atoi("012") << endl; 
  cout << atoi("aa012") << endl; // output: 0. No controllo errore...
  cout << atoi("0") << endl; 
  cout << atoi("-12") << endl; 

  cout << atof("0.14") << endl; 
  cout << atoi("aa0.12") << endl; // output: 0. No controllo errore...
  cout << atof("0") << endl; 
  cout << setprecision(10) << atof("-12.123456") << endl; 
}
