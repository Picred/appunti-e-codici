#include <iostream>
#include <fstream>
using namespace std;

int dicotomic(int *v, int n, int key){
	if(n==0) return 0;
	int m = n/2;
	if(v[m]==key) return 0;
	if(key < v[m])
		return dicotomic(v,m,key)+1;
	else 
		return dicotomic(v+m+1,n-m-1,key)+1;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int dim;
	while(in >> dim){
		int v[dim];
		int key;

		for(int i=0; i<dim; i++) in >> v[i];
		in >> key;
		cout << dicotomic(v,dim,key);

		cout << endl;
	}
	in.close();
	out.close();
	return 0;
}