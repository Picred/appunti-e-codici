#include "bst.h"

int main(){
    BST<int> bst_interi;
    BST<char> bst_char;

    bst_interi.insert(70);
    bst_interi.insert(53);
    bst_interi.insert(101);
    bst_interi.insert(90);
    bst_interi.insert(120);
    bst_interi.insert(40);
    bst_interi.insert(45);
    bst_interi.insert(34);
    bst_interi.insert(54);

    bst_char.insert('n');
    bst_char.insert('p');
    bst_char.insert('h');
    bst_char.insert('c');
    bst_char.insert('g');
    bst_char.insert('i');
    bst_char.insert('q');
    bst_char.insert('o');
    bst_char.insert('j');
    bst_char.insert('k');

    bst_interi.in_order();
    cout << endl;
    bst_char.in_order();
    cout << endl;

    //Test minimo
    cout << "Il minimo dell'albero di interi e' "<< *(bst_interi.min()) << endl;
    cout << "Il minimo dell'albero di char e' "<< *(bst_char.min()) << endl;

    //Test successore + search
    cout << "Il successore di 45 e' " << *(bst_interi.successore(bst_interi.search(45))) << endl;
    cout << "Il successore di j e' " << *(bst_char.successore(bst_char.search('j'))) << endl;

    //Test distanza successore bst di interi
        if(bst_interi.distanza_successore(54)==0){
            cout << "Non esiste il successore di 54" <<endl;
        }
        else{
            cout << "Distanza da 54->successore(54): " << bst_interi.distanza_successore(54) << endl;
        }

    //test distanza successore bst di char
        if(bst_char.distanza_successore('k')==0){
            cout << "Non esiste il successore di k" <<endl;
        }
        else{
            cout << "Distanza da k->successore(k): " << bst_char.distanza_successore('k') << endl;
        }

}