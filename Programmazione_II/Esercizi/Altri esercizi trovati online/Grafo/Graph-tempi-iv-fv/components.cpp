#include <iostream>
#include <fstream>
#include "Queue.cpp"
using namespace std;

#define MAXN 200
#define WHITE 0
#define BLACK 1
#define GRAY 2

//rappresentazione del grafo attraverso la matrice di adiacenza
template <class T> class Graph {
private:
    bool **adj; //adj[MAXN][MAXN];
    int n, m, current;
    T** k; // k[i] -> key se i è l'id della chiave key
    int *p; // vettore dei parent
    int *color; // vettore dei colori
    int *d; // vettore delle distanze
    int *iv,*fv; // inizio e fine visita dfs
    int *ts;  //ordinamento topologico
    int *r; // vettore delle radici della foresta DFS r[j]=i se j appartiene all'albero DFS di i
    int ts_pos; // posizione nel topological sort
    int t;
    int bfsSource; // informazione sulla sorgente relativa all'ultima chiamata BFS
    
    int _search(T key) {
        for(int i=0; i<n; i++) {
            if( *k[i] == key ) return i;
        }
        return -1;
    }
    
    void _bfs(int s) {      // O(n^2) (Matrici) - O(n+m) (Liste)
        //inizializzazione dei vettori
        if(bfsSource==s) return;
        //cout << "bfs(" << s << ")" << endl;
        for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            d[i] = -1;
        }
        Queue<int> *q = new Queue<int>(n);
        d[s] = 0;
        color[s] = BLACK;
        q->enqueue(s);
        while(!q->isEmpty()) {       // O(n)
            int* i = q->dequeue();   // ogni nodo viene estratto solo una volta (al più)
            for(int j=0; j<n; j++) {    // O(n)
                if(adj[*i][j]==1 && color[j]==WHITE) {
                    p[j] = *i;
                    color[j] = BLACK;
                    d[j] = d[*i]+1;
                    q->enqueue(j);
                }
            }
        }
        bfsSource = s;
    }
    
    void _printShortestPath(int i, int j) {
        if(i==j) {
            cout << i << " ";
            return;
        }
        _printShortestPath(i, p[j]);
        cout << j << " ";
    }

    void _printShortestPath(int j) {
        if(p[j]==-1) {
            cout << j << " ";
            return;
        }
        _printShortestPath(p[j]);
        cout << j << " ";
    }

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
                    r[i] = r[s];
                    cycle = cycle + _dfsVisit(i);
                }
            }
        fv[s] = t++;
        ts[ts_pos--] = s;
        //cout << "Fine visita nodo " << s << " al tempo " << fv[s] << endl;
        color[s] = BLACK;
        return cycle;
    }
    
