#include <iostream>
#include <cstring> //strlen(), strcpy(), etc
#include <cstdlib> // atoi, atol, etc

using namespace std;

int main(){
  
  char str1[] = "1";
  char str2[] = "12";
  char str3[] = "13a";
  char str4[] = "a13";
  char str5[] = "0";

  int n; 

  cout << "** atoi(const char *s) **" << endl;
  cout << atoi(str1) << endl; // OK 1 
  cout << atoi(str2) << endl; // OK 12
  cout << atoi(str3) << endl; // no error, return 13
  cout << atoi(str4) << endl; // error is..0! 
  cout << atoi(str5) << endl; // this is still 0!

  cout << "** strtol(const char *nptr, char **endptr) **" << endl;
  //strtol()
  char *end;
  const char *a = "0";
  const char *b = "aa";
  // strotol(cons)
  if((n=strtol(a, &end, 10))==0 && (*end!='\0')) // error?
    cout << "Error while converting string " << a << endl;
  else
    cout << "Converted: " << n << endl;

  if((n=strtol(b, &end, 10))==0 && (*end!='\0')) // error?
    cout << "Error while converting string " << b << endl;
  else
    cout << "Converted: " << n << endl;

  cout << "** atoi()/atof() **" << endl;
  int l = atoi("1000000000000"); //overflow
  cout << "l: " << l << endl;

  long int k = atol("1000000000000"); //long
  cout << "k: " << k << endl;

  double x = atof("4.567");
  cout << "x: " << x << endl;

  x = atof("4.5E10");
  cout << "x: " << x << endl;

  x = atof("4.5k"); //ERR
  cout << "x: " << x << endl; // ??

  x = atof("k4.5"); //ERR
  cout << "x: " << x << endl; // ?? as atoi().. 

  //you may use strtod()..  
  const char *c = "k4.5"; 
  if((x=strtod(c, &end))==0 && (*end!='\0')) // error?
    cout << "Error while converting string " << c << endl;
  else
    cout << "Converted: " << x << endl;
  
}
