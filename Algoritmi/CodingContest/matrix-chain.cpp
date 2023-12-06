#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int matrixchain(int* p, int n){
    int m[n][n];

    for(int i=1; i<n; i++){ //scorro m
        m[i][i] = 0;
    }

    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<j; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int solve(ifstream &in, int n){
    char tmp;
    int dim1, dim2;
    int* p = new int[n+1];

    for(int i=0; i<n; i++){
        in >> tmp >> dim1 >> tmp >> dim2 >> tmp;
        p[i] = dim1;
    }
    p[n] = dim2;

    return matrixchain(p,n+1);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    for(int i=0; i<100; i++){
        in >> n;
        out << solve(in,n) << endl;
    }
}