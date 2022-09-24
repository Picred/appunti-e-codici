#include <string>
#include <iostream>

using namespace std;

int main(){

  string AAA="AAA";
  string AAAA="AAAA";
  string abcdef="abcdef";
  string ffff="ffff";
  string abcdefa="abcdefa";
  
  cout << AAA << "<" << AAAA << "?" << (AAA<AAAA) << endl;

  cout << abcdef << "<" << ffff << "?" << (abcdef<ffff) << endl;

  cout << abcdef << "<" << abcdefa << "?" << (abcdef<abcdefa) << endl;
  
}
