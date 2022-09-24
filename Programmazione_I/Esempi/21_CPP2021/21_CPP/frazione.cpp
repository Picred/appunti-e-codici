#include <iostream>
#include "frazione.h"


   
Frazione::Frazione (int x, int y) 
   {
      bool negativo = x * y < 0;
      //memorizza l'eventuale segno meno
      if (x < 0)
         x = - x;  //elimina l'eventuale segno meno davanti a x
      if (y < 0)
         y = - y;  //elimina l'eventuale segno meno davanti a y
      num = x;
      den = y;
      
      if (y != 0) 
        {  //semplifica la frazione
         int m = mcd(x, y);
         if (negativo)
            num = - x / m;  //il segno meno viene memorizzato al numeratore
         else
            num = x / m;
         den = y / m;
        } 
      else 
        {   //impossibile, rappresentato con num e den a zero
         num = 0;
         den = 0;
        }  
   }

   
Frazione Frazione::piu(Frazione f) const
   {
      int n = this->num * f.den + 
              this->den * f.num;
      
      int d = den * f.den;
      
      return Frazione(n, d);
   }

   
Frazione Frazione::meno(Frazione f) const
   {
      int n = this->num * f.den - 
              den * f.num;
      
      int d = this->den * f.den;
     
      return Frazione(n, d);
   }

   
Frazione Frazione::per(Frazione f) const
   {
      int n = this->num * f.num;
      int d = this->den * f.den;
   
      return Frazione(n, d);
   }

   
Frazione Frazione::diviso(Frazione f) const
   {
      int n = num * f.den;
      int d = den * f.num;
   
      return Frazione(n, d);
   }

   
Frazione Frazione::inversa() const
   {
      return  Frazione(den, num);
   }

   
bool Frazione::equals(Frazione f) const
   {
      if (this->num == f.num && 
          den == f.den)
         return true;
      else
         return false;
   }

   
bool Frazione::eMinore(Frazione f) const
   {
      Frazione g = meno(f);

      if (g.num < 0)
         return true;
      else
         return false;
   }

   
bool Frazione::eMaggiore(Frazione f) const
   {
      Frazione g = meno(f);

      return (g.num > 0);
   }

   
ostream &operator<< (ostream &stream, Frazione f)
   {
      if (f.den == 0)
         cout << "impossibile\n";
      else if (f.den == 1)
         cout << f.num;
      else
         cout << f.num << "/" << f.den;
  
      return stream;     
   }

   
int Frazione::numeratore() const 
   {
      return num;
   }

   
int Frazione::denominatore() const
   {
      return den;
   }


   
