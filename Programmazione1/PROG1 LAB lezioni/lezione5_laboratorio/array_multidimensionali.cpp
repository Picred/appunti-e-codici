#include<iostream>
#include<iomanip>
using namespace std;

#define N 2
#define M 2
#define P 3

void fun1(int x[][2]) {
    for(int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << setw(5) << x[i][j];
        }
        cout << endl;
    }
}

void fun2(int x[2][2]) {
    for(int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            cout << setw(5) << x[i][j];
        }
        cout << endl;
    }
}

void fun3(int x[N][M]) {
    for(int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << setw(5) << x[i][j];
        }
        cout << endl;
    }
}

void fun4(int x[N][M][P]) {
    for(int i=0; i<N; i++) {
        cout << "i="<<i<<":"<<endl;
        for (int j=0; j<M; j++) {
            for (int k=0;k<P; k++) {
                cout << setw(5) << x[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

void fun5(int x[][M][P]) {
    for(int i=0; i<N; i++) {
        cout << "i="<<i<<":"<<endl;
        for (int j=0; j<M; j++) {
            for (int k=0;k<P; k++) {
                cout << setw(5) << x[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int x[][2] = {1,2,3,4};
    fun1(x);
    cout << endl;
    fun2(x);
    cout << endl;
    fun3(x);
    cout << endl;

    int y[N][M][P] = {1,2,3,4,5,6,7,8,9,10,11,12};

    fun4(y);
    cout << endl;
    fun5(y);
}