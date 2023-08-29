#include "OpenHash.cpp"

int main()
{
	cout << "Standard Version of Linear Probing" << endl;
	LinearTombstoneOpenHashTable<int>* test = new LinearTombstoneOpenHashTable<int>(11);
	test->insertKey(72)->insertKey(90)->deleteKey(72);
	cout << test->searchKey(4) << endl;;

	LinearTombstoneOpenHashTable<int>* LOHtable = new LinearTombstoneOpenHashTable<int>(11);
	LOHtable->insertKey(4)->insertKey(34)->insertKey(31)->insertKey(56)->insertKey(51)->insertKey(44)->insertKey(33)->insertKey(77)->insertKey(87)->insertKey(50)->insertKey(2);
	LOHtable->deleteKey(34)->deleteKey(77);
	LOHtable->insertKey(77)->insertKey(22)->deleteKey(51);
	LOHtable->print();	
	cout << "Key 44: " << LOHtable->searchKey(44) << endl;
	cout << "Key 800: " << LOHtable->searchKey(800) << endl;

	cout << "Non-standard Version of Linear Probing" << endl;
	LinearDeleteShiftOpenHashTable<int>* LEOHtable = new LinearDeleteShiftOpenHashTable<int>(11);
	LEOHtable->insertKey(50)->insertKey(4)->insertKey(44)->insertKey(33)->insertKey(77)->insertKey(87)->insertKey(2);
	LEOHtable->print();
	cout << "Search key 87: " << LEOHtable->searchKey(87) << endl;
	cout << "Delete key: 44" << endl;
	LEOHtable->deleteKey(44);
	LEOHtable->print();
	cout << "Delete key: 77 " << endl;
	LEOHtable->deleteKey(77);
	LEOHtable->print();
	cout << "Delete key: 44 " << endl;
	LEOHtable->deleteKey(44);
	LEOHtable->print();
	cout << "Delete key and insert: 87 " << endl;
	LEOHtable->deleteKey(87);
	LEOHtable->insertKey(87);
	LEOHtable->print();
	cout << "Insert key: 77 and 22" << endl;
	LEOHtable->insertKey(77)->insertKey(22);
	LEOHtable->print();
	cout << "Key 44: " << LEOHtable->searchKey(44) << endl;

	cout << "Non-standard Version of Quadratic Probing" << endl;
	QuadraticDeleteShiftOpenHashTable<int>* QEOHtable = new QuadraticDeleteShiftOpenHashTable<int>(11);
	QEOHtable->insertKey(4)->insertKey(44)->insertKey(33)->insertKey(77)->insertKey(87)->insertKey(50)->insertKey(2);
	QEOHtable->print();
	cout << "Search key 87: " << QEOHtable->searchKey(87) << endl;
	cout << "Delete key: 4" << endl;
	QEOHtable->deleteKey(4);
	QEOHtable->print();
	cout << "Delete key: 77 " << endl;
	QEOHtable->deleteKey(77);
	QEOHtable->print();
	cout << "Delete key: 44 " << endl;
	QEOHtable->deleteKey(44);
	QEOHtable->print();
	cout << "Delete key: 2 " << endl;
	QEOHtable->deleteKey(2);
	QEOHtable->print();
	cout << "Insert key: 77 " << endl;
	QEOHtable->insertKey(77)->insertKey(22);
	QEOHtable->print();
	cout << "Key 44: " << QEOHtable->searchKey(44) << endl;
	cout << "Delete 77: " << endl;
	QEOHtable->deleteKey(77);
	QEOHtable->print();
	cout << "Delete 87: " << endl;
	QEOHtable->deleteKey(87);
	QEOHtable->print();
	return 0;
}