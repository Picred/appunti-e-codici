#include <iostream> 
#include <queue> 

using namespace std;

template <class T> 
class Node{
	private:
		T key;
		int color;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;

	public:
		Node(T _key, int _color){
			parent = left = right = NULL;
			key = _key;
			color = _color;
		}
		
		T getKey(){
			return key;
		}

		int getColor(){
			return color;
		}

		Node<T>* getNodeLeft(){
			return left;
		}

		Node<T>* getNodeRight(){
			return right;
		}

		Node<T>* getNodeParent(){
			return parent;
		}

		void setNodeLeft(Node<T>* node){
			left=node;
		}

		void setNodeRight(Node<T>* node){
			right = node;
		}

		void setKey(T nkey){
			key = nkey;
		}

		void setColor(int ncolor){
			color = ncolor;
		}

		void setNodeParent(Node<T>* node){
			parent = node;
		}
};

template <class T> 
class RBTree{
	private:
		const int RED = 1;
		const int BLACK = 0;
		Node<T>* root;


		int isLeftChild(Node<T>* node){
			return node == node->getNodeParent()->getNodeLeft();
		}

		void moveNodeUp(Node<T>* parent, Node<T>* child){ // moves parent down and put child in its place 
			if (parent->getNodeParent() != NULL){
				if (isLeftChild(parent)) //se il parent è filgio destro o sinistro, in rotazione, cambia figlio destro e sinistro ovviamente
					parent->getNodeParent()->setNodeLeft(child);
				else
					parent->getNodeParent()->setNodeRight(child);
			}
			else
				this->setRoot(child);
			child->setNodeParent(parent->getNodeParent());
			parent->setNodeParent(child);
		}


		Node<T>* getNodeUncle(Node<T>* node){
			if (node->getNodeParent() == NULL || node->getNodeParent()->getNodeParent() == NULL)
				return NULL;
			if (isLeftChild(node->getNodeParent()))
				return node->getNodeParent()->getNodeParent()->getNodeRight();
			else
				return node->getNodeParent()->getNodeParent()->getNodeLeft();
		}

		Node<T>* getNodeSibling(Node<T>* node){ // returns pointer to sibling
			// sibling null if no parent 
			if (node->getNodeParent() == NULL)
				return NULL;
			if (isLeftChild(node))
				return node->getNodeParent()->getNodeRight();
			return node->getNodeParent()->getNodeLeft();
		}

		bool hasColorChild(Node<T>* node, int _color)
		{
			return (node->getNodeLeft() != NULL && node->getNodeLeft()->getColor() == _color)
				|| (node->getNodeRight() != NULL && node->getNodeRight()->getColor() == _color);
		}


		void printLevelOrder(Node<T>* x){ // level order visit
			queue<Node<T>*> q;
			q.push(x);
			while (!q.empty()){
				Node<T>* curr = q.front();
				q.pop();
				if (curr == NULL)
					cout << "(NIL) ";
				else{
					cout << "(" << curr->getKey() << "," << printColorChar(curr->getColor()) << ") ";
					q.push(curr->getNodeLeft());
					q.push(curr->getNodeRight());
				}
			}
		}

		void leftRotate(Node<T>* node){
			Node<T>* nParent = node->getNodeRight(); // new parent will be node's right child 			
			moveNodeUp(node, nParent);		//if (node == root)	root = nParent;
			node->setNodeRight(nParent->getNodeLeft());// connect x with new parent's left element 		
			if (nParent->getNodeLeft() != NULL) // connect new parent's left element with node  if it is not null 
				nParent->getNodeLeft()->setNodeParent(node);
			nParent->setNodeLeft(node); // connect new parent with x 
		}


		void rightRotate(Node<T>* node){
			Node<T>* nParent = node->getNodeLeft();// new parent will be node's left child 				
			moveNodeUp(node, nParent);// connect x with new parent's right element 		
			node->setNodeLeft(nParent->getNodeRight());
			if (nParent->getNodeRight() != NULL)// connect new parent's right element with node  if it is not null 		
				nParent->getNodeRight()->setNodeParent(node);
			nParent->setNodeRight(node);// connect new parent with x 
		}

		void swapColors(Node<T>* node1, Node<T>* node2){
			int temp = node1->getColor();
			node1->setColor(node2->getColor());
			node2->setColor(temp);
		}

		void swapKeys(Node<T>* node1, Node<T>* node2){
			T temp = node1->getKey();
			node1->setKey(node2->getKey());
			node2->setKey(temp);
		}


		void insertFixUp(Node<T>* node){ // fix red red at given node 
			if (node == this->getRoot()){ // if x is root color it black and return 
				node->setColor(BLACK);
				return;
			}

			Node<T>* parent = node->getNodeParent();
			Node<T>* grandparent = parent->getNodeParent();
			Node<T>* uncle = getNodeUncle(node);
			if (parent->getColor() != BLACK){
				if (uncle != NULL && uncle->getColor() == RED){ // uncle red, perform recoloring and recurse: case 1
					parent->setColor(BLACK);
					uncle->setColor(BLACK);
					grandparent->setColor(RED);
					insertFixUp(grandparent);
				}
				else{ // rotations
					if (isLeftChild(parent)){
						if (isLeftChild(node))	   //case 3
							swapColors(parent, grandparent);
						else{ //case 2
							leftRotate(parent);
							swapColors(node, grandparent);
						}
						(grandparent);
					}
					else{
						if (isLeftChild(node)){
							rightRotate(parent);
							swapColors(node, grandparent);
						}
						else
							swapColors(parent, grandparent);
						leftRotate(grandparent);
					}
				}
			}
		}


