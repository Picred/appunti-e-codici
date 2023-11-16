#include "Graph.cpp"

using namespace std;

template <class H, class T> int floydWarshall(Graph<H, T>* graph, T**& dist, int**& pred)
{
	int V = graph->getCurrentNodeNumber();

	dist = new T* [V];
    pred = new int* [V];
	for (int i = 0; i < V; i++)
	{
		dist[i] = new T[V];
		pred[i] = new int[V];
	}	

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			if (i == j)
			{
				dist[i][j] = 0;
				pred[i][j] = i;
			}
			else if (graph->getGraphIndexMatrix()[i][j] == 1)
			{
				dist[i][j] = graph->getGraphWeightMatrix()[i][j];
				pred[i][j] = i;
			}
			else
			{
				dist[i][j] = INT_MAX;
				pred[i][j] = -1;
			}
		}
	           
	for (int k = 0; k < V; k++)	
		for (int i = 0; i < V; i++)		
			for (int j = 0; j < V; j++)
			{
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						pred[i][j] = pred[k][j];
						//negative cycle check
						if (i == j && dist[i][j]<0)
						{
							return 0;
						}
					}
				
			}
	
	return 1;
}

/* A utility function to print solution */
template <class H, class T> void printDistances(Graph<H, T>* graph, T* dist[], int* pred[])
{	
	int V = graph->getCurrentNodeNumber();
	cout << "  ";
	for (int i = 0; i < V; i++)
		cout << *(graph->getKey(i)) << " ";
	cout << endl;

	for (int i = 0; i < V; i++)
	{
		cout << *(graph->getKey(i)) << " ";
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INT_MAX)
				cout << "INF" << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl <<"  ";
	for (int i = 0; i < V; i++)
		cout << *(graph->getKey(i)) << " ";
	cout << endl;
	for (int i = 0; i < V; i++)
	{
		cout << *(graph->getKey(i)) << " ";
		for (int j = 0; j < V; j++)
		{
			cout << pred[i][j] << " ";
		}
		cout << endl;
	}

}

template <class H, class T> void printPath(Graph<H, T>* graph, int* pred[], H &startk, H& endk)
{
	int start = graph->findIndex(startk);
	int end = graph->findIndex(endk);
	
	vector<int> stack = vector<int>();
	stack.push_back(end);
	stack.push_back(pred[start][end]);	
	while (stack.back() != pred[start][stack.back()])
	{
		if(stack.back() == -1)
		{
			stack.clear();
			break;
		}
		stack.push_back(pred[start][stack.back()]);		
	}

	if (stack.empty())
	{
		cout << "There is no path between " << startk << " and " << endk << endl;
		return;
	}
	while(!stack.empty())
	{		
		cout << "("<<stack.back() <<"," <<*(graph->getKey(stack.back())) << ")";
		stack.pop_back();
		if (!stack.empty())
			cout << ", ";
	}
	cout << endl;	
}

int main()
{
	Graph<char, int>* g = new Graph<char, int>(6);
	g->addNode('1')->addRootNode('2')->addRootNode('3')->addNode('4')->addNode('5');
	g->addEdge('1', '2', 5)->addEdge('1', '4', 1)->addEdge('3', '2', 1)->addEdge('4', '2', 3)->addEdge('4', '3', 1)->addEdge('4', '5', 3);
	g->print();	
	cout << endl<< "Floyd-Warshall:" << endl <<endl;
	int** distances;
	int** pred;
	floydWarshall(g, distances, pred);
	printDistances(g, distances, pred);
	char s = '4';
	char e = '1';
	cout << endl << "The path from " << s << " to " << e << " is :" << endl;
	printPath(g, pred, s, e);
	return 1;
}