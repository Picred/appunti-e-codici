#include <string>
#include <iostream>

using namespace std; 

int main(){
  
    string S1 = "123456789"; 

    //const, punta all'area di memoria ``interna'' dello oggetto string
    const char *ptr = S1.c_str();

    cout << ptr << endl; //0123456789
    S1[3]='t'; 
    cout << ptr << endl; //123t567890

    const char *data = S1.data();  //const..
    cout << data << endl; 
    S1[5]='X'; 

    cout << data << endl; 

    S1.append("aabbcc"); //letterale stringa, oggetto string, etc
    cout << S1 << endl; 


    S1.push_back('Z'); //push_back opera sul singolo carattere 
    cout << S1 << endl; 

    S1.assign("0123456789"); //rimpiazza il contenuto della stringa con il suo argomento
    cout << S1 << endl; 

    S1.clear();
    cout << "S1: " << S1 << endl; 

    S1 = "0123456789";

    char *sc = new char[20]; 
    S1.copy(sc, S1.length()/2);

    cout << "S1: " << S1 << ", sc: " << sc << endl;

    S1.erase(2, 5);
    cout << "S1: " << S1 << endl; 

    S1.insert(3, "AtestA");
    cout << S1 << endl; 


    S1.replace(3, 2, "B1B1B1"); 
    cout << S1 << endl; 

}
