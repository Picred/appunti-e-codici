#include <iostream>
#include <cctype>

using namespace std;

void toLower(char *str)
{
  while (*str) 
  {
    *str= tolower(*str);
    str++;
  }
}

int main(){
  
  char str[] = "AAbb";
  cout << str << endl;      
  toLower(str);
  cout << str << endl;      
      
  return 0;
}
