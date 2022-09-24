#include <iostream>

using namespace std; 

class ClasseX{

  int x, y;
  double d1,  d2; 

  public: 
    ClasseX(int a, int b, double d1, double d2); 

    void setData(int); //1
    void setData(int, int); //2 
    void setData(double, double);  //3
}; 

void ClasseX::setData(int a){
  this->x = a;
}

void ClasseX::setData(int a, int b){
  this->x = a;
  this->y = b;
}


void ClasseX::setData(double a, double b){
  this->d1 = a;
  this->d2 = b;
}

ClasseX::ClasseX(int a, int b, double d1, double d2){
  this->x = a;
  this->y = b;
  this->d1 = d1;
  this->d2 = d2;
}

int main(){

  ClasseX obj(1,2,4.5,6.7); 

  obj.setData(10); //1 
  obj.setData(9.8); //1 
  obj.setData(10,10); //2
  obj.setData(10.3,10.2); //3
  //obj.setData(2.3, 5); // ?? NB!
  //obj.setData(5, 2.3); //?? NB!
  
}
