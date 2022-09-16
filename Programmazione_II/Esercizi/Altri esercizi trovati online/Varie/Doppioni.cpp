#include <iostream>
#include <fstream>
using namespace std;

void scambia(int v[], int i, int j){
	int tmp = v[j];
	v[j] = v[i];
	v[i] = tmp;
}

void insertion(int v[], int n){
	for(int i=1; i<n; i++){
		int j = i;
		while(j>0 && v[j] < v[j-1]){
			scambia(v,j,j-1);
			j--;
		}
	}
}

int contaDoppioni(int v[], int n){
	int c = 0;
	int i = 0;
	while(i<n-1){
		int j = i+1;
		while(v[j] == v[i]){
			c++;
			j++;
		}
		i = j;
	}
	return c;
}

void stampa(int v[], int n){
	for(int i=0; i<n; i++) cout << v[i] << " ";
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	while(in >> n){
		int v[n];
		
		for(int i=0; i<n; i++) in >> v[i];

		insertion(v,n);
		out << contaDoppioni(v,n);
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}