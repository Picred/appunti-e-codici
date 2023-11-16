// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Tripla{
    private:
        T first, second, third;
    public:
        Tripla(T f, T s, T t){
            first = f;
            second = s;
            third = t;
        }

        T getFirst(){return first;}
        T getSecond(){return second;}
        T getThird(){return third;}

        friend bool operator<(Tripla &a, Tripla &b){
            if(a.first < b.first) 
                return 1;
            return 0;
        }

        friend bool operator>(Tripla &a, Tripla &b){
            if(a.first > b.first) 
                return 1;
            return 0;
        }

        void print(ofstream &out){
            out << "(" << first << " " << second << " " << third << ") ";
        }
};

Tripla<double>** counting_sort(Tripla<double>** triple, int n, ofstream &out){
    //find max & min indexs
    // double to int -> el * 10
    Tripla<int>** A = new Tripla<int>*[n+1];

    for(int i=1; i<=n; i++)
        A[i] = new Tripla<int>(triple[i]->getFirst()*10, triple[i]->getSecond()*10, triple[i]->getThird()*10);

    int max = 1;
    int min = 1;
    int k;

    for(int i=2; i<=n; i++){
        if (A[i]->getFirst() < A[min]->getFirst())
            min = i;
        
        if (A[i]->getFirst() > A[max]->getFirst())
            max = i;
    }

    k = A[max]->getFirst() - A[min]->getFirst() + 1;
    min = A[min]->getFirst();
    max = A[max]->getFirst();

    int* C = new int[k+1]{0};

    for(int i=1; i<=n; i++){
        C[A[i]->getFirst()-min+1]++;
    }

    for(int i=1; i<=k; i++){
        C[i]+=C[i-1];
    }

    Tripla<double>** B = new Tripla<double>*[n+1];

    for(int i=n; i>=1; i--){
        B[C[A[i]->getFirst()-min+1]] = new Tripla<double>(double(A[i]->getFirst()/10.0), double(A[i]->getSecond()/10.0), double(A[i]->getThird()/10.0));
        C[A[i]->getFirst()-min+1]--;
    }

    for(int i=1; i<=k; i++){
        out << C[i] << " ";
    }
    return B;
}

void solve(ifstream& in, ofstream& out, int n){
    Tripla<double>** triple = new Tripla<double>*[n+1];

    for(int i=1; i<=n; i++){
        char tmp;
        double first, second, third;

        in >> tmp >> first >> second >> third >> tmp;
        triple[i] = new Tripla(first, second, third);
    }

    Tripla<double>** res = counting_sort(triple, n, out);
    
    for(int i=1; i<=n; i++){
        res[i]->print(out);
    }
    out << endl;
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