		void iterativeInsertFixUp(Node<T>* key){ // fix red red at given node
			Node<T>* node = key;
			do{
				if (node == this->getRoot()){ // if x is root color it black and return 
					node->setColor(BLACK);
					return;
				}

				Node<T>* parent = node->getNodeParent();
				Node<T>* grandparent = parent->getNodeParent();
				Node<T>* uncle = getNodeUncle(node);
				
				if (parent->getColor() == BLACK)
					return;
				if (uncle != NULL && uncle->getColor() == RED) // uncle red, perform recoloring and recurse: case 1
				{
					parent->setColor(BLACK);
					uncle->setColor(BLACK);
					grandparent->setColor(RED);
					node = grandparent; //cosi ripeto il loop, come se fosse un caso ricorsivo
				}
				else // rotations
				{
					if (isLeftChild(parent))
					{
						if (isLeftChild(node))	   //case 3
							swapColors(parent, grandparent);
						else  //case 2
						{
							leftRotate(parent);
							swapColors(node, grandparent);
						}
						rightRotate(grandparent);
					}
					else
					{
						if (isLeftChild(node))
						{
							rightRotate(parent);
							swapColors(node, grandparent);
						}
						else
							swapColors(parent, grandparent);
						leftRotate(grandparent);
					}
					return;
				}
			} while (true);
		}

		double compare(T a, T b)
		{
			return ((a) - (double)(b));
		}

		Node<T>* search(T key) //search for a key, return the node if exists otherwise return the last node in th path
		{
			Node<T>* temp = this->getRoot();
			while (temp != NULL && compare(key,temp->getKey()) != 0)
			{
				if (compare(key, temp->getKey())<0)
				{
					if (temp->getNodeLeft() != NULL)
						temp = temp->getNodeLeft();
					else break;
				}
				else
				{
					if (temp->getNodeRight() != NULL)
						temp = temp->getNodeRight();
					else
						break;
				}
			}
			return temp;
		}
		
		
		Node<T>* minimum(Node<T>* n)
		{
			if (n == NULL)
				return n;
			Node<T>* tmp = n;
			while (tmp->getNodeLeft() != NULL)
				tmp = tmp->getNodeLeft();
			return tmp;
		}

		Node<T>* maximum(Node<T>* n)
		{
			if (n == NULL)
				return n;
			Node<T>* tmp = n;
			while (tmp->getNodeRight() != NULL)
				tmp = tmp->getNodeRight();
			return tmp;
		}

		Node<T>* predecessor(Node<T>* n)
		{
			if (n == NULL)
				return n;
			if (n->getNodeLeft() != NULL)
				return maximum(n->getNodeLeft());
			Node<T>* tmp = n->getNodeParent();
			while (tmp != NULL && n == tmp->getNodeLeft())
			{
				n = tmp;
				tmp = tmp->getNodeParent();
			}
			return tmp;
		}

		Node<T>* successor(Node<T>* n)
		{
			if (n == NULL)
				return n;
			if (n->getNodeRight() != NULL)
				return minimum(n->getNodeRight());
			Node<T>* tmp = n->getNodeParent();
			while (tmp != NULL && n == tmp->getNodeRight())
			{
				n = tmp;
				tmp = tmp->getNodeParent();
			}
			return tmp;
		}


		Node<T>* replaceNodeBST(Node<T>* x) // find the node replacing a deleted node in BST 
		{
			if (x->getNodeLeft() != NULL && x->getNodeRight() != NULL) // when node have 2 children 
				return successor(x);
			if (x->getNodeLeft() == NULL && x->getNodeRight() == NULL) // when leaf 
				return NULL;
			if (x->getNodeLeft() != NULL)// when single child 
				return x->getNodeLeft();
			else
				return x->getNodeRight();
		}


		void deleteNode(Node<T>* node)
		{
			Node<T>* replace = replaceNodeBST(node);
			bool combColor = ((replace == NULL || replace->getColor() == BLACK) && (node->getColor() == BLACK));
			Node<T>* parent = node->getNodeParent();
			if (replace == NULL)// node is a leaf 
			{
				if (node == this->getRoot())
					this->setRoot(NULL);
				else
				{
					if (combColor) //both black					
						deleteFixUp(node);
					else  // one of the two is red 
					{
						if (getNodeSibling(node) != NULL)
							getNodeSibling(node)->setColor(RED);
					}
					if (isLeftChild(node))//deleting				
						parent->setNodeLeft(NULL);
					else
						parent->setNodeRight(NULL);
				}
				delete node;
				return;
			}
			if (node->getNodeLeft() == NULL || node->getNodeRight() == NULL) // node has 1 child 
			{
				if (node == this->getRoot())// node is root 
				{
					node->setKey(replace->getKey());
					node->setNodeLeft(NULL);
					node->setNodeRight(NULL);
					delete replace;
				}
				else // Detach node from tree and move replace up 
				{
					if (isLeftChild(node))
						parent->setNodeLeft(replace);
					else
						parent->setNodeRight(replace);
					delete node;
					replace->setNodeParent(parent);
					if (combColor) // replace and node are black, fix double black at replace 					
						deleteFixUp(replace);
					else // one is red					
						replace->setColor(BLACK);
				}
				return;
			}
			swapKeys(replace, node); // node has 2 children, swap values with successor and recurse 
			deleteNode(replace);
		}
		

