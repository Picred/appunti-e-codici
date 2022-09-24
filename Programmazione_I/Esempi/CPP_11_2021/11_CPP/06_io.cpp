#include <iostream>
#include <string>

using namespace std;

int main(){
  
  string s;
  bool end=false;

  cout << "Please enter some text (`q` to quit): " << endl;

  do{

    cin >> s;

    //check if EOF occurs
    if(cin.eof()){
      cout << "End Of file!"; // try with CTRL-D which means EOF
      cin.clear();
      cin.ignore(); // don't stop the loop, simply ignore
    }
 
    //check if any error occurs 
    else if(cin.fail()){
      cout << "IO error!"; // read-write error
      cin.clear();
      cin.ignore(); // then, stop the loop! 
      end=true;
    }

    else if(s=="q") 
      end=true;
      
    cout << "You entered: " << s << endl;
  }while(end==false);

  cout << "Exit!" << endl;
}
