// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void solve(ifstream& in, ofstream& out, int n, int totResto){
    int* tagli = new int[n];
    for(int i=0; i<n; i++)
        in >> tagli[i];
    int* table = new int[totResto+1];
    for(int i = 1; i < totResto+1; i++)
        table[i] = INT_MAX;
    table[0] = 0;
    for(int i=1; i<totResto+1; i++)
        for(int j=0; j<n; j++)
            if(tagli[j] <= i){
                int tmp_res = table[i - tagli[j]];
                if(tmp_res != INT_MAX && tmp_res + 1 < table[i])
                    table[i] = tmp_res + 1;
            }
    out << table[totResto] << endl;
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int totResto, n;

    for(int i=0; i<100; i++){
        in >> totResto >> n;
        solve(in,out,n,totResto);
    }
}