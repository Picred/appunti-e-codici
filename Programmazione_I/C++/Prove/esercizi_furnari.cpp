#include<iostream>
using namespace std;

int main() {
        int s[3][3];
        
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                s[i][j]=i+j;
            }
        }

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                cout << "s[" << i << "][" << j << "]="<< s[i][j] << endl;
            }
        }
}