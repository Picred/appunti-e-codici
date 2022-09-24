#include <iostream>
#include <sstream>


using namespace std;


int main()
{    
   int number1,   // first number to add
       number2,   // second number to add

   // read in first number from user as an int 
   cout << "Enter first integer : ";
   cin >> number1;
      
   // read in second number from user as an int
   cout << "Enter second integer : ";
   cin >> number2;


   // convert int into string 
   stringstream sstm1, sstm2;
   sstm1 << number1;
   string first = sstm1.str();
   sstm2 << number2;
   string second = sstm2.str();


   // initialize result to the empty string
   string result = "";

   if ( number1 == number2 )
      result = first + " == " + second + "\n\n";

   if ( number1 != number2 )
      result = first + " != " + second + "\n\n";

   if ( number1 < number2 )
      result = result + "\n" + first + " < " + second;

   if ( number1 > number2 )
      result = result + "\n" + first + " > " + second;

   if ( number1 <= number2 )
      result = result + "\n" + first + " <= " + second;

   if ( number1 >= number2 )
      result = result + "\n" + first + " >= " + second;

   // Display results
   cout << result << endl;      
            
   return 0;
} // End main()
