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

        friend ostream& operator<<(ostream& out, Tripla& t){
            out << "(" << t.first << " " << t.second << " " << t.third << ")";
            return out;
        }
        
        friend bool operator>(Tripla &a, Tripla &b){
        if(a.first > b.first)
            return 1;
        else if(a.first == b.first && a.second > b.second)
            return 1;
        else if(a.first == b.first && a.second == b.second && a.third > b.third)
            return 1;
        return 0;
    }
};


template<class T>
class MaxHeap{
    private:
        Tripla<T>** heap;
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
        MaxHeap(Tripla<T>** arr, int dim){
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
    Tripla<T>** coppie = new Tripla<T>*[n+1];

    for(int i=1; i<n+1; i++){
        char tmp;
        T first, second, third;

        in >> tmp >> first >> second >> third >> tmp;
        coppie[i] = new Tripla(first, second, third);
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