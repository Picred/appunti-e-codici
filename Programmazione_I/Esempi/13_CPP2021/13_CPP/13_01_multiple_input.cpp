#include <iostream>
#include <string>
#include <limits>

using namespace std;

/* DUE Input (stringhe) di natura differente 
*  + Controllo errore
* - Controllo EOF 
* + Caratteri ``garbage'' vengono scartati  
*/ 

//Provare i seguenti input: 
//Pippo 
//Pippo pippo2 
int main(){
  
  float x; 

  //1.Primo input
  cout << "Insert a number: " << endl;
  cin >> x;

  //2.Controllo eventuali errori.
  if(cin.fail()){ //some IO error!
    cerr << "IO error: cin.fail()=" << cin.fail() << endl;
    //3.reset stato di errore dell'oggetto cin..
    cout << "Now clearing the error flags.." << endl;
    cin.clear();
    cout << "cin.fail()=" << cin.fail() << endl;
  }
  else
    cout << "You entered: " << x << endl;

  //scarta ulteriore input 
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  //4. Now we are ready to take some more input and to check for
  //any error..
  cout << "Now let's take some more input for a different reason. Please insert another number:" << endl;
  cin >> x;

  //5.Notifica errore 
  if(cin.fail()){ //some IO error!
    cerr << "IO error: cin.fail()=" << cin.fail() << endl; 
  }
  else
    cout << "You entered:  " << x << endl;

  cout << "Exit!" << endl;
}
