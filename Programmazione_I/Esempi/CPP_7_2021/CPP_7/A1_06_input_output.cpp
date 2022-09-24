#include <iostream>


using namespace std;


int main()
{
    
   int number1,   // first number to add
       number2,   // second number to add
       sum;       // sum of number1 and number2

   // read in first number from user as an int 
   cout << "Enter first integer : ";
   cin >> number1;
      
   // read in second number from user as an int
   cout << "Enter second integer : ";
   cin >> number2;

   // add the numbers
   sum = number1 + number2;

   // display the results
   cout << "The sum is " << sum << endl;      
            
   return 0;
} // End main()
