#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        int N;
        in >> N;
        string x;
        in >> x;
        string y;

        for(int i=0; i<N; i++){
            in >> y;
            int find = y.find(x);

            if(find>0) out << y << " ";
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
