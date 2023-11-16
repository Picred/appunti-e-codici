#include "ChainHashing.cpp"


int main(){
	DivisionChainedHashTable<int>* hashDiv= new DivisionChainedHashTable<int> (7);
	int a[] = { 15, 11, 27, 8, 12 };
	for (int i = 0; i < 5; i++)
		hashDiv->insertKey(a[i]);

	hashDiv->printHashTable();

	int pos = -1;
	int pos1 = -1;
	hashDiv->searchKey(8, &pos, &pos1);
	
	cout << "Key found at: "<<pos <<" " << pos1 << endl;
	hashDiv->deleteKey(8);
	hashDiv->printHashTable();
	cout << "Size: " << hashDiv->getSize() << endl;
	
	hashDiv->deleteKey(12);
	cout<<"Deleting key 12"<<endl;
	cout << "Size: " << hashDiv->getSize() << endl;
	hashDiv->printHashTable();
	cout << "Searching keys..." << endl;
	cout << "Key 27 :"<< hashDiv->searchKey(27) << endl;
	cout << "Key 899: "<< hashDiv->searchKey(899) << endl;

	
	MultiplicationChainedHashTable<int> hashMul(5);	
	for (int i = 0; i < 5; i++)
		hashMul.insertKey(a[i]);

	hashMul.insertKey(56);
	hashMul.deleteKey(12);
	hashMul.printHashTable();
}