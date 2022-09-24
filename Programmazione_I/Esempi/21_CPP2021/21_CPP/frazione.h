#ifndef FRAZIONE_H
#define FRAZIONE_H

#include <string>

using namespace std;



//**************
class Frazione {
//**************

public:  

   Frazione(int x, int y=1); 
   
   Frazione piu(Frazione f) const; 
   Frazione meno(Frazione f) const; 
   Frazione per(Frazione f) const; 
   Frazione diviso(Frazione f) const; 

   Frazione inversa() const; 

   bool equals(Frazione f) const; 
   bool eMinore(Frazione f) const; 
   bool eMaggiore(Frazione f) const; 
   
   int numeratore() const;
   int denominatore() const; 

   friend ostream &operator<< (ostream &stream, Frazione);

private: 
        
   int num, den;
   
   static int mcd(int a,int b)
      {
        int resto;
        do {
             resto = a % b;
             a = b;
             b = resto;
        } while (resto != 0);
        return a; 
      }  

};   // End class Frazione



#endif
