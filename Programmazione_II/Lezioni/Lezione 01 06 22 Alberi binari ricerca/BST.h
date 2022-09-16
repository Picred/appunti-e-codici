#ifndef BST_H
#define BST_H
#include <iostream>
#include "bst_node.h"

using namespace std;

template<typename T>
class BST {
    private:
        BSTNode<T>* root; //radice

    public:
        BST() {
            root = nullptr;
        }

        //implementiamo i metodi
        bool isEmpty() {
            return root == nullptr; //se la radice è nulla, l'albero è vuoto
        }

        BSTNode<T>* getRoot() {
            return this->root;
        }

        void insert(T key) {
            if (this->isEmpty()) {
                root = new BSTNode<T>(key); //creo un nuovo nodo sulla radice
                return;
            }

            insert(root, key);
        }

        void insert(BSTNode<T>* ptr, T key) {
            if (ptr == nullptr) { //caso base 
                ptr = new BSTNode<T>(key);
                return;
            }

            if (ptr->left == nullptr && key <= ptr->key) {
                ptr->left = new BSTNode<T>(key);
                ptr->left->setParent(ptr);
                return;
            }


            if (ptr->right == nullptr && key > ptr->key) {
                ptr->right = new BSTNode<T>(key);
                ptr->right->setParent(ptr);
                return;
            }

            else if (key <= ptr->key) {
                insert(ptr->left, key);
            }
            else {
                insert(ptr->right, key);
            }
        }

        void visit(BSTNode<T>* node) {
            cout << *node << endl;
        }

        void inOrder(BSTNode<T>* ptr) {
            if (ptr == nullptr)
                return;

            inOrder(ptr->left);
            visit(ptr);
            inOrder(ptr->right);
        }

        void inOrder() {
            inOrder(root);
        }

        BSTNode<T>* min() {
            return min(root);
        }

        BSTNode<T>* min(BSTNode<T>* from) {
            if (isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* ptr = from;
            while (ptr->left) {
                ptr = ptr->left;
            }
            return ptr;
        }

        BSTNode<T>* max() {
            return max(root);
        }

        BSTNode<T>* max(BSTNode<T>* from) {
            if (isEmpty()) {
                throw "Empty BST!";
            }

            BSTNode<T>* ptr = from;
            while (ptr->right) {
                ptr = ptr->right;
            }
            return ptr;
        }

        BSTNode<T>* successor(BSTNode<T>* x) {
            if (this->isEmpty()) {
                return nullptr;
            }

            // I caso: x ha un sottoalbero dx
            if (x->right) {
                return this->min(x->right);
            }
            else {
                return nullptr;
            }

            // II caso: x non ha sottoalbero dx
            // il successore di x è l'antenato piu prossimo di x il cui figlio sinistro è anche antenato di x

            BSTNode<T>* y = x->parent;

            while (x != nullptr && x == y->right) {
                x = y;
                y = y->parent;
            }

            return y;
        }

        BSTNode<T>* predecessor(BSTNode<T>* x) {
            if (this->isEmpty()) {
                return nullptr;
            }

            //I caso: x ha un sottoalbero sx
            if (x->left) {
                return this->max(x->left);
            }

            //II caso: x non ha un sottoalbero sx

            BSTNode<T>* y = x->parent;
            while (x != nullptr && x == y->left) {
                x = y;
                y = y->parent;
            }

            return y;
        }

        BSTNode<T>* search(T key) {
            return search(root, key);
        }

        //ricerca di un nodo data una chiave
        BSTNode<T>* search(BSTNode<T>* ptr, T key) {
            if (ptr == nullptr) {
                return nullptr;
            }
            if (ptr->key == key) {
                return ptr;
            }

            if (key <= ptr->key) { //dicotomica
                return search(ptr->left, key);
            }
            else {
                return search(ptr->right, key);
            }

            return nullptr;
        }

        // implementiamo la cancellazione 08 06 22
        BSTNode<T>* remove(T key) {
            if (this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* node = search(key); //vado a trovare il nodo che devo eliminare

            if (node == nullptr) {
                return nullptr; //se il nodo non è stato trovato
            }
            //se il nodo è stato trovato

            BSTNode<T>* toDelete = this->remove(node);
            if (toDelete != nullptr) { //il nodo da rimuovere era una foglia oppure aveva un figlio
                return toDelete;
            }

            //caso 3: nodo da eliminare ha 2 figli, non serve un altro if perchè è l'unica opzione rimasta
            //sostituisco la chiave nel nodo da eliminare con la chiave del suo successore
            BSTNode<T>* next = this->successor(node);
            //sostituzione della chiave
            T swap = node->key;
            node->key = next->key;
            next->key = swap;
            //devo eliminare next. Come?
            //fare una funzione che gestisce separatamente i primi 2 casi e la funzione che 
            //richiamo prenderà come parametro un BSTNode<T>* 
            //richiamo la procedura di cancellazione dei primi 2 casi sul successore del nodo da eliminare
            toDelete = this->remove(next);

            return toDelete;

        }

        BSTNode<T>* remove(BSTNode<T>* node) {
            //qui facciamo il caso 1 e il caso 2
            //caso 1 nodo è una foglia
            if (node->left == nullptr && node->right == nullptr) {
                if (node == node->parent->left)
                    node->parent->left = nullptr;
                else if (node == node->parent->right)
                    node->parent->right = nullptr;

                return node;
            }

            //caso 2 nodo ha 1 figlio

            if (node->left == nullptr && node->right != nullptr) { //il nodo da eliminare ha un figlio destro
                node->right->parent = node->parent;

                if (node == node->parent->left) { //se node è figlio sinistro
                    // node->right->parent = node->parent; //parent del figlio destro è il parent del nodo da eliminare 
                    // spostato fuori dall'if perchè indipendente 
                    node->parent->left = node->right; //56:15
                }
                else if (node == node->parent->right) {//se node è figlio destro
                    node->parent->right = node->right;
                }
                return node;
            }
            //il nodo da eliminare ha un figlio sinistro
            if (node->left != nullptr && node->right == nullptr) {
                node->left->parent = node->parent;
                //il nodo da eliminare è un figlio sx
                if (node == node->parent->left) {
                    node->parent->left = node->left;
                }
                //il nodo da eliminare è un figlio dx
                else if (node == node->parent->right) {
                    node->parent->right = node->left;
                }
                return node;
            }
            return nullptr;
        }

        //IMPLEMENTAZIONE DI POSTORDER
        void postOrder() {
            postOrder(root);
        }

        void postOrder(BSTNode<T>* ptr) {
            if (ptr == nullptr)
                return;

            postOrder(ptr->left);
            postOrder(ptr->right);
            visit(ptr);
        }

        //PREORDER
        void preOrder() {
            preOrder(root);
        }

        void preOrder(BSTNode<T>* ptr) {
            if (ptr == nullptr) {
                return;
            }

            visit(ptr);
            preOrder(ptr->left);
            preOrder(ptr->right);
        }
};


#endif