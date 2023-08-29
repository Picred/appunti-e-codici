#include "Graph.cpp"
#include "Heap.cpp"

using namespace std;

template <class T> 
class PairMinHeap : public MinBinaryHeap<T>
{
public:
	PairMinHeap(int size) : MinBinaryHeap<T>(size) {}
	PairMinHeap(T** A, int size) : MinBinaryHeap<T>(A, size) {}
	double compare(T* a, T* b)
	{
		return (double)( ((*b).second) - ( (double) (*a).second) );
	}
	void printKey(int i) const
	{
		cout << (*(this->getPriorityQueue())[i]).first << " " << (*(this->getPriorityQueue())[i]).second << endl;
	}

	int findIndex(int index) //data una chiave, trovo lindice su cui devo fare "l'integramento"(?) nello heap
	{
		for (int i = 1; i <= this->size(); i++){
			if((*(this->getPriorityQueue())[i]).first == index)
			  return i;
		}
		return -1;
	}
};




template <class H, class T> 
int Dijkstra(Graph<H, T>* graph, H keysrc, T*& distances, int*& predecessors){ // *& devo modificare le variabili nella funzione e restituirle aggiornate all'utente 
	int src = graph->findIndex(keysrc); //trovo indice della sorgente
	if (src == -1) //esiste la chiave?
		return 0;
	
	int V = graph->getCurrentNodeNumber(); 
	distances = new T[V];
	predecessors = new int[V];	
	PairMinHeap<pair<int,T>>*q  = new PairMinHeap<pair<int,T>>(V); //inizializzo heap... pair (struttura di cpp) è per le coppie (rivedere qualche lezione fa(2-3) perchè è stato spiegtato)
																//si accede al primo elemento con .first e al secondo con .second
	// Initially distance is for each node // manage the usage of the flag
	for (int i = 0; i < V; i++){ //popolazione heap
		if (i == src)		
			distances[i] = 0;		
		else		
			distances[i] = INT_MAX;

		predecessors[i] = -1; //perchè non conosco gli indici dei predecessori, compresa la sorgente
		q->enqueue(pair<int, T>(i, distances[i]));
	}
	while (q->size()){
		pair<int, T> top = *(q->extractMin());
		if (top.second == INT_MAX) //se trovo un infinito allora mi posso fermare. "top.second" è il secondo elemento della coppia
			break;
		int tmp = top.first; //primo elemento della coppia pair cioè -> indice del vertice appena estratto
		for (int i = 0; i < V; i++){ //looking for neighboors
			if (graph->getGraphIndexMatrix()[tmp][i] == 1){
				T newval = distances[tmp] + graph->getGraphWeightMatrix()[tmp][i]; //la nuova stima
				if (newval < distances[i]){ //il nuovo valore migliora la stima?
					distances[i] = newval; //Eseguo la relax
					predecessors[i] = tmp;
					// i non coincide con l'indice dello heap quindi devo procedere cosi:
					int index = q->findIndex(i); //cosi trovo l'indice corrispondente
					q->decreaseKey(index, pair<int,T>(i,newval)); //ora posso fare la decrease
				}
			}
		}
	}
    
	delete q;

	return 1; //procedura andata a buon fine
}





template <class H, class T> void printDistances(Graph<H, T>* graph, H key, T* distances, int* predecessors)
{
	cout << "Printing Dijkstra distances" << endl;
	if (predecessors == NULL || graph->findIndex(key) < 0)
		return;	
	int src = graph->findIndex(key);
	int V = graph->getCurrentNodeNumber();
	for (int i = 0; i < V; i++)
		if (i != src)
		{
			cout << "Distance from " << key << " to " << *(graph->getKey(i)) << " is ";
			if (distances[i] != INT_MAX)
				cout << distances[i] << endl;
			else
				cout << "INF" << endl;
		}
	cout << "Printing predecessor list" << endl;
	for (int i = 0; i < V; i++)
	{
	  if(i!=src)
		if (predecessors[i] > -1 )
			cout << "The predecessor of " << *(graph->getKey(i)) << " is " << *(graph->getKey(predecessors[i])) << endl;
		else 
			cout<< *(graph->getKey(i)) << " is unreacheable" << endl;		
	}
	return;
}


int main()
{
	Graph<char, int>* g = new Graph<char, int>(5);
	g->addNode('A')->addRootNode('C')->addRootNode('B')->addNode('D')->addNode('E');
	g->addEdge('C', 'B', 4)->addEdge('C', 'A', 19)->addEdge('B', 'A', 1)->addEdge('B', 'D', 2)->addEdge('A', 'D', 9)->addEdge('D', 'E', 3)->addEdge('B', 'E', 8)->addEdge('E', 'C', 1);
	g->print();
	int* distances = NULL;
	int* predecessors = NULL;
	if (Dijkstra(g, 'B', distances, predecessors))
		printDistances(g, 'B', distances, predecessors);
	return 1;
}