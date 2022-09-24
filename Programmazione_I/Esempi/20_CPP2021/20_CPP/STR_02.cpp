#include <iostream>
#include <cstring> // equivalente a #include <string.h> in C

using namespace std;

int main(){
  
  char *str;
  const int L = 20;
  int k;

  str= new char[L+1]; //chiede allocazione di memoria nello ``heap''
  cout << "After allocation, p-str: " <<  static_cast<void *>(str) << endl;

  for ( k= 0; k< L ; ++k)
    str[k]= '*';
  str[k]= 0;

  cout << "str: " << str << endl;  // ***** ...

  delete[] str;  //libera memoria, parentesi quadre perche' si tratta d array di ``oggetti''  
  cout << "After deallocation, p-str: " <<  static_cast<void *>(str) << endl;  //stesso indirizzo! 
  str[0] = 'c'; //undefined behaviour, str 

  cout << str << endl;

  //allora meglio..
  char *str1 = new char[L]; 
  cout << "After allocation, p-str1: " <<  static_cast<void *>(str1) << endl;
  for ( k= 0; k< L ; ++k)
    str1[k]= '*';
  str1[k]= 0;
  cout << "str1: " << str1 << endl;  // ***** ...      
  delete[] str1;
  cout << "After allocation, p-str1: " <<  static_cast<void *>(str1) << endl;
  //Dopo questa riga di codice str1 non sara' piu' un puntatore valido
  str1 = NULL; 
  cout << "p-str1: " << static_cast<void *>(str1) << endl;  // ***** ...      

  //str1[0]='c'; //segmentation fault 
  
  //meglio ancora..
  if(str1!=NULL)  
    str1[0]='c'; //segmentation fault 
}
