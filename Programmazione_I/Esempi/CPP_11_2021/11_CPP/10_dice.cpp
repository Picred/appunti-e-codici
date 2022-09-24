#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{  

  //dice : 1...6
  const short a = 1;
  const short b = 6;
  
   srand(time(0));

   for (int i = 1; i <= 10; i++)
   {  
      int d1 = rand() % (b-a) + a;
      int d2 = rand() % (b-a) + a;
      cout << d1 << " " << d2 << endl;
   }
   cout << endl;
   return 0;
}
