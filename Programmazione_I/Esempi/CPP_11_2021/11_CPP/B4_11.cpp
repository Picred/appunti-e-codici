#include <iostream>

using namespace std;


int main()
{ 
    const int MAX_RIGHE = 10;

    int riga;  //conta le righe
    int i;     //conta gli asterischi
      
    for (riga = 1;   riga <= MAX_RIGHE;   riga++)
      {
         for (i = 1;  i <= riga;   i++)
            cout << "*";
          
         cout << endl;
      } 
                  
   system("PAUSE");
   return EXIT_SUCCESS;
}
