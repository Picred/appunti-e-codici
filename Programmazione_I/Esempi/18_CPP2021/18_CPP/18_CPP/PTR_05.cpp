#include <iostream>

using namespace std;

//prototipo della funzione, 
//di norma si scrive in un file header
void swap(int*, int*);

int main()
{
 int x=5, y=10;
 cout<<"Before swap: x "<<x<<" y "<<y<<endl;

 swap(&x,&y); // &x and &y are the addresses of variables x and y

 cout<<"After swap: x "<< x <<" y "<<y<<endl;
 return 0;
}

void swap(int* x, int* y)
{  
  int temp;	
  temp = *x;
  *x = *y;
  *y = temp;
}
