#include "bst.h"

int main(){
    BST<int> bst;

    bst.insert(70);
    bst.insert(53);
    bst.insert(101);
    bst.insert(90);
    bst.insert(120);
    bst.insert(40);
    bst.insert(45);
    bst.insert(34);
    bst.insert(54);

    bst.in_order();

    //test minimo

    cout << "Il minimo dell'albero e' "<< *(bst.min());

    //test successore
    cout << endl << "Il successore di 54 e' " << *(bst.successore(bst.search(54)));
    cout << endl << "Il successore di 70 e' " << *(bst.successore(bst.search(70)));


    //test distanza
    cout << endl << "La distanza da 54 e il suo successore e' " << bst.distanza_successore(54);

    //test distanza con un albero degenerato
    BST<int> bst2;

    bst2.insert(100);
    bst2.insert(70);
    bst2.insert(74);
    bst2.insert(78);
    bst2.insert(87);
    bst2.insert(97);

    cout << endl << "La distanza da 97,nel secondo albero, e il suo successore e' " << bst2.distanza_successore(97);
}