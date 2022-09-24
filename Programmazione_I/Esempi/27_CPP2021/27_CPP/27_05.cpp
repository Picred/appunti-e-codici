#include <iostream>

using namespace std; 

class X{
     int x, y;
     float z;
     public:
       X(int=0, int=0, float=0.0);
};

X::X(int a, int b, float c){
  this->x = a;
  this->y = b;
  this->z = c; 
  cout << x << ", " << y << ", " << z << endl;
}

int main(){
  X x1{};
  X x2{1};
  X x3{1,2};   
}
