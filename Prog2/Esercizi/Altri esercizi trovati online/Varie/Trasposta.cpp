#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        int N;
        in >> N;
        int M;
        in >> M;
        int A[N][M];

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) in >> A[i][j];
        }

        for(int j=0; j<M; j++){
            for(int i=0; i<N; i++) out << A[i][j] << " ";
        }
     out << endl;
    }
    in.close();
    out.close();

    return 0;
}
