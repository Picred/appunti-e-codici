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
        int x;
        int y;
        char c;
        int risultato;

        for(int i=0; i<N ; i++){
            in >> x;
            in >> c;
            in >> y;
            if(c == '+') out << x + y << " ";
            if(c == '-') out << x - y << " ";
            if(c == '*') out << x * y << " ";
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
