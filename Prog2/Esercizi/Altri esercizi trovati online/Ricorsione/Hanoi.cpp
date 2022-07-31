#include <iostream>
#include <fstream>
using namespace std;

void HANOI(int N, int &M, int sorgente, int appoggio, int destinazione, int &S, int &D){

    if(N==1){
        if(M==1) { S=sorgente; D=destinazione; }
            M--;
            return;
        }
        HANOI(N-1, M, sorgente, destinazione, appoggio, S, D);
        HANOI(1, M, sorgente, appoggio, destinazione, S, D);
        HANOI(N-1, M, appoggio, sorgente, destinazione, S, D);
}

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

        int S = 0;
        int D = 0;

        HANOI(N,M,1,2,3,S,D);

        out << S << " " << D << endl;
    }
    in.close();
    out.close();

    return 0;
}
