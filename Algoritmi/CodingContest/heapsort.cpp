#include <iostream>
#include <fstream>

using namespace std;

template<class T>class MaxHeap{
    private:
        T* heap;
        int heapsize, maxsize, fycalls;

        int left(int i){
            return 2*i;
        }

        int right(int i){
            return (2*i)+1;
        }

        int parent(int i){
            return i/2;
        }

        void heapify(int i){
            fycalls++;
            int l = left(i);
            int r = right(i);
            int max = i;

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
        MaxHeap(T* vett, int size) : heapsize(size-1), maxsize(size), fycalls(0){
            this->heap = vett;
        }

        void build(){
            for(int i=heapsize/2; i>0; i--)
                heapify(i);
        }

        void insert(T key){
            heap[++heapsize] = key;
            int i = heapsize;

            while(i>1 && heap[i] > heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void extract(){
            swap(heap[1], heap[heapsize--]);
            heapify(1);
        }

        void heapsort(){
            while(heapsize > 1)
                extract();
        }

        void print(ofstream &out){
            out << fycalls << " ";
            for(int i=1; i<maxsize; i++)
                out << heap[i] << " ";
            out << endl;
        }
};

template<class T>void solve(ifstream &in, ofstream &out, int n){
    T* vett = new T[n+1];
    T key;
    for(int i=1; i<=n; i++){
        in >> key;
        vett[i] = key;
    }
    MaxHeap<T> heap = MaxHeap<T>(vett,n+1);
    heap.build();    
    heap.heapsort();
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if(type == "int")
            solve<int>(in,out,n);
        if(type == "char")
            solve<char>(in,out,n);
        if(type == "bool")
            solve<bool>(in,out,n);
        if(type == "double")
            solve<double>(in,out,n);
    }
}