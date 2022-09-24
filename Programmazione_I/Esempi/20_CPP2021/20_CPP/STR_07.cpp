#include <iostream>
#include <cctype> 

using namespace std;

int main(){
  
  char c = 'c';
  char zero = '0';
  char bigC = 'C';   
 
  cout << (isalpha(c)!=0 ? "true!" : "false!") << endl; // is a letter? 
  cout << (isdigit(c)!=0 ? "true!" : "false!") << endl; // is a number 0...9? 
  cout << (isupper(bigC)!=0 ? "true!" : "false!") << endl; // is upper letter? 
 

  return 0;
}
