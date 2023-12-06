#include <iostream>
#include <fstream>

using namespace std;


int min(int a, int b, int c){
    int min = a;
    if(b<min) min=b;
    if(c<min) min=c;
    return min;
}

void solve(int n, int m, string w1, string w2, ifstream&in, ofstream& out){
    int M[n+1][m+1];

    for(int i=0; i<=n; i++)
        M[i][0] = i;

    for(int i=0; i<=m; i++)
        M[0][i] = i;

    int p;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(w1[i-1] == w2[j-1])
                p = 0;
            else
                p = 1;
            M[i][j] = min(M[i-1][j]+1, M[i][j-1]+1, M[i-1][j-1]+p);
        }
    }

    out << M[n][m] << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n,m;
    string w1, w2;

    for(int i=0; i<100; i++){
        in >> n >> m >> w1 >> w2;
        solve(n,m,w1,w2,in,out);
    }
}