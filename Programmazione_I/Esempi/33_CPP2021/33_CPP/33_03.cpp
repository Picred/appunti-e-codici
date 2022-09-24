#include <iostream>
#include <cassert>

using namespace std; 

//Essi sono interi 
enum Mese{
  Gennaio, // 0
  Febbraio,  //2 
  Marzo, //.. 
  Aprile, 
  Maggio,
  Giugno, 
  Luglio, 
  Agosto, 
  Settembre, 
  Ottobre, 
  Novembre, 
  Dicembre  // 11
};


/* NB: I nomi definiti  vengono ``esportati'' nello scope
della enum. 

Con la seguente ulteriore dichiarazione, errore del compilatore 
(di ridefinizione dei nomi!)
Name clash! 
*/ 

 //COMPILE-TIME ERROR  
/*enum Mesi_estivi{  
  Giugno, 
  Luglio, 
  Agosto
};
 */
 

string traduci_mese(Mese m){
  string out; 
  switch(m){
    case Gennaio:
      return "Gennaio"; 
      break; 

    case Febbraio:
      out = "Febbraio"; 
      break; 
    //case 3: 
      //...

    case Dicembre:
      out = "Dicembre";
      break; 

    default: 
      out = "undefined";
      break; 
  }

  return out; 
}

int main(){
  Mese m1 = Agosto; // OK 
  //anche 
  m1 = Mese::Agosto; 
  //Mese m1 = Mese::Agosto; 

  //int --> enum
  Mese m2 = static_cast<Mese>(11); // Dicembre
  //m2 = 11; // Dicembre
  cout << "m2=" << traduci_mese(m2) << endl; 
  //Ok, una enum e' un intero..MA non ci sara' alcuna corrispondenza
  // tra il 19 e i nomi definiti..
  Mese m3 = static_cast<Mese>(19); // Undefined! Not within the range
  cout << "m3=" << traduci_mese(m3) << endl; 

  //m3 = 10; // int --> enum NO, compile-time error
  int x = m3;  // enum --> int OK 
  cout << x << endl; 

  //stampa interi..
  cout << "m1=" << m1 << ", m2=" << m2 << ", m3=" << m3 << endl;
  //la dimensione di un intero
  cout << "sizeof(m1)=" << sizeof(m1) << endl;

  cout << traduci_mese(m2) << endl; 
}
