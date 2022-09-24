#include <iostream>
#include <cstdlib>
#include <sstream> 

/* 
* ARGOMENTI della funzione main()
*
*/

using namespace std;
//int main() - senza argomenti
int main(int argc, char *argv[])
{
  cout << " argc e': " << argc << endl;
  cout << " il nome dell'eseguibile e' " << *argv << endl; 
       // ovvero << argv[0] << endl;
 
   for (int i=1; i<argc; i++)
      cout<<"Argomento #"<<i<<" = " << *(argv+i) << endl;
       // <<argv[i] << endl;

  stringstream ss; 
  int sum = 0; int n; 

    if(argc>1) // esegue la somma degli argomenti
      for(int k=1; k<argc; k++){
	ss << argv[k];
	if(!(ss>>n)){
	  ss.clear(); // due to IO error..
	  ss.str("");
	}

	else {
	  sum+=n;
	  ss.clear(); // due to EOF.. 
	  ss.str("");
	}
      }

    cout << "sum: " << sum << endl; 	

    return 0;
} // End main()
