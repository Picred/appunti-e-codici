#include <iostream>
#include <fstream>

using namespace std;

#define WHITE 0
#define BLACK 1
#define GRAY 2

template <class T>
class Grafo
{
    bool **adj; // matrice di adiacenza
    int n, m;   //numero nodi e archi
    T **k;      // vettore di puntatori a chiavi
    int current;
    T *p; // vettore dei parent
    T *color; // vettore dei colori
    T *iv,*fv; // inizio e fine visita dfs
    T *ts;
    int ts_pos;
    int t;

    int _dfsVisit(int s) {
        iv[s] = t++;
        int cycle = 0;
        color[s] = GRAY;
        //cout << "Inizio visita nodo " << s << " al tempo "<< iv[s]<<endl;
        for(int i=0; i<n; i++)
            if(adj[s][i]==1) {
                if(color[i]==BLACK) {
                    // si tratta di un arco di attraversamento o in avanti
                    //if(iv[s]<fv[i])
                    //    cout << "(" << s << "," << i << ") è un arco in avanti" << endl;
                    //else cout << "(" << s << "," << i << ") è un arco di attraversamento" << endl;
                }
                if(color[i]==GRAY) {
                    // abbiamo trovato un ciclo
                    //cout << "(" << s << "," << i << ") è un arco all'indietro" << endl;
                    cycle += 1;
                }
                if(color[i]==WHITE) {
                    //cout << "(" << s << "," << i << ") è un arco dell'albero" << endl;
                    p[i] = s;
                    cycle = cycle + _dfsVisit(i);
                }
            }
        fv[s] = t++;
        ts[ts_pos--] = s;
        //cout << "Fine visita nodo " << s << " al tempo " << fv[s] << endl;
        color[s] = BLACK;
        return cycle;
    }

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
        p = new T[num_elem];
        color = new T[num_elem];
        iv = new T[num_elem];
        fv = new T[num_elem];
        ts = new T[num_elem];
    }

    Grafo &addNode(T key){
        k[n] = new T(key);
    
        for (int i = 0; i < n; i++)
            adj[i][n] = adj[n][i] = 0;
        n++;
        return *this;
    }

    Grafo<T>& cancNode(T key) {
        int i = _search(key);
        if(i<0) return *this;
        // sistemo l'array k
        k[i] = k[n-1];
        // sistemo la matrice adj
        for(int j=0; j<n; j++) {
            adj[i][j] = adj[n-1][j];
            adj[j][i] = adj[j][n-1];
        }
        n--;
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

    Grafo<T>& cancEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return *this;
        adj[i][j] = 0;
        // se il grafo fosse non direzionato:
        // adj[j][i] = 0;
        m--;
        return *this;
    }

    int dfs() { // restituisce 1 se il grafo presenta dei cicli
        //inizializzazione dei vettori
        for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            iv[i] = fv[i] = -1;
        }
        ts_pos = n-1;
        t = 0; // tempo di visita posto a 0
        int cycle = 0;
        for(int s=0; s<n; s++)
            if(color[s]==WHITE) cycle = cycle + _dfsVisit(s);
        return cycle;
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

//5 7 int 33 48 50 72 89 (33,50) (33,72) (48,33) (50,48) (50,72) (50,89) (89,72)
//                         ^

int main()
{  
    ifstream in("input.txt");
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
                in >> A[i];
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
            int cycle = g.dfs();
            out << cycle;
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
            int cycle = g.dfs();
            out << cycle;
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
            int cycle = g.dfs();
            out << cycle;
        }
        out << endl;
    }

    in.close();
    out.close();

    return 0;
}