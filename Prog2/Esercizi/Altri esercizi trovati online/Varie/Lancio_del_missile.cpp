#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double distanza(int x, int y, int x1, int y1);

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        int N;
        in >> N;
        int x,y;
        in >> x;
        in >> y;
        int S[2*N];
        int x1;
        int y1;
        double min;
        int c=0;
        int f=2;

        for(int i=0; i<2*N; i++)in >> S[i];

        x1 = S[0];
        y1 = S[1];
        min = distanza(x, y, x1, y1);


        while(f<2*N) {
            x1 = S[f];
            y1 = S[f+1];
            if(distanza(x, y, x1, y1) < min){
                min = distanza(x, y, x1, y1);
                c = f;
            }
            f+=2;
        }
    out << S[c] << " " << S[c+1];
    out << endl;
    }
    in.close();
    out.close();

    return 0;
}

double distanza(int x, int y, int x1, int y1){
    return sqrt(pow((x-x1),2)+pow((y-y1),2));
}

