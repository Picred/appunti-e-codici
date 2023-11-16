#include <iostream>
#include <vector>
#include <string>
#include "../Heap/StandardHeap/Heap.cpp"

using namespace std;

template <class T> 
class HuffmanMinHeap : public MinBinaryHeap<T> //
{
 public:
	HuffmanMinHeap(int size) : MinBinaryHeap<T>(size) {}
	HuffmanMinHeap(T** A, int size) : MinBinaryHeap<T>(A, size) {}
	double compare(T* a, T* b)
	{
	 return ((double) b->getFrequency() - a->getFrequency());
	}		
	void printKey(int i) const
	{
	 cout << ((this->getPriorityQueue())[i])->getKey() << "," << ((this->getPriorityQueue())[i])->getFrequency() << endl;		 
	}
};



template <class T> class Node
{
private:
	T key;
	int frequency;
	Node<T> *left, *right;	
public:
	Node<T>(T key, int _frequency)
	{
	 this->key = key;
	 left = right = NULL;		
	 this->frequency = _frequency;
	}
	T getKey()
	{ 
	 return key; 
	}
	int isLeaf()
	{
	 return (getLeftNode()==NULL && getRightNode()==NULL); 
	}
	int getFrequency()
	{ 
	 return frequency;
	}
	Node<T>* getLeftNode()
	{ 
	 return left;
	}
	Node<T>* getRightNode()
	{
	 return right;
	}
	void setKey(T key)
	{
	 this->key = key;
	}	
	void setFrequency(int frequency)
	{
	 this->frequency = frequency;
	}	
	void setLeft(Node<T>* left)
	{
	 this->left = left;
	}
	void setRight(Node<T>* right)
	{
	 this->right = right;
	}
};





class HuffmanCode
{ 	 
private:	
	Node<char>* root;
	vector<pair<char,string>> map; //use hash table instead
	
	void buildCodes(Node<char>* root, string str){		  
		  if (root->isLeaf()){ //quando arrivo ad una foglia inserisco la codifica di quello specifico carattere sulla tabella
			  for (size_t i = 0; i < map.size(); i++) {
				  if (root->getKey() == map[i].first){
					  map[i].second=str;
					  return;
				  }
			  }
		  }
		  buildCodes(root->getLeftNode(), str + "0");
		  buildCodes(root->getRightNode(), str + "1");
	  }

	void buildRecursiveCodes()
	{
		buildCodes(root, "");
	}

	void buildIterativeCodes()
	{	  
	  vector<pair<Node<char>*,string>> nstack = vector<pair<Node<char>*, string>>();
	  nstack.push_back(pair<Node<char>*,string>(root, ""));
	  while (!nstack.empty())
	  {		  
		  pair<Node<char>*, string> tmp = nstack.back();
		  nstack.pop_back();		  
		  for (size_t i = 0; i < map.size(); i++)
		  {
			  if (tmp.first->isLeaf() && tmp.first->getKey() == map[i].first)
			  {
				  map[i].second = tmp.second;
				  break;
			  }
		  }		
		  if (tmp.first->getLeftNode() != NULL)		  
			  nstack.push_back(pair<Node<char>*, string>(tmp.first->getLeftNode(), tmp.second + "0"));
		  if (tmp.first->getRightNode() != NULL)
		     nstack.push_back(pair<Node<char>*, string>(tmp.first->getRightNode(), tmp.second + "1"));		  
	  }
	}

  public:	  
	  HuffmanCode(char* chars,  int* frequencies, size_t size){ //creo heap, doppia estrazine minimo, inserimento nodo
		  map = vector<pair<char,string>>(size); //inizializzo tabella con dimensione
		  root = NULL; 		  
		  for (size_t i = 0; i < size; i++) // popolo la tabella, cioè i char
			  map[i] = pair<char, string>(chars[i], "");

	HuffmanMinHeap<Node<char>>* heap = new HuffmanMinHeap<Node<char>>(size);	

		  for (size_t i = 0; i < size; i++){ //inserisco i nodi in mihneap (heap)	  
			  Node<char> tmp = Node<char>(chars[i], frequencies[i]);				  
			  heap->enqueue(tmp);				 
		  }

		  for (size_t i = 0; i < size-1; i++){ 
			  Node<char>* left = heap->extractMin();
			  Node<char>* right = heap->extractMin();			 
			  Node<char> parent = Node<char>('\0', left->getFrequency() + right->getFrequency());
			  parent.setLeft(left);
			  parent.setRight(right);
			  heap->enqueue(parent);
		  }

		  root = heap->extractMin(); //setto la radice dell'albero
		  delete heap;
		  buildRecursiveCodes();
	  }	  

	  Node<char>* getHuffmanTree()
	  {
		  return root;
	  }	  

	  vector<pair<char, string>>& getCodes()
	  {
		  return map;
	  }

	  void printCodes()
	  {
		for (auto t : map)		  
		  cout << t.first << ":" << t.second << endl;		  
	  }

	  string encode(string& s) //use the hash table instead
	  {
		  string result = "";
		  for (auto c : s)
		  {
			  size_t i = 0;
			  for (; i < map.size(); i++)
			  {
				  if (map[i].first == c)
				  {
					  result.append(map[i].second);
					  break;
				  }
			  }
			  if (i == map.size())
				  return "";
		  }
		  return result;
	  }

	  string decode(string& s) //use a tree visit
	  {
		  if (s.empty())
			  return "";
		 string result = "";
		 string tmp = "";
		 size_t i = 0;
		 while(i < s.size())
		  { 			 
			 tmp+=s[i];				 	 
			 for (size_t j = 0; j < map.size(); j++)
			 {
				 if (tmp == map[j].second)
				 {					
					 result+=map[j].first;
					 tmp = "";
					 break;
				 }
			 }
			 i++;
		  }
		 return result;
	  } 
};