		void deleteFixUp(Node<T>* node)
		{
			Node<T>* x = node;
			while (x != this->getRoot())
			{
				Node<T>* sibling = getNodeSibling(x);
				Node<T>* parent = x->getNodeParent();
				if (sibling == NULL) // No sibiling		
					x = parent;
				else
				{
					if (sibling->getColor() == RED) // red sibling, case 1
					{
						parent->setColor(RED);
						sibling->setColor(BLACK);
						if (isLeftChild(sibling))// left case				 
							rightRotate(parent);
						else // right case 
							leftRotate(parent);
						//x=x; repeat the while again with x
					}
					else //case 2,3,4 Sibling black
					{
						if (hasColorChild(sibling, RED))// exists a red child, case 3, 4
						{
							if (sibling->getNodeLeft() != NULL && sibling->getNodeLeft()->getColor() == RED)
							{
								if (isLeftChild(sibling)) // left left case 4
								{
									sibling->getNodeLeft()->setColor(sibling->getColor());
									sibling->setColor(parent->getColor());
									rightRotate(parent);
								}
								else // right left case 3
								{
									sibling->getNodeLeft()->setColor(parent->getColor());
									rightRotate(sibling);
									leftRotate(parent);
								}
							}
							else
							{
								if (isLeftChild(sibling)) // left right case 3
								{
									sibling->getNodeRight()->setColor(parent->getColor());
									leftRotate(sibling);
									rightRotate(parent);
								}
								else // right right case 4
								{
									sibling->getNodeRight()->setColor(sibling->getColor());
									sibling->setColor(parent->getColor());
									leftRotate(parent);
								}
							}
							parent->setColor(BLACK);
							break;
						}
						else // case 2, both black children
						{
							sibling->setColor(RED);
							if (parent->getColor() == BLACK)
								x = parent;
							else
							{
								parent->setColor(BLACK);
								break;
							}
						}
					}
				}
			}
		}
			
			
		void printInOrder(Node<T>* node) // print inorder
		{
		if (node == NULL)
		{
		cout << "(NIL) ";
		return;
		}
		printInOrder(node->getNodeLeft());
		cout << "("<< node->getKey() << ","<<printColorChar(node->getColor())<<") ";
		printInOrder(node->getNodeRight());
		}

	public:	 
		RBTree()
		{
		root = NULL;
		}

		Node<T>* getRoot() 
		{
		return root;
		}

		void setRoot(Node<T>* nroot)
		{
		root = nroot;
		}
		
		char printColorChar(int c)
		{
			if (c)
				return 'R';
			return 'B';
		}

		Node<T>* searchKey(T key) //search for a key, return the node if exists otherwise return the last node in th path
		{
			Node<T>* temp = root;
			while (temp != NULL && compare(key, temp->getKey()) != 0)
			{
			if (compare(key, temp->getKey()) < 0)
				temp = temp->getNodeLeft();	
			else						
				temp = temp->getNodeRight();			
			}
			return temp;
		}


		RBTree<T>* deleteKey(T key)
		{
			Node<T>* n = searchKey(key);
			if (n == NULL)
				return NULL;
			deleteNode(n);
			return this;
		}

		
		RBTree* insertKey(T n) // insert the given key 
		{
		Node<T>* newNode = new Node<T>(n, RED);
		if (root == NULL) //no root, the value is the root
		{	 
		root = newNode;
		}
		else
		{
		Node<T>* temp = search(n); //search the key
		if (compare(n, temp->getKey()) != 0) //value not found
		{
			newNode->setNodeParent(temp);
			if (compare(n, temp->getKey()) < 0)
				temp->setNodeLeft(newNode);
			else
				temp->setNodeRight(newNode);
		}
		else 
			return this;
		} 
		// insertFixUp(newNode);// fix red red violaton if exists 
		iterativeInsertFixUp(newNode);
		return this;
		}


		void printInOrder() // print inorder
		{
		cout << "Inorder: " << endl;
		if (root == NULL)
		cout << "(NIL)" << endl;
		else
		printInOrder(root);
		cout << endl;
		}

		
		void printLevelOrder() // print level order 
		{
		cout << "Level order: " << endl;
		if (this->getRoot() == NULL)
		cout << "NIL" << endl;
		else
		printLevelOrder(this->getRoot());
		cout << endl;
		}
};

