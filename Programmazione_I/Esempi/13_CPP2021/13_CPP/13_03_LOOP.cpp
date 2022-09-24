#include <iostream>
#include <string>
#include <limits>

using namespace std;

/* 
* LOOP 
* + Controllo errore
* + Controllo EOF 
* + scarta caratteri ``garbage''  
*/ 

//Provare i seguenti input:
//Pippo 
//Pippo pippo2 
// 46.5sss 
//44.8 pippo
//56.8 pippo pippo2 45.6 alalal 43.1 -1 ???
//LOOP 
int main(){

  double x; 
  double s = 0;
  int n=0;
  bool end=false;
  bool eof=false; 

  while(!end){
      cout << "Inserisci un numero in virgola mobile maggiore di zero, oppure -1 per terminare e stampare la media" << endl;
      cin >> x;

      if((eof=cin.eof())){ //if the user simulates EOF, the loop will end
        end=true; //la prossima iterazione non sara' eseguita
        cout << "EOF! Exit from the loop.." << endl;
      }

      else if(cin.fail()){
        cerr << "Input non valido, sara' ignorato.." << endl;
        cin.clear(); //reset all std:iostate flags..
      }

      else if(x==-1)
        end=true;
      else{ 
        s+=x;
        n++;
        cout << "Hai inserito: " << x << endl;
      }

      //ignora/scarta tutti i caratteri inseriti fino al ritorno a capo
      if(!eof)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      else
        eof=false; 
  } //end while 

  cout << "Media: " << (n!=0 ? s/n : 0) << endl;

}
