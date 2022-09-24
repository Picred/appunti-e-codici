#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

  cout << "Rand-max: " << RAND_MAX << endl;
    
   for (int i = 1; i <= 10; i++)
   {  
      int r = rand();
      cout << r << endl;
   }
   return 0;
}
