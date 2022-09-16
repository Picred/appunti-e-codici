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
        in >> N;
        int S[N];

        for(int cont=0; cont<N ; cont++){
            in >> S[cont];

            if(S[cont]%2 == 1){
                out << S[cont] << " ";
            }
        }

        out << endl;
    }
    in.close();
    out.close();

    return 0;

}
