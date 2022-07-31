#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Insertion_Sort(int* v, int n){
	int c = 0;
	for(int i=1; i<n; i++){
		int j=i;
		while(j>0 && v[j]<v[j-1]){
			swap(v[j-1],v[j]);
			j--;
			c++;
		}
	}
	return c;
}

int rinsertion(int *v, int n){
	if(n<=1) return;
	int c = 0;
	rinsertion(v,n-1);
	int j = n-2;
	while(j>=0 && v[j]>v[j+1]){
		scambia(v,j,j+1);
		j--;
		c++;
	}
	return c;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	while(in >> n){
		int v[n];
		for(int i=0; i<n; i++) in >> v[i];
		out << Insertion_Sort(v,n) << " ";
		out << rinsertion(v,n) << endl;
	}
	in.close();
	out.close();

	return 0;


}