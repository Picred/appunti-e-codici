#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

/* 
* Il programma chiede allo utente 
* l'inserimento di numeri, uno dopo 
* l'altro, massimo 50. 
* Il programma scrive i numeri inseriti dallo 
* utente in un file. 
* Il programma termina quando 
* l'utente i) ha inserito 50 numeri, 
* oppure ii) se l'utente inserisce EOF 
* iii) oppure ancora se avviene un qualsiasi 
* errore di scrittura. 
*/ 
int main(){

  //al massimo 50 numeri..
  const int MAX_ITEMS=50;
  //End of File
  bool end=false;
  //contatore
  int c=0;
  //variabile per input utente  
  double input; 

  string sep, final_output; 

  //flag per terminazione inserimento input

  //Il nome del file  
  const string FILENAME="out_test.txt";
  
  //Apertura file in modalita' scrittura
  fstream outfile(FILENAME, ios_base::out );

  if(!outfile.is_open()){
    cerr << "Failed to open file " +FILENAME << endl;
    return -1; 
  }

  while(c<MAX_ITEMS && !end){

    //messaggio ad utente
    cout << "Please insert a number, or CTRL+'d' to end .." << endl; 

    //legge input utente
    cin >> input; 
  
    //EOF? Allora il loop terminera'
    if(cin.eof()){
      cout << "EOF!" << endl; 
      end=true; // condizione di terminazione del loop
    }
    
    else if(cin.fail()){
      cerr << "IO error: fail()=" << cin.fail() << endl;

      cerr << "Now clearing the error flags.." << endl;
      cin.clear(); // clear all the error flags
      cerr << "cin.fail()=" << cin.fail() << endl; 

      cerr << "Discarding invalid input.." << endl;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore the remaining characters
    }

    else{
      sep = (++c%5==0 ? '\n' : ' '); 
      if(!(outfile << input << sep)){ //!(stream) equaivalente a outfile.fail()
	cerr << "Error writing on file " + FILENAME + ", aborting.."<< endl;
	outfile.close(); 
	return -1;
      }
    }
  }//end while

  cout << "Written " << c << " numbers on file " + FILENAME << endl;
  outfile.close(); // chiude il file
}
