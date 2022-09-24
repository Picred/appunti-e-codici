#include <iostream>

using namespace std;


int main()
{ 
    char c = 0;
	cout << "sizeof(char) = " << sizeof(char) << endl << endl;
    	  
    int i;
    for (i = 0;  i < 128;  i++) 
        {
          cout << "Valore: " << (int)c << " Carattere: " << c++ << endl; 
          cout << "Valore: " << i << " Carattere: " << (char)i << endl; 
        }
    
   system("PAUSE");
   return EXIT_SUCCESS;
}
