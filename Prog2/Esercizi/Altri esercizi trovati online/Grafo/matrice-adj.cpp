#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Grafo
{
    bool **adj; // matrice di adiacenza
    int n, m;   //numero nodi e archi
    T **k;      // vettore di puntatori a chiavi
    int current;

    int _search(T key)
    {
        for (int i = 0; i < n; i++)
        {
            if (*k[i] == key)
                return i;
        }
        return -1;
    }

public:
    Grafo(int num_elem)
    {
        adj = new bool *[num_elem];
        for (int i = 0; i < num_elem; i++)
        {
            adj[i] = new bool[num_elem];
        }
        n = 0;
        m = 0;
        k = new T *[num_elem];
        for (int i = 0; i < num_elem; i++)
        {
            k[i] = NULL;
        }
        current = 0;
    }

    Grafo &addNode(T key)
    {
        k[n] = new T(key);
        for (int i = 0; i < n; i++)
        {
            adj[i][n] = adj[n][i] = 0;
        }
        n++;
        return *this;
    }

    Grafo &addEdge(T key1, T key2)
    {
        int indx1 = _search(key1);
        int indx2 = _search(key2);
        if (indx1 == -1 || indx2 == -1)
            return *this;
        adj[indx1][indx2] = 1;
        m++;
        return *this;
    }

    T getKey(int indx)
    {
        return *k[indx];
    }

    int getSize() { return n; }

    int hasEdge(int indx1, int indx2)
    {
        if (adj[indx1][indx2] == 1)
            return 1;
        else
            return 0;
    }

    //iteratore
    void reset()
    {
        current = 0;
    }

    int hasNext()
    {
        return current < n;
    }

    T *next()
    {
        if (!hasNext())
            return NULL;
        T *e = k[current];
        current++;
        return e;
    }
};

template <class T>
ostream &operator<<(ostream &out, const Grafo<T> &g)
{
    Grafo<T> tmp = g;
    tmp.reset();
    int indx = 0, cont_adj = 0;
    int size = tmp.getSize();
    while (tmp.hasNext())
    {
        T *e = tmp.next();
        out << "(" << *e;
        for (int i = 0; i < size; i++)
        {
            if (tmp.hasEdge(indx, i))
                cont_adj++;
        }
        if (cont_adj > 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (tmp.hasEdge(indx, i))
                    out << " " << tmp.getKey(i);
            }
        }
        out << ") ";
        indx++;
    }
    return out;
}

template <class T>
void merge(T *A, int m, int n)
{
    int i = 0, j = m, k = 0;
    T *new_A = new T[n];
    while (i < m and j < n)
    {
        if (A[i] < A[j])
            new_A[k++] = A[i++];
        else
            new_A[k++] = A[j++];
    }

    while (j < n)
        new_A[k++] = A[j++];
    while (i < m)
        new_A[k++] = A[i++];

    for (int i = 0; i < n; i++)
    {
        A[i] = new_A[i];
    }
    delete[] new_A;
}

template <class T>
void merge_sort(T *A, int n)
{
    if (n <= 1)
        return;
    int m = n / 2;
    merge_sort(A, m);
    merge_sort(A + m, n - m);
    merge(A, m, n);
}

int main()
{
    // TEST MANUALE
    int n = 5;
    Grafo<int> g(n);
    int A[]= {33,48,50,72,89};
    merge_sort(A, n);
    g.addNode(A[0]).addNode(A[1]).addNode(A[2]).addNode(A[3]).addNode(A[4]);
    g.addEdge(33, 50).addEdge(33, 72).addEdge(48, 33).addEdge(50, 48).addEdge(50, 72).addEdge(50, 89).addEdge(89, 72);
    cout << g;
    

    /*ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++)
    {
        int N, M;
        in >> N;
        in >> M;
        string type;
        in >> type;

        if (type == "int")
        {
            int *A = new int[N];
            for (int i = 0; i < N; i++)
            {
                in >> A[i];
            }
            merge_sort(A, N);
            Grafo<int> g(N);
            for (int i = 0; i < N; i++)
            {
                g.addNode(A[i]);
            }

            for (int i = 0; i < M; i++)
            {
                char c;
                in >> c;
                int val1, val2;
                in >> val1;
                in >> val2;
                in >> c;
                g.addEdge(val1, val2);
            }
            out << g;
        }
        else if (type == "char")
        {
            char *A = new char[N];
            for (int i = 0; i < N; i++)
            {
                in >> A[i];
            }
            merge_sort(A, N);
            Grafo<char> g(N);
            for (int i = 0; i < N; i++)
            {
                g.addNode(A[i]);
            }

            for (int i = 0; i < M; i++)
            {
                char c;
                in >> c;
                char val1, val2;
                in >> val1;
                in >> val2;
                in >> c;
                g.addEdge(val1, val2);
            }
            out << g;
        }
        else
        {
            double *A = new double[N];
            for (int i = 0; i < N; i++)
            {
                double tmp;
                in >> tmp;
                A[i] = tmp;
            }
            merge_sort(A, N);
            Grafo<double> g(N);
            for (int i = 0; i < N; i++)
            {
                g.addNode(A[i]);
            }

            for (int i = 0; i < M; i++)
            {
                char c;
                in >> c;
                double val1, val2;
                in >> val1;
                in >> val2;
                in >> c;
                g.addEdge(val1, val2);
            }
            out << g;
        }
        out << endl;
    }

    in.close();
    out.close();
    */

    return 0;
}