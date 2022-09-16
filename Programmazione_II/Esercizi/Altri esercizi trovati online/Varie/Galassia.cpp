#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100 ; task++){
        long long int N;
        in >> N;
        string MAX;
        in >> MAX;
        string A[N];
        string NewString;

        for(int i=0; i<N-1; i++){
            in >> A[i];
            NewString = A[i];
            if(MAX.length() < NewString.length())MAX = NewString;
            if(MAX.length() == NewString.length()){
                for(int c=0; c<MAX.length() ; c++){
                    if(MAX[c] > NewString[c]){c= MAX.length();}
                    if(MAX[c] < NewString[c]){
                            MAX=NewString;
                            c = MAX.length();
                    }
                }
            }
        }

        out << MAX;
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
