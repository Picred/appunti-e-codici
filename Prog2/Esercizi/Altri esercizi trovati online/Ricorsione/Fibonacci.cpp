#include <iostream>
#include <fstream>
using namespace std;

unsigned long int fibonacci(int n){
	unsigned long int F[n+1];
	F[1]=F[2]=1;
	for(int i=3; i<n+1; i++){
		F[i]= F[i-1] + F[i-2];
	}
	return F[n];
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;

	while(in >> n){
		out << fibonacci(n) << endl;
	}
	in.close();
	out.close();
}