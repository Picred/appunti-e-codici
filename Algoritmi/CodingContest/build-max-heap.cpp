#include <iostream>
#include <fstream>

using namespace std;

template<class T> class MaxHeap{
    private:
        T* heap;
        int heapsize;

        int left(int i) { return 2*i;}
        int right(int i) { return (2*i)+1;}
        int parent(int i) { return i/2;}

        void heapify(int i){
            int max = i;
            int r = right(i);
            int l = left(i);

            if(l <= heapsize && heap[l] > heap[max])
                max = l;
            if(r <= heapsize && heap[r] > heap[max])
                max = r;
            
            if(max!=i){
                swap(heap[max], heap[i]);
                heapify(max);
            }
        }

    public:
        MaxHeap(int hsize, T* vett){
            heap = new T[hsize];
            heapsize = hsize;
            heap = vett;
        }

        void build(){
            for(int i = heapsize/2; i>0; i--)
                heapify(i);
        }

        void print(ofstream& out){
            for(int i = 1; i<=heapsize; i++)
                out << heap[i] << " ";
            out << endl;
        }
};

template<class T>void solve(ifstream &in, ofstream& out, int n){
    T* vett = new T[n+1];

    for(int i=1; i<=n; i++)
        in >> vett[i];

    MaxHeap<T> heap = MaxHeap(n, vett);
    heap.build();
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if(type == "bool" || type == "int")
            solve<int>(in,out,n);
        if(type == "char")
            solve<char>(in,out,n);
        if(type == "double")
            solve<double>(in,out,n);
    }
}