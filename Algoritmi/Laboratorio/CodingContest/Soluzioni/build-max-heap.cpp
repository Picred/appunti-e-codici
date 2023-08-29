#include <fstream>
#include <iostream>

using namespace std;

template <class H> class Heap {
    private:
        H *heap;
        int size;

        int parent(int i) { 
            return i / 2; 
        }

        int left(int i) { 
            return i * 2; 
        }

        int right(int i) { 
            return (i * 2) + 1; 
        }

        void swap(int x, int y) {
            H tmp = heap[x];
            heap[x] = heap[y];
            heap[y] = tmp;
        }

        void heapify(int i) {
            int max = i;
            int l = left(i);
            int r = right(i);

            if (l <= size && heap[max] < heap[l])
                max = l;

            if (r <= size && heap[max] < heap[r])
                max = r;

            if (max != i) {
                swap(i, max);
                heapify(max);
            }
        }

    public:
        Heap(H *_heap, int _size) {
            heap = _heap;
            size = _size;
        }

        void build() {
            for (int i = size / 2; i > 0; i--)
            heapify(i);
        }

        void fprint(ofstream &out) {
            for (int i = 1; i <= size; i++)
            out << heap[i] << "\t";
            out << "\n";
        }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
    H *array = new H[n + 1];
    for (int j = 1; j <= n; j++)
        in >> array[j];

    Heap<H> heap = Heap<H>(array, n);
    heap.build();
    heap.fprint(out);
    delete[] array;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i = 0; i < 100; i++) {
        string type;
        in >> type;
        int n;
        in >> n;

        if (type == "int")
            solve<int>(in, out, n);

        else if (type == "bool")
            solve<bool>(in, out, n);

        else if (type == "double")
            solve<double>(in, out, n);

        else if (type == "char")
            solve<char>(in, out, n);
    }
}