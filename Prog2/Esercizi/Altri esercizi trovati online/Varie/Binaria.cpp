#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output");

    for(int task=0; task<100; task++){
        int n;
        in >> n;
        int x;
        for(int i=0; i<n; i++){
            in >> x;
            bitset<8> obj_x(x); // inizializzo l'oggetto con i bit values;
            out << obj_x <<" ";
        }
    out << endl;
    }
    return 0;
}
