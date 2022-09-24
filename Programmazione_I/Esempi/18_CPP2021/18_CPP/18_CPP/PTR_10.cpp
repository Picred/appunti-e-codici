#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Test{
  
  public:
    Test(); 
    Test(int a, int b);

    void foo();     
};

void Test::foo(){
  cout << "Hello!" << endl;
} 

 Test::Test(int a, int b){
  cout << "a: " << a << ", b:" << b << endl;
}

Test::Test(){

}

int main()
{
  Test t;

  Test *ptr = &t;

  ptr->foo();

  (*ptr).foo();

  Test *p = new Test();  // dynamic allocation
  Test *p1 = new Test(5,10); //dynamic allocation

  p->foo();

  delete p; // free memory
  delete p1; //free memory
}

