// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int matrixChain(int* p, int n){
    int m[n][n];

    for(int i=1; i<n; i++){
        m[i][i] = 0;
    }

    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j = i+l-1;

            m[i][j] = INT_MAX;

            for(int k=i; k<j; k++){
                int q;
                q = (m[i][k] + m[k+1][j]) + (p[i-1] * p[k] * p[j]);
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n-1];
}

void solve(ifstream& in, ofstream& out, int n){
    int* p = new int[n+1];
    int dim1, dim2;
    
    for(int i=0; i<n; i++){
        char tmp;
        in >> tmp >> dim1 >> tmp >> dim2 >> tmp;
        p[i] = dim1;
    }
    p[n] = dim2;

    out << matrixChain(p, n+1) << endl;
}

int main(int argc, char const *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int i=0; i<100; i++){
        int n; in >> n;
        solve(in, out, n);
    }
}