public:
    Graph() {
        n = m = 0;
        adj = new bool*[MAXN];
        for(int i=0; i<MAXN; i++)
            adj[i] = new bool[MAXN];
        k = new T*[MAXN];
        for(int i=0; i<MAXN; i++) k[i] = NULL;
        current = 0;
        p = new int[MAXN];
        color = new int[MAXN];
        d = new int[MAXN];
        r = new int[MAXN];
        iv = new int[MAXN];
        fv = new int[MAXN];
        ts = new int[MAXN];
        bfsSource = -1;
    }
    
    Graph<T>& addNode(T key) {
        // inseriamo il nodo all'interno dell'array k
        k[n] = new T(key);
        n++;
        // aggiorniamo la matrice di adiacenza
        for(int i=0; i<n; i++) adj[n][i] = adj[i][n] = 0;
        return *this;
    }

    Graph<T>& cancNode(T key) {
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

    Graph<T>& addEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return *this;
        adj[i][j] = 1;
        // se il grafo fosse non direzionato:
        adj[j][i] = 1;
        m++;
        return *this;
    }

    Graph<T>& cancEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return *this;
        adj[i][j] = 0;
        // se il grafo fosse non direzionato:
        adj[j][i] = 0;
        m--;
        return *this;
    }

    int sizeV() {
        return n;
    }
    
    int sizeE() {
        return m;
    }
    
    int existEdge(T key1, T key2) {
        int i = _search(key1);
        int j = _search(key2);
        if(i<0 || j<0) return 0;
        return adj[i][j];
    }
    
    int findNode(T key) {
        int i = _search(key);
        return i;
    }
    
    void adjSet(T key, ostream& out) {
        int i = _search(key);
        if(i<0) return;
        out << "{ ";
        for(int j=0; j<n; j++) {
            if(adj[i][j]==1)
                out << *k[j] << " ";
        }
        out << "}";
    }
    
    void bfs(T key) {
        int s = _search(key);
        if(s<0) return;
        //inizializzazione dei vettori
        _bfs(s);
    }
    
    int shortestPath(T source, T target) {
        int s = _search(source);
        int t = _search(target);
        if(s<0 || t<0) return -1;
        _bfs(s);
        return d[t];
    }

    void printShortestPath(T source, T target) {
        int sp = shortestPath(source, target);
        if(sp>=0) {
            cout << "(" << sp << ") ";
            int t = _search(target);
            _printShortestPath(t);
            cout << endl;
        }
    }

    void raggiungibili(T key) {
        int s = _search(key);
        cout << "{ ";
        if(s>=0) {
            _bfs(s);
            for(int i=0; i<n; i++)
                if(d[i]>=0) cout << *k[i] << " ";
        }
        cout << "}" << endl;
    }
    
    int dfs(int par=0) { // restituisce 1 se il grafo presenta dei cicli
        //inizializzazione dei vettori
        int ord[n];
        for(int i=0; i<n; i++) ord[i] = ts[i];
        for(int i=0; i<n; i++) {            // O(n)
            p[i] = -1;
            color[i] = WHITE;
            iv[i] = fv[i] = -1;
            r[i] = -1;
        }
        ts_pos = n-1;
        t = 0; // tempo di visita posto a 0
        int cycle = 0;
        for(int i=0; i<n; i++) {
            int s = i;
            if(par==1) s = ord[i];
            if(color[s]==WHITE) {
                r[s] = s;
                cycle = cycle + _dfsVisit(s);
            }
        }
        return cycle;
    }
    
    
    int topologicalSort() {
        if(dfs()) {
            cout <<  "Non esiste un ordinamento topologico del grafo" << endl;
            return 1;
        }
        cout << "< ";
        for(int i=0; i<n; i++)
            cout << ts[i] << " ";
        cout << ">" << endl;
        return 0;
    }

    void inverti() {
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(adj[i][j]!=adj[j][i]) {
                    int tmp = adj[i][j];
                    adj[i][j] = adj[j][i];
                    adj[j][i] = tmp;
                }
            }
        }
    }
/*
     0 1 2 3

 0   0 1 1 0
 1   0 0 0 1
 2   1 0 0 0
 3   0 0 0 0
 */
    
    // restituisce la radice dell'albero DFS che contiene il nodo j
    int root(int j) {
        while(p[j]!=-1)
            j = p[j];
        return j;
    }

    void printCC2(ostream& out) {
        // le radici degli alberi DFS sono i nodi per cui p[i]=-1
        int cc = 0;
        int processed[MAXN] = {0}; // processed[i]=1 se ho già stampato la cc di i
        for(int i=0; i<n; i++) 
        	if(!processed[i]) {
            	cc++;
            	for(int j=i+1; j<n; j++)
                	if(r[j]==r[i])  {
                    	processed[j] = 1;
                	}
        	}
        out << cc << endl;
    }
    
    void printCC(ostream& out) {
        // le radici degli alberi DFS sono i nodi per cui p[i]=-1
        int cc = 0;
        for(int i=0; i<n; i++) if(p[i]==-1) { // analizzo tutte le radice della foresta DFS
            cc++;
            
        }
        
        out << cc <<  endl;
    }
    
    void connectedComponents(ostream& out) {
        // 1. prima DFS utilizzando l'ordine standard per calcolare i tempi di fine visita
        dfs();
        // 2. costruiamo il grafo con gli archi invertiti
        inverti();
        // 3. seconda DFS utilizzando l'ordine suggerito dai tempi di fne visita
        dfs(1); // chiamata con parametro 1
        // 4. restitutire ogni albero DFS come una diversa Componente Connessa
        printCC(out);
        inverti();
        return;
    }
    
    void printRadix(){
    	for(int i=0; i<n-1; i++)
    		if(p[i]==-1) cout << *k[i] << " ";
    }
    
    // iteratore
    void reset() {
        current = 0;
    }
    int hasNext() {
        return current<n;
    }
    T* next() {
        if(!hasNext()) return NULL;
        T* tmp = k[current];
        current++;
        return tmp;
    }

    void printR(){
    	for(int i=0; i<n; i++) cout << r[i] << " ";
    }
};

