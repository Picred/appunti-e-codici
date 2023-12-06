#include <iostream>
#include <fstream>

using namespace std;

template<class T>void solve(ifstream& in, ofstream& out, int n){
    int A[n];

    for(int i=0; i<n; i++){
        T key;
        in >> key;
        if(typeid(T) == typeid(double))
            key*=10; 
        A[i] = key;       
    }

    int max = A[0];
    int min = A[0];

    for(int i=0; i<n; i++){
        if(A[i] < min)
            min = A[i];
        if(A[i] > max)
            max = A[i];
    }

    int k = max-min+1;

    int C[k]={0};

    for(int i=0; i<n; i++){
        C[A[i]-min]++;
    }
    
    for(int i=1; i<k; i++)
        C[i]+=C[i-1];
    
    T B[n];

    for(int i=n-1; i>=0; i--){
        T key = A[i];
        if(typeid(T) == typeid(double))
            key = (double)A[i]/10;
        B[--C[A[i]-min]] = key;
    }

    for(int i=0; i<k; i++)
        out << C[i] << " ";
    
    for(int i=0; i<n; i++)
        out << B[i] << " ";
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if(type == "int" || type == "bool")
            solve<int>(in,out,n);
        if(type == "char")
            solve<char>(in,out,n);
        if(type == "double")
            solve<double>(in,out,n);
    }
}