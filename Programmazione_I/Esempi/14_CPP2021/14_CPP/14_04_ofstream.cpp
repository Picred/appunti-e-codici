#include <iostream>
#include <fstream>
#include <string>

#define FILENAME_WRITE "A14_04_DATA.txt"

using namespace std; 

/* Uso della classe ofstream per scrittura di file 
* Uso metodo fail() per verifica eventuali errori 
*/ 
int main(){

  string s; 
  
  
  ofstream myfile;

  //metodo open
  myfile.open(FILENAME_WRITE); //NB: nessun flag per specificare apertura in scrittura!

  //controllo presenza di eventuali errori in fase di apertura file 
  if(!myfile.is_open()){
    cerr << "Error opening file " << FILENAME_WRITE << endl;
    return -1;
  }

  myfile << "A14_04 pippo test pippo2" << endl; 
  //uso del metodo fail 
  if(myfile.fail())
    cerr << "Error writing on file " << FILENAME_WRITE << endl;
  else
    cout << "Written data on file " << FILENAME_WRITE << endl;        

  myfile.close();
}
