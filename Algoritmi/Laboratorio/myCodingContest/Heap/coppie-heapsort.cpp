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

        friend ostream& operator<<(ostream& out, Coppia& c){
            out << "(" << c.first << " " << c.second << ")";
            return out;
        }

        friend bool operator>(Coppia &a, Coppia &b){
        if(a.first > b.first)
            return 1;
        else if(a.first == b.first && a.second > b.second)
            return 1;
        return 0;
    }
};


template<class T>
class MaxHeap{
    private:
        Coppia<T>** heap;
        int heapsize;
        int fycalls;

        int left(int i){
            return i*2;
        }

        int right(int i){
            return (i*2)+1;
        }

        int parent(int i){
            return i/2;
        }

        void heapify(int i){
            if (heapsize >= 1) fycalls++;

            int l = left(i);
            int r = right(i);
            int max = i;

            if(l<=heapsize && *heap[l] > *heap[max])
                max = l;

            if(r<=heapsize && *heap[r] > *heap[max])
                max = r;

            if(max!=i){
                swap(heap[i], heap[max]);
                heapify(max);
            }
        }

    public:
        MaxHeap(Coppia<T>** arr, int dim){
            this->heap=arr;
            heapsize=dim;
            fycalls=0;
        }


        void build(){
            for(int i=heapsize/2; i>0; i--){
                this->heapify(i);
            }
        }

        void print(ofstream &out, int n){
            out << fycalls << " ";
            for(int i=1; i<=n; i++){
                out << *heap[i] << " ";
            }
            out << endl;
        }
        
        void extract(){
            swap(heap[1], heap[heapsize]);
            heapsize--;
            heapify(1);
        }

        void heapsort(int n){
            for(int i=0; i<n; i++)
                this->extract();
        }
};


template<class T> void solve(ifstream& in, ofstream& out, int n){
    Coppia<T>** coppie = new Coppia<T>*[n+1];

    for(int i=1; i<n+1; i++){
        char tmp;
        T first, second;

        in >> tmp >> first >> second >> tmp;
        coppie[i] = new Coppia(first, second);
    }

    MaxHeap<T> heap = MaxHeap<T>(coppie, n);
    heap.build();
    heap.heapsort(n);
    heap.print(out, n);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;

        if(type =="int" || type =="bool")
            solve<int>(in,out,n);
                
        if(type =="double")
            solve<double>(in,out,n);
        
        if(type =="char")
            solve<char>(in,out,n);   
    }
}