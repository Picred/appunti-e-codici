#include <iostream>

using namespace std;

int main(){

   //COMPILATION WARNING: overflow!
   int b=(1.0E100); 
   cout << "b=1.0E100, "<< "b (NO  cast): " << b << endl;

   //NO warning, ma casting inutile
   int a=static_cast<int>(1.0E100);
   cout << "a=1.0E100, "<< "a (cast): " << a << endl;
  
   //Anche qui casting e' inutile, nessun  warning
  //ma nella conversione a int perdiamo informazioni
   int c=static_cast<int>(1.123456);
   cout << "c=1.123456, "<< "c (cast): " << c << endl;

   //rounding to int value
  //per arrotondare correttamente
   float price = 34.6;
   int rounded = price + 0.5;

   cout << "Price: " << price << ", rounded (int, NO cast, implicit conversion): " << rounded << endl;

    //rounding to int value, but want to leave 
    //the result in a floating point variable. 
    //How? Explicit conversion
   float rounded1 = (int) (price + 0.5);
   cout << "Price (float) : " << price << ", rounded (float, explicit cast!): " << rounded1 << endl;

   rounded1 = static_cast<int>(price + 0.5);
   cout << "Price (float) : " << price << ", rounded (float, explicit named cast!): " << rounded1 << endl;


   
}
