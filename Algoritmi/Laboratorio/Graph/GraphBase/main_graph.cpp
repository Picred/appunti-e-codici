#include "graph.cpp"

int main()
{
	int def = 0;
	Graph<char, int>* g = new Graph<char, int>(4);
	g->addNode('A')->addRootNode('C')->addRootNode('B')->addNode('D');
	g->addEdge('C', 'B', def)->addEdge('C', 'A', def)->addEdge('C', 'C', def)->addEdge('B', 'D', def)->addEdge('A', 'D', def);
	cout << "Max size of the graph: " << g->getMaxNodeNumber() << endl;
	cout << "Current node number: " << g->getCurrentNodeNumber() << endl;
	cout << "Current edge number: " << g->getCurrentEdgeNumber() << endl;
	g->print();
	cout << "The root is " << *(g->getRootNode()) << " at index " << g->getRootIndex() << endl;
	cout << "We now change the root" << endl;
	g->setRootNode('C');
	cout << "The new root is " << *(g->getRootNode()) << " at index " << g->getRootIndex() << endl;
	cout << "We now delete some edges" << endl;
	g->deleteEdge('C', 'A')->deleteEdge('B', 'D');
	cout << "Current edge number: " << g->getCurrentEdgeNumber() << endl;
	g->print();
	cout << "Modifying graph" << endl;
	g->addEdge('C', 'A', def)->addEdge('B', 'D', def)->addEdge('A', 'C', def)->addEdge('B', 'C', def);
	g->print();
	cout << "BFS Visit From " << *(g->getRootNode())<<" at index "<<g->getRootIndex()<< endl;
	vector<int> BFSpredecessors;
	vector<int> BFSdistances;
	g->BFS_visit(*(g->getRootNode()),BFSpredecessors, BFSdistances);
	for (int i = 0; i < BFSpredecessors.size(); i++)
	{
		cout << "BFS Visit From " << *(g->getRootNode()) << " to " << *(g->getKey(i)) << " has predecessor ";
		if (BFSpredecessors[i] == -1)
			cout << "NIL";
		else
			cout << *(g->getKey(BFSpredecessors[i]));
		cout<< " and " << BFSdistances[i] << " edges "<< endl;
	}

	vector<int> DFSpredecessors;
	vector<int> DFSdiscoverTime;
	vector<int> DFSfinishTime;
    cout << "DFS Visit: "<< endl;
	g->DFS_recursive_visit(DFSpredecessors, DFSdiscoverTime, DFSfinishTime);	
	for (int i = 0; i < DFSpredecessors.size(); i++)
	{
		cout <<  *(g->getKey(i)) << " has predecessor ";
		if (DFSpredecessors[i] == -1)
			cout << "NIL";
		else
			cout << *(g->getKey(DFSpredecessors[i]));
		cout << ", discover time " << DFSdiscoverTime[i] << " and finish time "<<DFSfinishTime[i] << endl;
	}

	cout << "Deleting node" << endl;
	//change the root node before deleting
	g->setRootNode('B');
	g->deleteNode('C');
	g->print();
	return 0;
}