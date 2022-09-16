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
        string S[N];

        for(int i=0; i<N; i++)in >> S[i];

        for(int i=0; i<N; i++){
            string y = S[i];
            int cont = 0;
            if(x.length()>y.length()) i=N;
            for(int c=0; c<y.length(); c++){
                if(x[cont]==y[c])
                    cont++;
            }
            if(x.length()==cont) out << S[i] << " ";
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
