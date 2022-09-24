#include <iostream>
#include <string>

/* 

Il programma chiede all'utente di inserire una stringa, 
un numero che rappresenta il primo carattere della stringa 
che l'utente desidera stampare, ed un altro numero che rappresenta il numero di caratteri totali da stampare. 

- Ciclo while
- Ciclo for 

*/

using namespace std;

int main(){
  
  string mystr;
  int start, len, len_str;

  cout << "Please insert the string: " << endl;
  cin >> mystr;

  cin.ignore(10000, '\n');

  len_str = mystr.length();

  cout << "Please insert the number of the first character to print (min=1, max=" << mystr.length() << ")";
  cin >> start;

  if(cin.fail()){
    cout << "ERROR: Inserted value is not a number!";
    return -1;
  }

  if(start<1 || start > mystr.length()){
    cout << "ERROR: Inserted value is out of range!";
    return -1;
  }

  cout << "Please insert the number of characters to print (max=" << len_str-start+1 << ")";
  cin >> len;

  if(cin.fail()){
    cout << "ERROR: Inserted value is not a number!" << endl;
    return -1;
  }

  if(len<=0 || len > len_str-start+1){
    cout << "ERROR: Inserted value is out of range!" << endl;
    return -1;
  }

  cout << "**Stampa con ciclo while**" << endl; 
  int counter=start-1;
  while(counter<(start-1)+len){
    cout << "Char " << counter+1 << ": " << mystr.substr(counter,1) << endl;
    counter++; 
  }

  cout << "**Stampa con ciclo for**" << endl; 
  for(counter=start-1; counter<(start-1)+len;counter++){
    cout << "Char " << counter+1 << ": " << mystr.substr(counter,1) << endl;
  }
}
