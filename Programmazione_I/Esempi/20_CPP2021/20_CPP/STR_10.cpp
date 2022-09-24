#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
  
  string s1("testabcdEFGTREaaa");

  const char *cstr = s1.c_str(); //from string to char * with '\0'

  //from string to char * with no guarantee thatthe string is terminated with '\0'
  const char *data = s1.c_str();

  cout << cstr << endl;
  cout << data << endl;

  cout  << strlen(cstr) << endl;
  cout  << strlen(data) << endl;

  return 0;
}
