#include "BST.h"
using namespace std;

int main()
{
    BST<int> bst;

    bst.insert(10);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    bst.insert(2);
    bst.insert(5);
    bst.insert(9);
    bst.insert(3);

    bst.inOrder(); //visita in ordine dell'albero

    cout << "bst.search(9)" << (bst.search(9) ? "found" : "not found") << endl;

    cout << "bst.search(20)" << (bst.search(20) ? "found" : "not found") << endl;

    cout << "Min: " << *(bst.min()) << endl;
    cout << "Max: " << *(bst.max()) << endl;

    cout << "Successore di root: " << *(bst.successor(bst.getRoot()));
}