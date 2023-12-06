#include <iostream>
#include <fstream>

using namespace std;

void countingsort(int *A, int n, ofstream &out){
    int max = A[0];
    int min = A[0];

    for(int i=1; i<n; i++){
        if(A[i] > max)
            max = A[i];
        
        if(A[i] < min)
            min = A[i];
    }

    int k = (max-min)+1;
    int* C = new int[k]{0};

    for(int i=0; i<n; i++)
        C[A[i]-min]++;
    
    for(int i=1; i<k;i++)
        C[i]+=C[i-1];
    
    int* B = new int[n];

    for(int i=n-1; i>=0; i--)
        B[--C[A[i]-min]] = A[i];
    
    for(int i=0; i<k; i++)
        out << C[i] << " ";
    
    for(int i=0; i<n; i++)
        out << B[i] << " ";
    
    out << endl;
}

void solve(ifstream &in, ofstream &out, int n){
    int* vett = new int[n];

    for(int i=0; i<n; i++)
        in >> vett[i];
    
    countingsort(vett,n,out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;

    for(int i=0; i<100; i++){
        in >> n;
        solve(in,out,n);
    }
}