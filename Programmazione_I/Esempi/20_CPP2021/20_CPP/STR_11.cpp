#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(){
  
  string s1("Alfio Aldo");

  s1.insert(5, " Giancarlo "); //Alfio Giancarlo Aldo

  cout << s1 << endl;

  return 0;
}
