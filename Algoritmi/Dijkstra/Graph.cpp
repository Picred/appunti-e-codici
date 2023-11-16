#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;


template <class H, class T> class Graph
{
private:
	int maxLenght, node_number, edge_number;
	H** keyMap;
	T** weightMatrix;
	int** indexMatrix;
	int rootindex;

	Graph<H, T>* modifyEdge(H const& x, H const& y, T const& _weight, int ind)
	{
		int i = findIndex(x);
		int j = findIndex(y);
		if (i < 0 || j < 0)
			return this;
		if (indexMatrix[i][j] == ind)
		{
			if (ind)
			{
				indexMatrix[i][j] = 0;
				edge_number--;
			}
			else
			{
				indexMatrix[i][j] = 1;
				edge_number++;

			}			
			weightMatrix[i][j] = _weight;
		}
		return this;
	}

	void _DFS_recursive_visit(int vertex, int& time, vector<int>& colors, vector<int>& predecessors, vector<int>& discovertime, vector<int>& finishtime)
	{
		time++;
		discovertime[vertex] = time;
		colors[vertex] = 1;
		for (int i = 0; i < this->getCurrentNodeNumber(); i++)
		{
			if (colors[i] == 0 && this->getGraphIndexMatrix()[vertex][i] == 1)
			{
				predecessors[i] = vertex;
				_DFS_recursive_visit(i, time, colors, predecessors, discovertime, finishtime);
			}
		}
		colors[vertex] = 2;
		time++;
		finishtime[vertex] = time;
	}

public:
	Graph(int _maxLenght)
	{
		this->maxLenght = _maxLenght;
		indexMatrix = new int* [maxLenght];
		weightMatrix = new T * [maxLenght];
		edge_number = node_number = 0;
		rootindex = -1;
		for (int i = 0; i < maxLenght; i++)
		{
			indexMatrix[i] = new int[maxLenght];
			weightMatrix[i] = new T[maxLenght];
			for (int j = 0; j < maxLenght; j++)
			{
				indexMatrix[i][j] = 0;
				weightMatrix[i][j] = NULL;
			}
		}
		keyMap = new H * [maxLenght];
		for (int i = 0; i < maxLenght; i++)
			keyMap[i] = NULL;
	}

	int findIndex(H x)
	{
		for (int i = 0; i < node_number; i++)
			if (*keyMap[i] == x)
				return i;
		return -1;
	}

	int getRootIndex()
	{
		return this->rootindex;
	}

	int getMaxNodeNumber()
	{
		return maxLenght;
	}

	int getCurrentNodeNumber()
	{
		return node_number;
	}

	int getCurrentEdgeNumber()
	{
		return edge_number;
	}

	H** getGraphKeyMatrix() 
	{
		return keyMap;
	}

	T** getGraphWeightMatrix() 
	{
		return weightMatrix;
	}

	int** getGraphIndexMatrix() 
	{
		return indexMatrix;
	}

	H* getKey(int index)
	{
		if (index < 0 || index >= node_number)
			return NULL;
		return keyMap[index];
	}

	Graph<H, T>* addNode(H const& k)
	{
		if (node_number == maxLenght)
			return this;
		if (findIndex(k) >= 0)
			return this;
		keyMap[node_number] = new H(k);
		node_number++;
		return this;
	}

	void BFS_visit(H const& key, vector<int>& predecessors, vector<T>& distances)
	{
		int src = this->findIndex(key);
		predecessors = vector<int>(this->getCurrentNodeNumber(), -1);
		distances = vector<int>(this->getCurrentNodeNumber(), INT_MAX);
		vector<T> colors = vector<int>(this->getCurrentNodeNumber(), 0); //0 White // 1 gray // 2 black		
		//predecessors[src] = src;
		distances[src] = 0;
		colors[src] = 1;
		//initializing queue
		queue<int> q = queue<int>();
		q.push(src);
		while (!q.empty())
		{
			int tmp = q.front();
			q.pop();
			for (int i = 0; i < this->getCurrentNodeNumber(); i++)
			{
				if (i!=tmp && colors[i] == 0 && this->getGraphIndexMatrix()[tmp][i] == 1)
				{
				  colors[i] = 1;
				  distances[i] = distances[tmp] + 1;
				  predecessors[i] = tmp;
				  q.push(i);					
				}
			}
			colors[tmp] = 2;			
		}
	}

	
	void DFS_recursive_visit(vector<int>& predecessors, vector<int>& discovertime, vector<int>& finishtime)
	{
	 predecessors = vector<int>(this->getCurrentNodeNumber(), -1);
	 discovertime = vector<int>(this->getCurrentNodeNumber(), INT_MAX);
	 finishtime = vector<int>(this->getCurrentNodeNumber(), INT_MAX);
	 int time=0;
	 vector<int> colors = vector<int>(this->getCurrentNodeNumber(), 0); //0 White // 1 gray // 2 black	 
	 for (int i = 0; i < this->getCurrentNodeNumber(); i++)
	 {
		 if (colors[i] == 0)
			 _DFS_recursive_visit(i, time, colors, predecessors, discovertime, finishtime);
	 }
	}

	


	Graph<H, T>* addRootNode(H const& k)
	{
		rootindex = node_number;
		return addNode(k);
	}

	Graph<H, T>* addEdge(H const& x, H const& y, T const& weight)
	{
		return this->modifyEdge(x, y, weight, 0);
	}

	Graph<H, T>* deleteEdge(H const& x,  H const& y)
	{
		return this->modifyEdge(x, y, NULL, 1);
	}


	Graph<H, T>* deleteNode(H const& key)
	{
		int pos = findIndex(key);
		if (pos < 0 || node_number == 0 || pos == rootindex)
			return this;

		for (int i = pos; i < node_number - 1; i++)
			for (int j = 0; j < node_number - 1; j++)
			{
				indexMatrix[j][i] = indexMatrix[j][i + 1]; //column shift
				weightMatrix[j][i] = weightMatrix[j][i + 1]; //column shift
			}

		for (int i = pos; i <= node_number - 2; i++)
			for (int j = 0; j <= node_number - 2; j++)
			{
				indexMatrix[i][j] = indexMatrix[i + 1][j]; //row shift 
				weightMatrix[i][j] = weightMatrix[i + 1][j]; //row shift
			}

		for (int i = 0; i < node_number; i++) //resetting last column
		{
			indexMatrix[i][node_number - 1] = 0;
			indexMatrix[node_number - 1][i] = 0;

			weightMatrix[i][node_number - 1] = NULL;
			weightMatrix[node_number - 1][i] = NULL;
		}

		for (int j = pos; j < node_number - 1; j++)
			keyMap[j] = keyMap[j + 1];
		keyMap[node_number - 1] = NULL;

		node_number--;
		return this;
	}

	H const* getRootNode()
	{
		if (rootindex < 0)
			return NULL;
		return	keyMap[rootindex];
	}

	void setRootNode(H const& k)
	{
		int t = findIndex(k);
		if (t < 0)
			return;
		else rootindex = t;
	}

	void print() const
	{
		for (int i = 0; i < node_number; i++)
		{
			cout << "(" << i << ", " << *keyMap[i] << ")" << " --> ";
			for (int j = 0; j < node_number; j++)
				if (indexMatrix[i][j])
				{
					cout << "{" << *keyMap[j] << "," << weightMatrix[i][j] << "}  ";

				}
			cout << endl;
		}
	}

	void printIndexMatrix() const
	{
		for (int i = 0; i < node_number; i++)
		{
			for (int j = 0; j < node_number; j++)
				cout << indexMatrix[i][j] << " ";
			cout << endl;
		}
	}

	void printWeightMatrix() const
	{
		for (int i = 0; i < node_number; i++)
		{
			for (int j = 0; j < node_number; j++)
				cout << weightMatrix[i][j] << " ";
			cout << endl;
		}
	}

};
