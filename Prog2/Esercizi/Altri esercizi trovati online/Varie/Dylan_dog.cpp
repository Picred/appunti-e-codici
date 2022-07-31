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
        int F;
        in >> F;
        int x=0;
        int S[N];

        for(int i=0; i<N; i++) in>>S[i];
        for(int i=0; i<N ; i++){
            if(F==S[i]){
                x= i+1;
                i=N;
            }
        }
       cout << x << endl;
    }

}
