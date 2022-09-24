#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Test{
  
  public:

    void foo();     
};

void Test::foo(){
  cout << "Hello!" << endl;
} 

int main()
{
  Test t; // allocazio oggetto

  Test *ptr = &t;

  ptr->foo();

  (*ptr).foo();
}

