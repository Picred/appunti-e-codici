#include <iostream>
#include <string>
#include <limits>

using namespace std;

//Provare i segg input:
// 24.6
// 34lsls
// alalala
// + Controllo errore
// - controllo EOF 
// - non si scartano eventuali caratteri inseriti dall'utente dopo la prima stringa!
int main(){

  float x; //floating point to collect the user input

  //1.Input
  cout << "Insert any number: " << endl; 
  cin >> x; 

  //2.Controllo eventuali errori.
  if(cin.fail()){ //some IO error!
    cerr << "IO error: cin.fail()=" << cin.fail() << endl; 
    //3.reset stato di errore dell'oggetto cin..
    cout << "Now clearing the error flags.." << endl;
    cin.clear(); 
    cout << "cin.fail()=" << cin.fail() << endl;
  }
  else{
    cout << "The number you entered is " << x << endl; 
  }

  //4. Now we are ready to take some more inoput and to check for
  //any error. But we should call ignore(.., '\n').. 

  cin.ignore(numeric_limits <streamsize>::max(), '\n') ;

  return 0;

}
