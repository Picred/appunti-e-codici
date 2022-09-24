#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class X{

  int a,b,c;

  public: 

  X(int x, int y,int z){
    a=x;
    b=y;
    c=z;
  }

  X(){
    this->a = this->b = this->c = 0;
  }

  int getA(){
    return a;
  }

  int getB(){
    return b;
  }

  int getC(){
    return c;
  }

  //il terzo parametro (reference) viene poi restituito 
  // come dato di ritorno
  X &sum(const X &a, const X &b, X &result){
      result.a = a.a + b.a;
      result.b = a.b + b.b;
      result.c = a.c + b.c;
      //si provi..
      //a.a = 2;
      return result; 
  }
  
  // nessun tipo di ritorno, ma comportamento identico 
  void sum1(const X &a, const X &b, X &result){
      result.a += a.a + b.a;
      result.b += a.b + b.b;
      result.c += a.c + b.c;
  }

  //attenzione: terzo parametro e' COPIA di 
  //parametro attuale, quindi nessuna modifica 
  //al dato originale
  void fakeSum(const X &a, const X &b, X result){
      result.a += 2*(a.a + b.a);
      result.b += 2*(a.b + b.b);
      result.c += 2*(a.c + b.c);
  }

};

int main()
{ 

  //creazione oggetti 
  X a(1,2,3);
  X b(1,2,3); 

  //
  X res;
  X res1(2,4,8);  

  res = a.sum(a,b,res); 
  a.sum1(a,b,res1); 

  cout << res.getA() << endl; 
  cout << res.getB() << endl; 
  cout << res.getC() << endl; 

  cout << res1.getA() << endl;
  cout << res1.getB() << endl;
  cout << res1.getC() << endl;

  a.fakeSum(a,b,res1); // passaggio per valore
  cout << res1.getA() << endl;
  cout << res1.getB() << endl;
  cout << res1.getC() << endl;

} // End main()
