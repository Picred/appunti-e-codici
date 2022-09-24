#include <iostream>
#include <string>
//Strings are provided by the standard library

using namespace std;

int main()
{  
   string str1 = "Franco";
   string str2 = "Francesco";
      
   //concatenazione delle due stringhe appena definite
   string messaggio = str1 + str2; 

   cout << messaggio << endl;  
     
   string s("Franco");
   
   if (s == str1) {
        cout << "Uguali\n";
   }

   if (str1 < str2) cout << "Minore!\n";
         else  cout << "Maggiore!\n";
            
   return 0;
} // End main()
