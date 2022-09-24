#include <iostream>

using namespace std; 

int main(){

  for(int c=0; c<128; c++)
    cout << c << ":" << (char) c << endl; //stampa i caratteri ASCII da 0 a 127
      cout << "===========" << endl;

  for(int c=0; c<127; c++) // 
    cout  <<  (char) c << "<" << (char) (c+1) << "?" << (c<c+1) << endl;
}
