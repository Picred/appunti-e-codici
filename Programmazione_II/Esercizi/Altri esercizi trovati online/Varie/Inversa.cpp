#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100 ; task++){
        int N;
        in >> N;
        int S[N*2];
        int c=0;
        int x;
        int y;

        for(int i=0; i<N*2; i++)in >> S[i];

        while(c<N*2) {
            x = rand()%(100-5+1)+5;
            y = rand()%(100-5+1)+5;
            if(x>y) {
                if(x-y==S[c] && x+y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
                else if(x-y==S[c] && x*y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
                else if(x+y==S[c] && x-y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
                else if(x+y==S[c] && x*y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
                else if(x*y==S[c] && x+y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
                else if(x*y==S[c] && x-y==S[c+1]) {
                    out << x << " " << y << " ";
                    c+=2;
                }
            }
        }
    out << endl;
    }

    in.close();
    out.close();

    return 0;

}
