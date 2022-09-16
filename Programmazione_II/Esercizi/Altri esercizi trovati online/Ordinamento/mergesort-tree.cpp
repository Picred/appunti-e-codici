#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class Node
{
private:
    T *pKey;
    Node<T> *pLeft, *pRight;
public:
    Node(T &key)
    {
        this->pKey = new T(key);
        this->pLeft = this->pRight = NULL;
    }

    T& getKey() const
    {
        return *(this->pKey);
    }

    void setKey(T& key)
    {
        this->pKey = new T(key);
    }

    Node<T> *getLeft() const
    {
        return this->pLeft;
    }

    void setLeft(Node<T> *pNode)
    {
        this->pLeft = pNode;
    }

    Node<T> *getRight() const
    {
        return this->pRight;
    }

    void setRight(Node<T> *pNode)
    {
        this->pRight = pNode;
    }

};

template<typename T>
class BST
{
private:
    Node<T> *pRoot;
    T *arrInput;
    size_t nSize; 
    int iCurrNodesCount;

    Node<T> *_insert(Node<T> *pLastRoot, T& key)
    {
        if(pLastRoot == NULL)
        {
            pLastRoot = new Node<T>(key);
            return pLastRoot;
        }

        if(pLastRoot->getKey() > key)
            pLastRoot->setLeft(_insert(pLastRoot->getLeft(), key));
        else
            pLastRoot->setRight(_insert(pLastRoot->getRight(), key));
        
        return pLastRoot;        
    }

    void _inOrder(Node<T> *pLastRoot, ofstream &ofFile)
    {
        if(pLastRoot == NULL)
            return;
        
        _inOrder(pLastRoot->getLeft(), ofFile);
        ofFile << pLastRoot->getKey() << " ";
        _inOrder(pLastRoot->getRight(), ofFile);
    }


    void _mergeSort(ofstream &ofFile) 
    {
        int iMiddle = this->nSize / 2;
        if(iMiddle > 0)
        {
            BST<T> *pBST_Left = new BST<T>(iMiddle);
            BST<T> *pBST_Right = new BST<T>(this->nSize - iMiddle);

            for (int i = 0; i < iMiddle; i++)
                pBST_Left->insert(this->arrInput[i]);

            for (size_t i = iMiddle; i < this->nSize; i++)
                pBST_Right->insert(this->arrInput[i]);
            
            pBST_Left->printOut(ofFile);
            pBST_Left->mergeSort(ofFile);

            pBST_Right->printOut(ofFile);
            pBST_Right->mergeSort(ofFile);

            delete pBST_Left;
            delete pBST_Right;
        }
        
    } 

public:
    BST(size_t nSize)
    {
        this->nSize = nSize;
        this->arrInput = new T[nSize];
        this->iCurrNodesCount = 0;
        this->pRoot = NULL;
    }

    void mergeSort(ofstream &ofFile)
    {
        _mergeSort(ofFile);
    }

    void insert(T& key)
    {
        this->pRoot = _insert(this->pRoot, key);
        this->arrInput[this->iCurrNodesCount] = key;
        this->iCurrNodesCount++;
    }

    void inOrder(ofstream &ofFile)
    {
        _inOrder(pRoot, ofFile);
    }

    void printOut(ofstream &ofFile)
    {
        ofFile << "[ ";

        for (size_t i = 0; i < this->nSize; i++)
            ofFile << this->arrInput[i] << " ";
        
        ofFile << ": ";

        inOrder(ofFile);
        
        ofFile << "] ";// << endl;
        
    }

};

template<typename T>
void process(ifstream &ifFile, ofstream &ofFile)
{
    size_t nSize;
    ifFile >> nSize;

    BST<T> *pBST = new BST<T>(nSize);

    for (size_t i = 0; i < nSize; i++)
    {
        T temp;
        ifFile >> temp;
        pBST->insert(temp);
    }

    pBST->printOut(ofFile);
    pBST->mergeSort(ofFile);
    ofFile << endl;

    delete pBST;
}

int main()
{
    ifstream ifFile("input.txt");
    ofstream ofFile("output.txt");

    string strType;

    while(ifFile >> strType)
    {
        switch(strType[0])
        {
            case 'i':
            process<int>(ifFile, ofFile);
            break;
            case 'b':
            process<bool>(ifFile, ofFile);
            break;
            case 'c':
            process<char>(ifFile, ofFile);
            break;
            case 'd':
            process<double>(ifFile, ofFile);
            break;
        }
    }

    return 0;
}