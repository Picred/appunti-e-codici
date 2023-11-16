// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;
class Activity{
    private:
        int s;
        int f;
    public:
        Activity(int _s, int _f) : s(_s), f(_f){}

        int getS(){
            return s;
        }

        int getF(){
            return f;
        }
};

void sort(Activity** vett, int n){
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(vett[i]->getF() > vett[j]->getF())
                swap(vett[i], vett[j]);
}

void solve(ifstream &in, ofstream &out, int n){
    Activity** acts = new Activity*[n];

    for(int i=0; i<n; i++){
        char tmp;
        int s,f;
        in >> tmp >> s >> f >> tmp;
        acts[i] = new Activity(s,f);
    }

    sort(acts,n);

    int k=0;
    int counter = 1;
    
    for(int i=1; i<n; i++){
        if(acts[i]->getS() >= acts[k]->getF()){
            k = i;
            counter++;
        }
    }

    out << counter << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;

    for(int i=0; i<100; i++){
        in >> n;
        solve(in,out,n);
    }
}