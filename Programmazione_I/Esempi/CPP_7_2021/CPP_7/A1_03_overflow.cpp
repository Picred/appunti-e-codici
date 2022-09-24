#include <iostream>
#include <climits>

using namespace std;

int main(){

   // 1-Integer overflow!
   cout << "Overflow: INT_MAX=" << INT_MAX << " INT_MAX+1000= " << INT_MAX+1000 << endl;  
   
   // 2-No overflow! Suffix used! Compiler knows that 1000L is a long and applies a
   // promotion
   cout << "No overflow: INT_MAX=" << INT_MAX << " INT_MAX+1= " << INT_MAX+1000L << endl;

   /*
   * Suffixes:  LL for long long, L for long, f for float
   */
   
   //The result will be an integer, no conversion to floating point
   cout << "No any promotion: (3 +4+6)/2=" << (3+4+6)/2 << endl;

   //Now the printed result should be correct, 2.0 is a double
   cout << "Promotion to double: (3 +4+6)/2=" << (3+4+6)/2.0 << endl;

   //The result should be correct also in this case, 2.0 is a float. We use a suffix
   cout << "Promotion to float: (3 +4+6)/2=" << (3+4+6)/2.0f << endl;
  
   //overflow for a float say us we have obtained infinity! 
    float res = 10E10*10E30;
    cout << "Un risultato float molto grande : " 
        << res << endl << endl;

}
