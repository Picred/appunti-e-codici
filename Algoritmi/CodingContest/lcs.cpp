// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

void solve(ifstream& in, ofstream &out, int n, int m, string x, string y){
    int** c = new int*[n+1];

    for(int i=0; i<=n; i++){
        c[i] = new int[m+1]{0};
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1]+1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
    
    out << c[n][m] << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    string x, y;

    for(int i=0; i<100; i++){
        in >> n >> m >> x >> y;
        solve(in,out,n,m,x,y);
    }
}