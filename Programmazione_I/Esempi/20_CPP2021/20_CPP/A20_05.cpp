#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std; 

int main(){

  string s = "0123456789";

//  cout << s[10000] << endl; //Segmentation fault! 
  try {
    cout << s.at(10000) << endl; 
} catch (const std::exception& e) { // reference to the base of a polymorphic object
     std::cout << "Caught exception: " << e.what() << endl; // information from length_error printed
}

}
