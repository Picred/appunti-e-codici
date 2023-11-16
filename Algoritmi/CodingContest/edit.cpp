// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

void solve(ifstream& in, ofstream& out, string x, string y, int n, int m){
    int c[n+1][m+1];

    for(int i=0; i<=m; i++)
        c[0][i] = i;
    
    for(int i=0; i<=n; i++)
        c[i][0] = i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int p;
            if (x[i-1] == y[j-1])
                p=0;
            else 
                p=1;
            c[i][j] = min(min(c[i-1][j]+1, c[i][j-1]+1), c[i-1][j-1]+p);
        }
    }
    out << c[n][m] << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n,m;
    string X,Y;

    for(int i=0; i<100; i++){
        in >> n >> m >> X >> Y;
        solve(in,out,X,Y,n,m);
    }
}