#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//print a square matrix. Each element is the sum of the two indeces

int main()
{  
   const int N = 6;

   for (double x = 1; x <= N; x++)
   {
      // Print table row

      for (int n = 1; n <= N; n++)
      {
         cout << setw(2) << x << n;
      }
      cout << endl;
   }

  
  for(int counter=0; counter < 6; counter++)
    cout << setw(3) << "#"; 
  cout << endl;

  //print the lower triangular matrix
   for (double r = 1; r <= N; r++)
   {
      // Print table row, only elements for which c<=r

      for (int c = 1; c <= r; c++)
      {
         cout << setw(2) << r << c;
      }
      cout << endl;
   }


  for(int counter=0; counter < 6; counter++)
    cout << setw(3) << "#"; 
  cout << endl;


  //print the upper triangular matrix
   for (double r = 1; r <= N; r++)
   {
      // Print table row, only elements for which c>=r

      for (int c = 1; c <= N; c++)
      {
	if(c>=r)
         cout << setw(2) << r << c;
	else
	cout << setw(3) << ""; 
      }
      cout << endl;
   }

   return 0;
}
