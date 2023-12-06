#include <iostream>
#include <fstream>

using namespace std;

template<class T> class Terna{
    public:
        T first, second, third;
        Terna(T f, T s, T t) : first(f), second(s), third(t) {}
        
        friend bool operator>(Terna &a, Terna &b){
            if(a.first > b.first) 
                return true;
            if(a.first == b.first && a.second > b.second) 
                return true;
            if(a.first == b.first && a.second == b.second && a.third > b.third) 
                return true;
            return false;
        }
};

template<class T> class MaxHeap{
    private:
        Terna<T>** heap;
        int heapsize, fycalls;

        int left(int i){ return i*2;}
        int right(int i){ return (i*2)+1;}
        int parent(int i){ return i/2;}

        void heapify(int i){
            heapsize > 0 ? fycalls ++ : fycalls += 0;
            int l = left(i);
            int r = right(i);
            int max = i;

            if(l <= heapsize && *heap[l] > *heap[max])
                max = l;
            if(r <= heapsize && *heap[r] > *heap[max])
                max = r;
            if(max != i){
                swap(heap[i], heap[max]);
                heapify(max);
            }
        }
    public:
        MaxHeap(int hsize, Terna<T>** vett){
            heap = vett;
            fycalls = 0;
            heapsize = hsize;
        }

        void build(){
            for(int i=heapsize/2; i>0; i--)
                heapify(i);
        }

        void heapsort(int size){
            for(int i=0; i<size; i++)
                extract();
        }

        void extract(){
            swap(heap[1], heap[heapsize]);
            heapsize--;
            heapify(1);
        }

        void print(ofstream &out, int size){
            out << fycalls << " ";
            for(int i=1; i<=size; i++)
                out << "(" << heap[i]->first << " " << heap[i]->second << " " << heap[i]->third << ") ";
            out << endl;
        }
};

template<class T> void solve(ifstream &in, ofstream &out, int n){
    Terna<T>** vett = new Terna<T>*[n+1];

    T f, s, t;
    char tmp;

    for(int i=1; i<=n; i++){
        in >> tmp >> f >> s >> t >> tmp;
        vett[i] = new Terna<T>(f,s,t);
    }

    MaxHeap<T> heap = MaxHeap(n, vett);
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
        if(type == "int" || type == "bool")
            solve<int>(in,out,n);
        if(type == "char")
            solve<char>(in,out,n);
        if(type == "double")
            solve<double>(in,out,n);
    }
}