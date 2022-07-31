#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        int N;
        double Sum = 0.0;
        in >> N;
        double S[N];

        for(int i=0; i<N ; i++){
                in >> S[i];
                Sum += S[i];
        }
        out << Sum << endl;
    }
    in.close();
    out.close();

    return 0;
}
