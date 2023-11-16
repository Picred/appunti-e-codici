#include "Heap.cpp"


int main(){
	MaxHeap<int>* B = new MaxHeap<int>(100);
	B->enqueue(6)->enqueue(9)->enqueue(2)->enqueue(7)->enqueue(12);
	cout << "The queue is :" << endl;
	B->print();
	cout << "The max is: " << *(B->extractMax()) << endl;
	cout << "The queue after the extact is:" << endl;
	B->print(); 
	cout << "The tree is:" << endl; 
	cout << "Additional elements" << endl;
	B->enqueue(4)->enqueue(1)->enqueue(5);
	B->print();
	cout << "Increase key indexed 6 to 8" << endl;
	B->increaseKey(6, 8);
	B->print();
	cout << "Sorting" << endl;
	B->sort();
	B->print();

	cout << endl << endl;

	int node_number = 100;
	int** V = new int* [node_number];
	for (int i = 1; i < node_number; i++)
		V[i] = new int(rand() % 100);
	MinHeap<int>* C = new MinHeap<int>(V, node_number);
	cout << "The initial array is:" << endl;
	C->print();
	cout << "Building the heap" << endl;
	C->buildHeap();
	cout << "The heap is:" << endl;
	C->print();
	cout << "The tree is:" << endl;
	cout << "Sorting..." << endl;
	C->sort();
	cout << "The sorted array is:" << endl;
	C->print();
	return 1;
}
