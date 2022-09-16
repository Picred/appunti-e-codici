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
        int M;
        int P;
        in >> N;
        in >> M;
        in >> P;
        int A[N][M];
        int B[M][P];
        int C[N][P];
        //inizializzo A
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++)
                in >> A[i][j];
        }
        //inizializzo B
        for(int i=0; i<M; i++){
            for(int j=0; j<P; j++)
                in >> B[i][j];
        }
        int risultato = 0;
        //Effettuo il prodotto ciclando righe/colonne/colonne
        for(int i=0; i<N; i++){
            for(int j=0; j<P; j++){
                C[i][j] = 0;
                C[0][1];
                for(int k=0; k<M; k++)
                    C[i][j]+=A[i][k]*B[k][j];
            }
        }
        //stampo matrice C
        for(int i=0; i<N ;i++){
            for(int j=0; j<P; j++)
                out << C[i][j] << " ";
        }
    out << endl;
    }
    in.close();
    out.close();
    return 0;
}
