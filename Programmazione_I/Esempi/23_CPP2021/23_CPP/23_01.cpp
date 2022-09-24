#include <iostream>

using namespace std;

class C{

  int x,y,z; 

  public:
    C(int a, int b, int c){
      x = a;
      y = b;
      z = c;  
    }

    void foo(int x){
      x = x + x; 
      cout << "foo(), x=" << x << endl;
    }

    void foo1(int x){
      this->x+= x; 
      cout << "foo1(), x=" << x << ", this->x= " << this->x << endl;
    }

    int getX(){
      return x; 
    }
};

int main(){

  C test(1,2,3);  

  test.foo(10);
  cout << "main(), getX()=" << test.getX() << endl;

  test.foo1(10);
  cout << "main(), getX()=" << test.getX() << endl;
     
}
