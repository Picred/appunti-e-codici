#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Selection_Sort(int *v, int n){
	int dist = 0;
	for(int i=0; i<n-1; i++){
		int k = i;
		for(int j=i+1; j<n; j++){
			if(v[j] < v[k]) k = j;
		}
		dist += k-i;
		swap(v[i],v[k]);
	}
	return dist;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;

	while(in >> n){
		int v[n];
		for(int i=0; i<n; i++) in >> v[i];
		out << Selection_Sort(v,n) << endl;
	}
	in.close();
	out.close();

	return 0;
}