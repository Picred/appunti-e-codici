// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

class Coppia{
    private:
        double el1, el2;
    public:
        Coppia(){
            el1=0.0;
            el2=0.0;
        }

        Coppia(double x, double y){
            this->el1 = x;
            this->el2 = y;
        }

        double getFirst(){
            return this->el1;
        }
        
        double getSecond(){
            return this->el2;
        }

        friend ostream& operator<<(ostream& out, Coppia c){
            out << "(" << c.el1 << "," << c.el2 << ")";
            return out;
        }

        void print(){

        }
};

Coppia** counting_sort(Coppia** A, int n){
    //max e min
    double Max = A[0]->getFirst();
    double min = A[0]->getFirst();

    for(int i=1; i<n; i++){
        if(A[i]->getFirst() < min)
            min = A[i]->getFirst();
        
        if(A[i]->getFirst() > Max)
            Max = A[i]->getFirst();
    }

    int k =(Max - min) + 1;
    int* C = new int[k];

    for(int i=0; i<k; i++){
        C[i] = 0;
    }
    
    for(int i=0; i<k; i++){
        int index = floor(A[i]->getFirst() - min);
        C[index]+=1;
        cout << C[i] << " ";
    }

    for(int i=1; i<n; i++){
        C[i]+=C[i-1];
    }

    Coppia** B = new Coppia*[n];

    for(int i=n-1; i>=0; i--){
        int index = floor(A[i]->getFirst() - min);
        B[--C[index]] = A[i];
    }

    return B;

}


void solve(ifstream& in, ofstream& out, int n){
    Coppia** A = new Coppia*[n];

    for(int i=0; i<n; i++){
        double el1, el2;
        char tmp;

        in >> tmp >> el1 >> tmp >> el2 >> tmp;
        A[i] = new Coppia(el1, el2);
    }

    Coppia** B = counting_sort(A, n);

}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;

    for(int i=0; i<3; i++){
        in >> n;
        solve(in,out,n);
    }
}