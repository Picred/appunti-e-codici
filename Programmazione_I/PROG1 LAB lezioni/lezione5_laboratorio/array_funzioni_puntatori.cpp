#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

void print(int **x, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << setw(5) << x[i][j];
        }
        cout << endl;
    }
}

void print_strmat(string ***S, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cout << setw(5) << *S[i][j];
        }
        cout << endl;
    }
}

void print3(int ***x, int M, int N, int P) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<P; k++) {
                cout << "x["<<i<<"]["<<j<<"]["<<k<<"] = "<<x[i][j][k] << endl;
            }
        }
    }
}

void print3_ptr(int **** x, int M, int N, int P) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<P; k++) {
                cout << "x["<<i<<"]["<<j<<"]["<<k<<"] = "<<*x[i][j][k] << endl;
            }
        }
    }
}

int*** get_array(int M, int N, int P) {
    int c = 1;
    int ***x = new int**[M];
    for(int i=0; i<M; i++) {
        x[i] = new int*[N];
        for (int j=0; j<N; j++) {
            x[i][j] = new int[P];
            for (int k=0; k<P; k++) {
                x[i][j][k] = c++;
            }
        }
    }
    return x;
}

void print1(const int *x, int n) {
    for(int i=0; i<n; i++) {
        cout << x[i] << " - ";
    }
    cout << endl;
}

int main() {
    int **x = new int*[2];
    int c = 1;
    for(int i=0; i<2; i++) {
        x[i] = new int[2]{c++,c++};
    }

    print(x, 2, 2);
    delete[] x;

    x=nullptr;

    if(x)
        x[0][0]=2;

    int **y = new int*[7];
    c = 1;
    for(int i=0; i<7; i++) {
        y[i] = new int[5];
        for (int j=0; j<5; j++) {
            y[i][j]=c++;
        }
    }
    

    cout << endl;

    print(y, 7, 5);

    delete[] y;

    cout << endl;

    //int z[2][2] = {1,2,3,4}; // ERRORE!
    //print(z, 2, 2);

    //matrice di puntatori a stringa
    string ***S = new string**[2];
    for (int i=0; i<2; i++) {
        S[i] = new string*[2];
        for (int j=0; j<2; j++) {
            S[i][j] = new string("abc");
        }
    }

    print_strmat(S, 2, 2);

    delete[] S;

    c=1;
    int ***z = new int**[2];
    for(int i=0; i<2; i++) {
        z[i] = new int*[2];
        for (int j=0; j<2; j++) {
            z[i][j] = new int[2];
            for (int k=0; k<2; k++) {
                z[i][j][k] = c++;
            }
        }
    }

    print3(z, 2, 2, 2);

    delete[] z;

    int ***q = get_array(3,5,7);
    print3(q, 3, 5, 7);
    delete[] q;

    int xx[] = {1,2,3};
    print1(xx, 3);
    print1(xx, 3);
}