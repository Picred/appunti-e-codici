#include <iostream>

using namespace std;

int main(){
  
  string input;
  
  string s; //stringa vuota
  string s1("test");
  string s2 = "test2";  
  string s3(s1+", a new test");  

  cout << s << endl;  //overloading operatore << per string
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;  

  cin >> input; //overloading operatore >> per string

  input+=", fixed input"; 

  cout << (s1 < s2) << endl; // overloading operatori per confronto stringhe
  
  // uso operatore [] per indicizzazione carattere   
  cout << s1[2] <<  endl; //stampa s
  cout << s1[6] << endl; // ?? stampa nulla, 6 e' out of range

  //invece con substr()..
  cout << s1.substr(6,1) << endl; // errore: exception!

  return 0;
}
