#include <iostream>
#include <fstream>
using namespace std;

class Activity{
    private:
        int s;
        int f;
    public:
        Activity(int _s, int _f): s(_s), f(_f){}

        int getS(){return s;}
        int getF(){return f;}
        int getProfit(){return f - s;}

        friend ostream& operator<<(ostream& os, Activity &x){
            return os << "(" << x.s << " " << x.f << ")";
        }
};

void sort(Activity** acts, int n){
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(acts[i]->getF() > acts[j]->getF())
                swap(acts[i], acts[j]);
            else if(acts[i]->getF() == acts[j]->getF() && acts[i]->getS() < acts[j]->getS())
                swap(acts[i], acts[j]);
}

int latestNonConflict(Activity** acts, int i){
    for(int j = i-1; j >= 0; j--)
        if(acts[j]->getF() <= acts[i]->getS())
            return j;
    return -1;
}

void solve(ifstream& in, ofstream& out, int n){
    Activity** acts = new Activity*[n];

    for(int i = 0; i < n; i++){
        char tmp;
        int s; 
        int f; 
        in >> tmp >> s >> f >> tmp;
        acts[i] = new Activity(s,f);
    }
    sort(acts, n);

    int table[n];
    table[0] = acts[0]->getProfit();

    for(int i = 1; i < n; i++){
        int tmprofit = acts[i]->getProfit();
        int l = latestNonConflict(acts, i);
        if(l != -1)
            tmprofit += table[l];
        if(tmprofit > table[i-1])
            table[i] = tmprofit;
        else
            table[i] = table[i-1];
    }
    out << table[n-1] << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    
    for(int i = 0; i < 100; i++){
        in >> n;
        solve(in, out, n);
    }
}