#include "RB-Tree.cpp"

int main() 
{
 RBTree<int>* rbTree=new RBTree<int>();
 rbTree->insertKey(1)->insertKey(11)->insertKey(12)->insertKey(69)->insertKey(4)->insertKey(14)->insertKey(82)->insertKey(50)->insertKey(77)->insertKey(3);
 rbTree->printInOrder();
 rbTree->printLevelOrder();	
 rbTree->deleteKey(12);
 rbTree->deleteKey(77);
 rbTree->insertKey(7)->insertKey(7)->insertKey(3)->insertKey(18)->insertKey(10)->insertKey(22)->insertKey(8)->insertKey(11)->insertKey(26)->insertKey(2)->insertKey(6)->insertKey(13);
 rbTree->deleteKey(18)->deleteKey(11)->deleteKey(3)->deleteKey(10)->deleteKey(22);
 rbTree->printInOrder();
 rbTree->printLevelOrder();
 Node<int>* tmp = rbTree->searchKey(69);
 if (tmp != NULL)
	 cout << tmp->getKey() << " " << rbTree->printColorChar(tmp->getColor()) << endl;
 else cout << "Key not present" << endl;
 return 0;
}