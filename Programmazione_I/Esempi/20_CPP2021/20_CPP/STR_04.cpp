#include <iostream>
#include <cstring> //strlen(), strcpy(), etc 

using namespace std;

int main(){
  
  char str1[] = "pippo";
  char str2[] = "moda";
 
  /* STRLEN */ 
  cout << "len(str1): " << strlen(str1) <<  endl;
  cout << "len(str2): " << strlen(str2) <<  endl;

  cout << "len(\"pippo1\"): " << strlen("pippo1") <<  endl;

  /* STRCMP */
  int r = 0;
  const char* tmp = "Pippo";
  if((r=strcmp(str1, tmp)) < 0)
    cout << "String " << str1 << " is less than " << tmp  << endl;
  else if(r>0)    
    cout << "String " << str1 << " is greter than " << tmp << endl;
  else    
    cout << "String " << str1 << " is equal to " << tmp << endl;

  const char* tmp1 = "zzzz";
  if((r=strcmp(str1, tmp1)) < 0)
    cout << "String " << str1 << " is less than " << tmp1  << endl;
  else if(r>0)    
    cout << "String " << str1 << " is greter than " << tmp1 << endl;
  else    
    cout << "String " << str1 << " is equal to " << tmp1 << endl;

  /* STRCPY */
  cout << "Copying " << str2 << " into " << str1 << ".." << endl;
  strcpy(str1, str2); //str1 <--str2;
  
  cout << "str1: " << str1 << ", str2:" << str2 << endl;

  /* STRSTR */
  char s[15] = "Abracadabra";
  char *found = strstr(s,"dab");
  if(found!=NULL)
    cout << "Found: " << found << endl;     // prints dabra
  else
    found[2] = 'X';
  cout << found << endl; 
  cout << s << endl; 

  /* ESERCIZIO: usare la versione ``bounded'', ovvero strncmp() e strncpy() */
}
