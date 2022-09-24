#include <iostream>
#include <cstring> // equivalente a #include <string.h> in C

using namespace std;

int main(){
  
  char *str;
  const int L = 6;
  int k;

  str= new char[L+1]; //chiede allocazione di memoria nello ``heap''
  char *ps = str; // il nome di un array e' puntatore a char
  for ( k= 0; k< L ; ++k)
    *ps++= '*';
  *ps= 0;
  cout << "str: " << str << endl;  // ***** ...
  delete[] str;  //libera memoria, parentesi quadre perche' si tratta d array di ``oggetti''  
}
