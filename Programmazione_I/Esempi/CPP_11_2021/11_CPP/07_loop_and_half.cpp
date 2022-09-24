#include <iostream>

using namespace std;

int main()
{ 

  int input;
  int even=0; 

  /* The loop will stop if 
    the user enters two consecutive even numbers
    or the input is not a number
    or the input is not a positive number. 
  */
  
  do{
    cout << "Please enter a positive number (or a negative one to exit): " << endl; 
    cin >> input;
    if(cin.fail()) //failed
      break; 
    cout << "Entered: " << input << endl;
  
    if(input%2==0)
      even++;
    else 
      even=0;

  }while(even<2 && input>0);

  cout << "EXIT!!" << endl;

  return 0;
}
