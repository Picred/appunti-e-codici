// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Coppia{
    private:
        T first, second;
    public:
        Coppia(T f, T s){
            first = f;
            second = s;
        }

        T getFirst(){return first;}
        T getSecond(){return second;}

        friend bool operator<(Coppia &a, Coppia &b){
            if(a.first < b.first) 
                return 1;
            return 0;
        }

        friend bool operator>(Coppia &a, Coppia &b){
            if(a.first > b.first) 
                return 1;
            return 0;
        }

        void print(ofstream &out){
            out << "(" << first << " " << second << ") ";
        }
};

Coppia<double>** counting_sort(Coppia<double>** coppie, int n, ofstream &out){
    //find max & min indexs
    // double to int -> el * 10
    Coppia<int>** A = new Coppia<int>*[n+1];

    for(int i=1; i<=n; i++)
        A[i] = new Coppia<int>(coppie[i]->getFirst()*10, coppie[i]->getSecond()*10);

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

    for(int i=1; i<=n; i++)
        C[A[i]->getFirst()-min+1]++;

    for(int i=1; i<=k; i++)
        C[i]+=C[i-1];

    Coppia<double>** B = new Coppia<double>*[n+1];

    for(int i=n; i>=1; i--){
        B[C[A[i]->getFirst()-min+1]] = new Coppia<double>(double(A[i]->getFirst()/10.0), A[i]->getSecond()/10.0);
        C[A[i]->getFirst()-min+1]--;
    }

    for(int i=1; i<=k; i++)
        out << C[i] << " ";

    return B;
}

void solve(ifstream& in, ofstream& out, int n){
    Coppia<double>** coppie = new Coppia<double>*[n+1];

    for(int i=1; i<=n; i++){
        char tmp;
        double first, second;

        in >> tmp >> first >> second >> tmp;
        coppie[i] = new Coppia(first, second);
    }

    Coppia<double>** res = counting_sort(coppie, n, out);
    
    for(int i=1; i<=n; i++)
        res[i]->print(out);

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