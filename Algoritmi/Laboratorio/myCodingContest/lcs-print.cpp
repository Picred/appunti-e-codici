// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

int** create_matrix(int n, int m){
    int** c = new int*[n];

    for(int i=0; i<n; i++)
        c[i] = new int[m]{0};

    return c;
}

int lcs(string x, string y, int n, int m){
    int **c = create_matrix(n+1,m+1);
    int i,j;

    for(i=1; i<n+1; i++)
        for(j=1 ; j<m+1; j++)
            if(x[i-1] == y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);

    string slcs = "";
    for(i=n+1; i>1; i--)
        for(j=m+1; j>1; j--)
            if(x[i-1] == y[j-1]){
                slcs += x[i-1] + slcs;
                i--;
                j--;
            }
            else if(c[i-1][j] > c[i][j-1]){
                i--;
            }
            else
                j--;

    int max_seq = c[n][m];
    return max_seq;
}

int main(){
    fstream in("input.txt");
    ofstream out("output.txt");

    int n,m;
    string x,y;

    for(int i=0; i<100; i++){
        in >> n >> m >> x >> y;
        out << lcs(x,y,n,m) << endl;
    }
}