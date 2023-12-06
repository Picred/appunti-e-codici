#include <iostream>
#include <fstream>

using namespace std;

void sort(int* vals, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vals[i] < vals[j])
                swap(vals[i], vals[j]);
        }
    }
}

void solve(ifstream &in, ofstream &out, int n, int maxPeso){
    int* vals = new int[n];
    int maxVal = 0;
    int peso = 0;

    for(int i=0; i<n; i++){
        in >> vals[i];
    }

    sort(vals,n);

    for(int i=0; i<n; i++){
        if(peso+1 <= maxPeso){
            peso++;
            maxVal+=vals[i];
        }
    }

    out << maxVal << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, maxPeso;

    for(int i=0; i<100; i++){
        in >> n >> maxPeso;

        solve(in,out,n,maxPeso);
    }
}