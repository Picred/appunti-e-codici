#include<iostream>
using namespace std;

int x = 0;

int** fun() {
    int **v = new int*[3];
    for(int i=0; i<3; i++) {
        v[i] = new int[4];
        for (int j=0; j<4; j++) {
            v[i][j] = 0;
        }
    }

    return v;
}

int main() {
}