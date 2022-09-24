#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std; 

/* 
  Le union permettono di definire una struttura
  dati i cui membri sono allocati a partire dallo 
  stesso indirizzo di memoria. 

  Lo spazio occupato in memoria dalla union equivale allo spazio 
  necessario a mantenere in memoria il tipo piu' 
  grande. 
*/ 

enum Type { 
  number, character
};

union Value{
  int num;
  char c; 
};

/* 
  Il record: tipo  e valore.
*/ 
struct Record {
  Type t;
  Value v;
};

void print_all_records(struct Record arr[], int l){
  for(int i=0; i<l; i++)
    switch(arr[i].t){ //switch sulla enumerazione
      case number: 
	cout << "Number: " << arr[i].v.num << endl; 
	break; 
      case character: 
	cout << "Character: " << arr[i].v.c << endl; 
	break; 
      default:
	cout << "Undefined" << endl; 
    }
}


int main(){

  srand(time(0));

  const int DIM = 10;

  Record *array = new Record[DIM];

  //Quanto occupa una struttura di tipo union? 
  cout << "sizeof(Value): " << sizeof(Value) << ", sizeof(int): " << sizeof(int) << ", sizeof(char): " << sizeof(char) << endl;

  for(int j=0; j<DIM; j++){
    if(rand() % 2 == 0){ // record di tipo char 
      array[j].t = character;
      (array[j].v).c = (char) (rand()%26 + 'a');
    }
    else{ // record di tipo int 
      array[j].t = number;
      (array[j].v).num = (short) (rand()% 100);
    }
  }

  print_all_records(array, DIM);
}