template <class H> ostream& operator<<(ostream& out, const Graph<H>& g) {
    Graph<H> tmp = g;
    tmp.reset();
    int id = 0;
    while(tmp.hasNext()) {
        H* e = tmp.next();
        out << "(" << id << "," << *e << ") --> ";
        id++;
        tmp.adjSet(*e, out);
        out << endl;
    }
    return out;
}

// 5 4 int 33 34 48 50 72 (33,48) (33,72) (48,50) (50,72) 
//          ^

int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    
    for(int task=0; task<100; task++) {
        int nodi, archi;
        string tipo;
        in >> nodi;
        in >> archi;
        in >> tipo;
        if (tipo == "int") {
            Graph<int>* g = new Graph<int>();
            int keys;
            int source, target;
            char ignore;
            for(int i=0; i<nodi; i++) {
                in >> keys;
                g->addNode(keys);
            } 
            for(int i=0; i<archi; i++) {
                in >> ignore;
                in >> source;
                in >> target;
                in >> ignore;
                g->addEdge(source, target);
            } 
            g->connectedComponents(out);
            g->dfs();        
        }
        if (tipo == "char") {
            Graph<char>* g = new Graph<char>();
            char keys;
            char source, target;
            char ignore;
            for(int i=0; i<nodi; i++) {
                in >> keys;
                g->addNode(keys);
            } 
            for(int i=0; i<archi; i++) {
                in >> ignore;
                in >> source;
                in >> target;
                in >> ignore;
                g->addEdge(source, target);
            }           
            g->connectedComponents(out);
            g->dfs(); 
        }
        if (tipo == "double") {
            Graph<double>* g = new Graph<double>();
            double keys;
            double source, target;
            char ignore;
            for(int i=0; i<nodi; i++) {
                in >> keys;
                g->addNode(keys);
            } 
            for(int i=0; i<archi; i++) {
                in >> ignore;
                in >> source;
                in >> target;
                in >> ignore;
                g->addEdge(source, target);
            }           
            g->connectedComponents(out);
            g->dfs(); 
        }
        if (tipo == "bool") {
            Graph<bool>* g = new Graph<bool>();
            bool keys;
            bool source, target;
            char ignore;
            for(int i=0; i<nodi; i++) {
                in >> keys;
                g->addNode(keys);
            } 
            for(int i=0; i<archi; i++) {
                in >> ignore;
                in >> source;
                in >> target;
                in >> ignore;
                g->addEdge(source, target);
            }
            g->connectedComponents(out);
            g->dfs(); 
        }
    }
    
    in.close();
    out.close();
    
    return 0;
}
/*
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
            Grafo<int> g(N);
            for (int i = 0; i < N; i++) g.addNode(A[i]);

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
            g.connectedComponents(out); 
        }
        else if (type == "char")
        {
            char *A = new char[N];
            for (int i = 0; i < N; i++) in >> A[i];
            
            Grafo<char> g(N);
            for (int i = 0; i < N; i++) g.addNode(A[i]);
            
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

int main() {
    Graph<int> *g = new Graph<int>();
       
    g->addNode(33);
    g->addNode(34);
    g->addNode(48);
    g->addNode(50);
    g->addNode(72);

    g->addEdge(33,48).addEdge(33,72);
    g->addEdge(48,50);
    g->addEdge(50,72);

    //cout << *g << endl;
    g->connectedComponents(cout);
    g->dfs();
    //g->printR();
    //g->printRadix();
}
*/