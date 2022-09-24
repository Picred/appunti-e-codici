#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*
* DUE Input, DUE LOOP 
* 1 numero 
* 2 stringa
* + controllo errore, EOF, scarta caratteri di garbage
*/ 
int main(){
  
  double x;
  string s;
  bool end =false;
  bool eof=false;

  //1.PRIMO INPUT, UN NUMERO, FINCHE' L'UTENTE 
  //NON INSERISCE UN NUMERO VALIDO! 
  while(!end){
    cout << "Insert a number: " << endl; 
    cin >> x; 

    //eof will not end the loop!
    if(cin.eof()){
	cerr << "EOF!" << endl; 
	eof=true; 
	cin.clear(); 
    }

    //2.Controllo eventuali errori.
    else if(cin.fail()){ // IO error!
      cerr << "IO error: cin.fail()=" << cin.fail() << endl;
      eof=cin.eof();
      //3.reset stato di errore dell'oggetto cin..
      cerr << "Now clearing the error flags.." << endl;
      cin.clear(); 
      cerr << "cin.fail()=" << cin.fail() << endl;
      cout << "Invalid input!" << endl;
    }

    else{
      cout << "You entered: " << x << ", the result is " << (x/2) << endl;
      end=true;
    }

    //if not eof ignore the remaining chars, useful for the next block (user will give a string)
    if(!eof)
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore the remaining chars
    else
      eof=false; //reset boolean variable
  }//end while

  end=false;

  //SECONDO INPUT, UNA STRINGA
  while(!end){
    //4. Now we are ready to take a string as input
    cout << "Please insert a string:" << endl;
    cin >> s;

    //5.Notifica errore 
    if(cin.fail()){ // IO error!
      cerr << "IO error: cin.fail()=" << cin.fail() << endl;
      cin.clear();
    }

    else{
      cout << "You entered:  " << s << ", three times your string is: " << s + s +s << endl;
      end=true; // ok
    }

      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore the remaining chars
  }//end while
}
