#include <iostream>
#include <string>

using namespace std;

int main()
{  
   cout << "Enter your first name: ";
   string first;
   cin >> first;
   cout << "Enter your surname: ";
   string second;
   cin >> second;
   string initials = first.substr(0, 1) 
      + "." + second;
   cout << initials << endl;

   string ending_char = second.substr(second.length()-1,1);
   cout << "Last char of surname: " << ending_char << endl; 

   return 0;
}
