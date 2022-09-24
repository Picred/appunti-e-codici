#include <iostream>
#include <fstream>
#include <string>

#define FILENAME_WRITE "A14_05_DATA.txt"

using namespace std; 

/* Uso della classe fstream per scrittura di file 
*  uso metodo fail() per controllo errore. 
*/ 
int main(){

 // string s; 
  
  fstream myfile;

  //metodo open
 // myfile.open(FILENAME_WRITE, std::fstream::out);
  //FM provare anche append ed eseguire il programma diverse volte
  myfile.open(FILENAME_WRITE, std::fstream::out | std::fstream::app);

  //controllo presenza di eventuali errori in fase di apertura file 
  if(!myfile.is_open()){
    cerr << "Error opening file " << FILENAME_WRITE << endl;
    return -1;
  }

  myfile << "Terza esecuzione" << endl; 
  //uso metodo fail()
  if(myfile.fail())
    cerr << "Error writing on file " << FILENAME_WRITE << endl;
  else
    cout << "Written data on file " << FILENAME_WRITE << endl;        

  myfile.close();
}
