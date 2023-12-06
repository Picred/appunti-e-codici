#include <iostream>
#include <fstream>

using namespace std;


class Activity{
    private:
        int s;
        int f;
    public:
        Activity(int _s, int _f) : s(_s), f(_f){}
    
        int getS(){return s;}
        
        int getF(){return f;}        
};

void actSort(Activity** acts, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(acts[i]->getF() >= acts[j]->getF())
                swap(acts[i], acts[j]);
        }   
    }
}

void solve(int n, ifstream &in, ofstream&out){
    char tmp;
    Activity** acts = new Activity*[n];

    for(int i=0; i<n; i++){
        int s;
        int f;
        in >> tmp >> s >> f >> tmp;
        acts[i] = new Activity(s,f);
    }

    actSort(acts,n);

    int lastSelected=0;
    int counter = 1;
    
    for(int i=1; i<n; i++){
        if(acts[i]->getS() >= acts[lastSelected]->getF()){
            lastSelected = i;
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
        solve(n,in,out);
    }
}