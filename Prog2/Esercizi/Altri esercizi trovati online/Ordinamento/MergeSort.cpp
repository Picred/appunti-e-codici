#include <iostream>
#include <fstream>
#include <cstdlib> //dare un occhiata se funziona o meno
#include <vector> // da modificare con i vector
using namespace std;

void merge(int *v, int n, int m,int &c){		// Complexity: O(n)
	int b[n];
	int i,j,k;
	i = k = 0;
	j = m;
	while(i<m && j<n){
		if(v[i]<v[j]){
			b[k++] = v[i++];
			c++;
		}
		else b[k++] = v[j++];
	}
	while(i<m) b[k++] = v[i++];
	while(j<n) b[k++] = v[j++];

	for(int i=0; i<n; i++) v[i] = b[i];
}

void mergesort(int *v, int n, int &c){			// Complexity: O(n log n) - O(n log n)
	if(n<=1) return;
	int m = n/2;
	mergesort(v,m,c);
	mergesort(v+m,n-m,c);
	merge(v,n,m,c);

int main(){
	cout << "ciao" << endl;
	int v[4] = {8,10,34,19};
	int counter = 0;
	MergeSort(v,4,counter);
	cout << counter << endl;
}

/*
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;

    while(in >> n){
        int vett[n];
        int counter = 0;
        for(int i = 0; i<n ; i++) in >> vett[i];
        MergeSort(vett, 0, n-1, counter);

        out << counter << endl;
    }
    in.close();
    out.close();

    return 0;
}
*/