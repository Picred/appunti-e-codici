#include "bst.h"


int main(){
    BST<int> bst;

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

    cout << "----------INORDER TEST----------"<<endl;
    //test inOrder()
    bst.inOrder();

    cout << endl << endl;
    //test postOrder()
    cout << "----------POSTORDER TEST----------"<<endl;
    bst.postOrder();
    
    cout << endl << endl;
    //test preOrder()
    cout << "----------PREORDER TEST----------"<<endl;
    bst.preOrder();

    cout << endl << endl;
    //test minimo
    cout << "----------MINIMO TEST----------"<<endl;
    cout << "MINIMO=" << *(bst.min()) << endl;

    cout << endl << endl;
    //test massimo
    cout << "----------MASSIMO TEST----------"<<endl;
    cout << "MASSIMO=" << *(bst.max()) << endl;

    cout << endl << endl;
    //test search
    cout << "----------SEARCH TEST----------"<<endl;
    cout << "search(69)=" << (bst.search(69) ? "Trovato" : "Non trovato") << endl;
    cout << "search(2)=" << (bst.search(2) ? "Trovato" : "Non trovato") << endl;

    cout << endl << endl;
    //test successore con accesso al nodo tramite search
    cout << "----------SUCCESSORE TEST----------"<<endl;
    cout << "Il successore di 7 e'" << *(bst.successor(bst.search(7))) << endl;

    cout << endl << endl;
    //test predecessore con accesso al nodo tramite search
    cout << "----------PREDECESSORE TEST----------"<<endl;
    cout << "Il predecessore di 12 e'" << *(bst.predecessor(bst.search(12))) << endl;


}