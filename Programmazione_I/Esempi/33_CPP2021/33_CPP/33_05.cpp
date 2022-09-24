#include <iostream>
#include <cassert>

using namespace std; 

//Le enum class sono completamente 
//tipizzate e non esportano i valori nello scope 

enum class MeseEstivo{
  Giugno, // 0
  Luglio, // 1
  Agosto //2
};

enum class MeseInvernale{
  Dicembre, // 0
  Gennaio, //1
  Febbraio // 2
};

int main(){
  MeseEstivo m; 
  //m = Giugno; // Compile-time error, Giugno fuori scope! 
  m = MeseEstivo::Giugno; // OK

  m = static_cast<MeseEstivo>(1); // conversione esplicita, come plain enums

  int mese; 

  //le enum class sono ``fortemente tipizzate''..
  //mese = m; // Compile-time error! 

  mese = static_cast<int>(MeseEstivo::Giugno);  // OK 

  //if(m==Dicembre){} // Compile-time error! No Dicembre in questo scope..
    //...

  //Cioe' che in 33_04.cpp generava un warning adesso 
  //genera un errore..
  //if(m==MeseInvernale::Dicembre){} // Compile-time error! Confronto non possibile..


}
