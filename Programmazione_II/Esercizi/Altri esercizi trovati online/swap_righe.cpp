#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int task=0; task<100; task++){
        int n;
        in >> n;
        int m; 
        in >> m;
        int matrix[n][m];
        int Sum[n] = {0};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                in >> matrix[i][j];
            }
        }

        for(int rows = 0; rows < n; rows++)
            for(int columns = 0; columns < m; columns++)
                Sum[rows] += matrix[rows][columns];

        int c = 0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1; j++){
                if(Sum[j]>Sum[j+1]){
                    int tmp = Sum[j+1];
                    Sum[j+1] = Sum[j];
                    Sum[j] = tmp;
                    c++;
                }
            }
        }

        out << c << endl;
    }
    in.close();
    out.close();

    return 0;

}

    




