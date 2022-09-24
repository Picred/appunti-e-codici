#include <iostream>
#include <cassert>

using namespace std; 

//Essi sono interi, ma attenzione..
enum MeseEstivo{
  Giugno, // 0
  Luglio, // 1
  Agosto //2
};

enum MeseInvernale{
  Dicembre, // 0
  Gennaio, //1
  Febbraio // 2
};

int main(){
  MeseEstivo m1 = Giugno; // estate 

  MeseInvernale m2 = Dicembre; //estate 

  if(m2==Giugno) // ??
    cout << "m2: estate!" << endl; 

  if(m1==MeseInvernale::Dicembre) 
    cout << "m1: inverno!" << endl; 

}
