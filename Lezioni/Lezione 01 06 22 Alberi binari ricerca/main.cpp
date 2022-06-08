#include "BST.h"
using namespace std;

int main()
{
    BST<int> bst;   

    // bst.max();

    try{
        bst.max();
    }
    catch (const char* ex){
        cout << ex << endl;
    }
    bst.insert(40);
    bst.insert(25);
    bst.insert(21);
    bst.insert(18);
    bst.insert(57);
    bst.insert(36);
    bst.insert(46);
    bst.insert(32);
    bst.insert(78);
    bst.insert(52);
    bst.insert(11);
    bst.insert(44);


    bst.inOrder(); //visita in ordine dell'albero

    cout << "bst.search(11) = " << (bst.search(11) ? "found" : "not found") << endl;

    cout << "bst.search(20)= " << (bst.search(20) ? "found" : "not found") << endl << endl;

    cout << "Min: " << *(bst.min()) << endl;
    cout << "Max: " << *(bst.max()) << endl << endl;

    cout << "Successore di root: " << *(bst.successor(bst.getRoot()));

    cout << "\n\n";
    BSTNode<int>* cancellato1 = bst.remove(11);
    cout << "Rimozione 11" << endl;
    bst.inOrder();
    
    BSTNode<int>* cancellato2 = bst.remove(21);
    cout << "Rimozione 21" << endl;
    bst.inOrder();
    BSTNode<int>* cancellato3 = bst.remove(40);
    cout << "Rimozione 40" << endl;
    bst.inOrder();
}