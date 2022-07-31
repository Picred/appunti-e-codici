#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100 ; task++){
        int N;
        int M;
        in >> N;
        in >> M;
        int A[N][M];
        int B[N][M];
        int C[N][M];
        //Inizializziamo A
        for(int c=0; c<M ; c++){
            for(int i=0; i<N; i++)
                in >> A[i][c];
        }

        for(int c=0; c<M ; c++){
            for(int i=0; i<N ; i++)
                in >> B[i][c];
        }

        for(int c=0; c<M ; c++){
            for(int i=0; i<N ; i++){
                C[i][c]= A[i][c] + B[i][c];
                out << C[i][c] << " ";
            }
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
