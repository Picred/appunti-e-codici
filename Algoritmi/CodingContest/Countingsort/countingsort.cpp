// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

void counting_sort(int* A, int n, ofstream& out){
    int max = A[0];
    int min = A[0];
    
    // find max/min
    for(int i=1; i<n; i++){
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }

    int K = (max-min)+1;
    int* C = new int[K]{0};

    for(int i=0; i<n; i++)
        C[A[i]-min]++;

    for(int i=1; i<K; i++)
        C[i]+= C[i-1];

    int* B = new int[n]{0};

    for(int i=n-1; i>=0; i--)
        B[--C[A[i]-min]] = A[i];

    for(int i=0; i<K; i++)
        out << C[i] << " ";

    for(int i=0; i<n; i++)
        out << B[i] << " ";
    
    out << endl;
}

int main(int argc, char const *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;

    for(int i=0; i<100; i++){
        in >> n;
        int* vett = new int[n]{};

        for(int i=0; i<n; i++)
            in >> vett[i]; 
        
        counting_sort(vett, n, out);
    }

    return 0;
}
