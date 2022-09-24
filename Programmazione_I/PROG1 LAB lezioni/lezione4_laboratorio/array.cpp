#include<iostream>

using namespace std;

int main() {
    int x[5] = {1,2,3,4,5};
    cout << x[0] << endl;

    int y[5] = {};
    cout << y[0] << endl;

    int z[5] = {1,2};
    cout << z[0] << " - " << z[2] << endl;

    int w[5];
    w[0] = 5;
    w[1] = 7;
    w[2] = 0;
    w[3] = 8;
    w[4] = -2;

    for(int i = 0; i<5; i++)
        cout << w[i] << " - ";
    
    cout << endl;

    int h[5];

    for(int i=0; i<5; i++)
        h[i] = i*i;

    for(int i = 0; i<5; i++)
        cout << h[i] << " - ";

    cout << endl;

    cout << "Numero di byte: " << sizeof(h) << endl;
    cout << "Numero di elementi: " << sizeof(h)/sizeof(int) << endl;

    int X[2][3];

    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)
            X[i][j] = i+j;

    cout << X[0][2] << endl;

    int Y[2][2] = {1,2,3,4};

    for(int i=0; i<2;i++){
        for (int j=0; j<2; j++) {
            cout << Y[i][j] << " ";
        }
        cout << endl;
    }

    int Z[2][3][5];

    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)    
            for(int k=0; k<5; k++)
                Z[i][j][k] = i+j+k;

    for(int i=0; i<2; i++)
        for(int j=0; j<3; j++)    
            for(int k=0; k<5; k++)
                cout << "Z["<<i<<"]["<<j<<"]["<<k<<"]="<<Z[i][j][k]<<endl;

    float q[2] = {2.3, 5.4};

    char s[255] = {'H','e','l','l','o',' ','w','o','r','l','d','\0'};
    cout << s << endl;

    int xx[] = {1,2,3};
    cout << xx[1] << endl;

    int yy[][3] = {1,2,3,4,5,6};
    //1 2 3 
    //4 5 6

    cout << yy[1][2] << endl;

    int zz[][1][3] = {1,2,3,4,5,6,7,8,9}; // 3 x 1 x 3
    // 1, 2 ,3 -> [1][3] 
    // 4, 5, 6 -> [1][3]
    // 7, 8, 9 -> [1][3]

    cout << zz[1][0][1] << endl;
}