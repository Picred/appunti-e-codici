#include <iostream>

using namespace std;

int main()
{ 

  int input;
  int even=0; 
  bool con=true; 

  /* The loop will stop if 
    the user enters two consecutive even numbers
    or the input is not a number
    or the input is not a positive number. 
  */
  
  while(con){
    cout << "Please enter a positive number (or a negative one to exit): " << endl; 
    cin >> input;
    if(cin.fail() || input < 0){ //failed
      cout << "Numero negativo o errore di IO" << endl; 
      con=false; 
    }

    else{
      cout << "Entered: " << input << endl;
  
      if(input%2==0)
	even++;  
      else
	even=0;

      if(even>=2)
	con=false;
    }
  }

  cout << "EXIT!" << endl;

  return 0;
}
