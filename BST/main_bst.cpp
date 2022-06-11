#include "bst.h"


int main(){
    BST<int> bst;

    // bst.insert(10);
    bst.insert(4);
    bst.insert(16);
    bst.insert(12);
    bst.insert(18);
    bst.insert(14);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    //test inOrder()
    bst.inOrder();

    cout << endl << endl;
    //test postOrder()
    bst.postOrder();

    //test minimo
    cout << "MINIMO=" << *(bst.min()) << endl;

    //test massimo
    cout << "MASSIMO=" << *(bst.max()) << endl;

    //test search
    cout << "search(69)=" << (bst.search(69) ? "Trovato" : "Non trovato") << endl;
    cout << "search(2)=" << (bst.search(2) ? "Trovato" : "Non trovato") << endl;

    //test successore con accesso al nodo tramite search
    cout << "Il successore di 7 e'" << *(bst.successor(bst.search(7))) << endl;

    //test predecessore con accesso al nodo tramite search
    cout << "Il predecessore di 12 e'" << *(bst.predecessor(bst.search(12))) << endl;


}