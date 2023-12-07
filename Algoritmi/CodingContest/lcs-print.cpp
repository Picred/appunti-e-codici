#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    ofstream prints("prints.txt");

    int n,m;
    string w1, w2; // word

    for(int k=0; k<100; k++){
        in >> n >> m >> w1 >> w2;
        // cout << n << " " << m << " " << w1 << " " << w2 << endl;

        int** c = new int*[n+1];

        for(int i = 0; i<=n; i++)
            c[i] = new int[m+1]{0};

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(w1[i-1] == w2[j-1])
                    c[i][j] = c[i-1][j-1]+1;
                else
                    c[i][j] = max(c[i-1][j],c[i][j-1]);
            }
        }

        out << c[n][m] << endl;

        // lcs print
        string slcs = "";

        int i = n; 
        int j = m;

        while(i>0 && j>0){
            if(w1[i-1] == w2[j-1]){
                slcs = w1[i-1] + slcs;
                i--;
                j--;
            }else if(c[i-1][j] > c[i][j-1] )
                i--;
            else
                j--;
        }

        prints << "slcs: " << slcs << endl;
    }
}