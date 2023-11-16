#include "GraphBase/Graph.cpp"

template <class H, class T> 
int BellmanFord(Graph<H, T>* graph, H keysrc, T*& distances, int*& predecessors){
	int V = graph->getCurrentNodeNumber();
	distances = new T[V];
	predecessors = new int[V];
	int src = graph->findIndex(keysrc);
	// Initially distance is for each node // manage the usage of the flag
	
	for (int i = 0; i < V; i++){ //inizializzazione dei vettori
		distances[i] = INT_MAX;
		predecessors[i] = -1;
	}
	distances[src] = 0;	 //distanza sorgente 0
	// Relax all edges | V | -1 times
	int stop = 1; //if distances and predecessors cannot be update after a cycle of relax calls, the procudere could be stopped
	for (int s = 0; s < V - 1 && stop; s++){		
		stop = 0; // verifico se finisco di aggiornare oppure no
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++){
				if (graph->getGraphIndexMatrix()[i][j] == 1 && distances[i] != INT_MAX){ //vedo se l'arco esiste. verifico che sia diverso da int_max per evitare overflow (diventa negativo)
					//posso fare la relax
					T weight = graph->getGraphWeightMatrix()[i][j];
					if (distances[i] + weight < distances[j]){
						distances[j] = distances[i] + weight;
						predecessors[j] = i;
						stop = 1; //se aggiorno, cambio la variabile
						//cout << j << " " << i << endl;
					}	
					
				}
			}
	}
	//Check for negative-weight cycles
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			if (distances[i] != INT_MAX && graph->getGraphIndexMatrix()[i][j] == 1)
			{
				T weight = graph->getGraphWeightMatrix()[i][j];
				if (distances[i] + weight < distances[j])
					return 0;
			}
		}
	return 1;
}



template <class H, class T> 
void printDistances(Graph<H,T>* graph,  H key, T* distances, int* predecessors){
	cout << "Printing Bellman-Ford distances" << endl;
	if (graph->findIndex(key) < 0)
		return;
	if (predecessors == NULL || distances == NULL)
	{
		cout << "Graph contains negative weight cycles" << endl;
		return;
	}	
	int src = graph->findIndex(key);
	for (int i = 0; i < graph->getCurrentNodeNumber(); i++)
		if (i != src)
	       cout << "Distance from " << key << " to " << *(graph->getKey(i)) << " is " << distances[i] << endl;

	cout << "Printing predecessor list" << endl;
	for (int i = 0; i < graph->getCurrentNodeNumber(); i++)
	{
	 if (i != src)
		if (predecessors[i] > -1)
			cout << "The predecessor of " << *(graph->getKey(i)) << " is " << *(graph->getKey(predecessors[i])) << endl;
		else
			cout << *(graph->getKey(i)) << " is unreacheable" << endl;
		//cout << *(graph->getKey(predecessors[i])) << "-->" << endl;
	}
	return;
}


int main()
{
	Graph<char, int>* g = new Graph<char, int>(5);
	g->addNode('A')->addRootNode('C')->addRootNode('B')->addNode('D')->addNode('E');
	g->addEdge('C', 'B', 4)->addEdge('C', 'A', 1)->addEdge('C', 'C', 0)->addEdge('B', 'D', 2)->addEdge('A', 'D', -19)->addEdge('D','E', 3)->addEdge('B', 'E', -80);
	// g->addEdge('D', 'C', -3); //this line add a negative cicle
	g->print();
	int* distances = NULL;
	int* predecessors = NULL;
	if (BellmanFord(g, 'C', distances, predecessors))
		printDistances(g, 'C', distances, predecessors);
	else
		cout<<"The graph contains negative cycles" << endl;
 return 1;
}