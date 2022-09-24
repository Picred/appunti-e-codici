#include <iostream>

using namespace std;

int main(){

  int a=30;
  
  switch(a){
    case 30: //if a==30 ...
      cout << "a is 30" << endl;
      break;
    case 40://else if(a==40) ... 
      cout << "a is 40";
      break;
    case 50:
      cout << "a is 50!";
      break;
    case 34:
      cout << "a is 34!";
      break;
    case 10:
      cout << "a is 10!" << endl;   
      break; //without break? 
    case 44:
      cout << "a is 44!";
      break;
    case 90:
      cout << "a is 90!" << endl;
    default: //executed if other cases do not hold
      cout << "a not recognized!";
  }
  
  int b = 7;
  bool odd;

  switch(b){
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
      odd=true;
      break;
    default: //executed if other cases do not hold
      odd=false;
  }

  cout << "Number b is " << (odd ? "odd" : "even") << endl;

  return 0;  
}
