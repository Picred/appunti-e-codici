#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class NodeManager
{
private:
    T **pArray;
    size_t nSize;
    int iCounter;
public:
    NodeManager(size_t size)
    {
        nSize = size;
        pArray = new T*[nSize];
        iCounter = 0;
    }

    void insert(T key)
    {
        pArray[iCounter] = new T(key);
        iCounter++;
    }

    int indexOf(T key)
    {
        for (size_t i = 0; i < nSize; i++)
        {
            if(*pArray[i] == key)
                return i;
        }
        return -1;
    }

    T contentOf(int i)
    {
        return *pArray[i];
    }
};

template<typename T>
class Graph
{
private:
    bool **bAdj;
    size_t nSize; // nodes
    bool *bVisited;
    NodeManager<T> *pNodeMng;

    void _dfs(size_t index, T *iArr, int &iCounter)
    {
        bVisited[index] = true;
        for (size_t i = 0; i < nSize; i++)
        {
            if(bAdj[index][i] && !bVisited[i])
                _dfs(i, iArr, iCounter);
        }
        iArr[iCounter] = pNodeMng->contentOf(index);
        iCounter++;
    }

public:
    Graph(size_t size)
    {
        nSize = size;
        bAdj = new bool*[nSize];
        for (size_t i = 0; i < nSize; i++)
            bAdj[i] = new bool[nSize]();
        bVisited = new bool[nSize]();
        pNodeMng = new NodeManager<T>(nSize);
    }

    void insertNode(T key)
    {
        pNodeMng->insert(key);
    }

    void insertEdge(T from, T to)
    {
        bAdj[pNodeMng->indexOf(from)][pNodeMng->indexOf(to)] = true;
    }

    void dfs(T *iArr)
    {
        int iCounter = 0;
        for (size_t i = 0; i < nSize; i++)
        {
            if(!bVisited[i])
                _dfs(i, iArr, iCounter);
        }
        
    }

};


template <typename T>
void process(ifstream &ifFile, ofstream &ofFile, size_t nNodes, size_t nEdges)
{
    Graph<T> *pGraph = new Graph<T>(nNodes);
    for (size_t i = 0; i < nNodes; i++)
    {
        T temp;
        ifFile >> temp;
        pGraph->insertNode(temp);
    }

    for (size_t i = 0; i < nEdges; i++)
    {
        T start, end;
        char junk;

        ifFile >> junk;
        ifFile >> start;
        //ifFile >> junk;
        ifFile >> end;
        ifFile >> junk;

        pGraph->insertEdge(start, end);
    }
    T *Arr = new T[nNodes];

    pGraph->dfs(Arr);

    for (int i = nNodes -1; i >= 0; i--)
    {
        ofFile << Arr[i] << " ";
    }

    ofFile << endl;
    
}

int main ()
{
    ifstream ifFile("input.txt");
    ofstream ofFile("output.txt");

    size_t nNodes, nEdges;
    string strType;
    
    while(ifFile >> nNodes)
    {
        ifFile >> nEdges;
        ifFile >> strType;

        switch (strType[0])
        {
            case 'i':
            process<int>(ifFile, ofFile, nNodes, nEdges);
            break;

            case 'd':
            process<double>(ifFile, ofFile, nNodes, nEdges);
            break;

            case 'b':
            process<bool>(ifFile, ofFile, nNodes, nEdges);
            break;

            case 'c':
            process<char>(ifFile, ofFile, nNodes, nEdges);
            break;

        }
    }

    return 0;
}