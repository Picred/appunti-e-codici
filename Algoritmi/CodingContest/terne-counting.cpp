#include <iostream>
#include <fstream>

using namespace std;

template<class T>class Terna{
public:
    T first, second, third;
    Terna(T f, T s, T t) : first(f), second(s), third(t){}
    friend ostream& operator<<(ostream& out, Terna& t){
        out << "(" << t.first << " " << t.second << " " << t.third << ")";
        return out; 
    }
    friend bool operator<(Terna& t1, Terna& t2){
        if(t1.first < t2.first) return true;
        return false;
    }
};

Terna<double>** counting_sort(Terna<double>** terne, int n, ofstream& out){
    Terna<int>** A = new Terna<int>*[n];

    for(int i=0; i<n; i++)
        A[i] = new Terna<int>(terne[i]->first*10,terne[i]->second*10,terne[i]->third*10);
    
    int min = A[0]->first;
    int max = A[0]->first;

    for(int i=0; i<n; i++){
        if(A[i]->first < min)
            min = A[i]->first;
        if(A[i]->first > max)
            max = A[i]->first;
    }

    int k = max-min+1;
    int C[k] = {0};

    for(int i=0; i<n; i++)
        C[A[i]->first - min]++;
    
    for(int i=1; i<k; i++)
        C[i]+=C[i-1];
    
    Terna<double>** B = new Terna<double>*[n];
    for(int i=n-1; i>=0; i--)
        B[--C[A[i]->first-min]] = new Terna<double>((double)(A[i]->first/10.0),(double)(A[i]->second/10.0),(double)(A[i]->third/10.0));
    
    for(int i=0; i<k; i++)
        out << C[i] << " ";

    return B;
}

template<class T>void solve(ifstream& in, ofstream& out, int n){
    Terna<double>** terne = new Terna<double>*[n];

    for(int i=0; i<n; i++){
        T f, s, t;
        char tmp;
        in >> tmp >> f >> s >> t >> tmp;
        terne[i] = new Terna(f,s,t);
    }

    Terna<double>** B = counting_sort(terne, n, out);

    for(int i=0; i<n; i++)
        out << *B[i] << " ";
    out << endl;        
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    for(int i=0; i<100; i++){
        in >> n;
        solve<double>(in,out,n);
    }
}