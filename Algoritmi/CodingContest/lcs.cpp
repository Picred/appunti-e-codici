#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solve(int n, int m, string word1, string word2, ifstream &in, ofstream &out){
    int** c = new int*[n+1];

    for(int i=0; i<n+1; i++)
        c[i] = new int[m+1]{0};
    
    for(int i=0; i<n+1; i++)
        c[0][i] = 0;
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(word1[i-1] == word2[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    out << c[n][m] << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n, m;
    string word1, word2;

    for(int i=0; i<100; i++){
        in >> n >> m >> word1 >> word2;
        solve(n,m,word1,word2,in,out);
    }
}