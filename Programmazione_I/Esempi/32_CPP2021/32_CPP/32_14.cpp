#include <iostream>

using namespace std; 

//FIBONACCI 

long fibo(int n){
  cout << "fibo(" << n << ")" << endl; 
  if(n<=1)
    return 1;
  return fibo(n-1) + fibo(n-2); 
}

int main(int argc, char *argv[]){
  if(argc<2){
    cerr << "No argument!" << endl; 
    return -1; 
  }

  fibo(atoi(argv[1])); 
}
