#ifndef BST_H
#define BST_H
#include <iostream>
#include "bst_node.h"

using namespace std;

template<typename T>
class BST{
    private:
        BSTNode<T>* root; //radice

    public:
        BST(){
            root=nullptr;
        }

    //implementiamo i metodi
    bool isEmpty(){
        return root==nullptr; //se la radice è nulla, l'albero è vuoto
    }

    BSTNode<T>* getRoot(){
        return this->root;
    }

    void insert(T key){
        if(this->isEmpty()){
            root=new BSTNode<T>(key); //creo un nuovo nodo sulla radice
            return;
        }

        insert(root,key);
    }

    void insert(BSTNode<T>* ptr, T key){
        if(ptr==nullptr){ //caso base 
            ptr=new BSTNode<T>(key);
            return;
        }
        
        if(ptr->left==nullptr && key<= ptr->key){
            ptr->left = new BSTNode<T>(key);
            ptr->left->setParent(ptr);
            return;
        }
        
        
        if(ptr->right == nullptr && key>ptr->key){ 
            ptr->right = new BSTNode<T>(key);
            ptr->right->setParent(ptr);
            return;
        }

        else if (key<=ptr->key){
            insert(ptr->left,key);
        }
        else{
            insert(ptr->right,key);
        }
    }

    void visit(BSTNode<T>* node){
        cout << *node << endl;
    }

    void inOrder(BSTNode<T>* ptr){
        if(ptr==nullptr)
            return;

        inOrder(ptr->left);
        visit(ptr);
        inOrder(ptr->right);
    }

    void inOrder(){
        inOrder(root);
    }

    BSTNode<T>* min(){
        return min(root);
    }

    BSTNode<T>* min(BSTNode<T>* from){
        if(isEmpty()){
            return nullptr;
        }

        BSTNode<T>* ptr = from;
        while(ptr->left){
            ptr=ptr->left;
        }
        return ptr;
    }

    BSTNode<T>* max(){
        return max(root);
    }

    BSTNode<T>* max(BSTNode<T>* from){
        if(isEmpty()){
            return nullptr;
        }

        BSTNode<T>* ptr = from;
            while(ptr->right){
                ptr=ptr->right;
            }
        return ptr;
    }

    BSTNode<T>* successor(BSTNode<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }

        // I caso: x ha un sottoalbero dx
        if(x->right){
            return this->min(x->right);
        }
        else{
            return nullptr;
        }

        // II caso: x non ha sottoalbero dx
        // il successore di x è l'antenato piu prossimo di x il cui figlio sinistro è anche antenato di x

        BSTNode<T>* y = x->parent;

            while(x!=nullptr && x==y->right){
                x=y;
                y=y->parent;
            }

            return y;
    }

    BSTNode<T>* predecessor(BSTNode<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }

        //I caso: x ha un sottoalbero sx
        if(x->left){
            return this->max(x->left);
        }

        //II caso: x non ha un sottoalbero sx

        BSTNode<T>* y = x->parent;
            while(x!=nullptr && x==y->left){
                x=y;
                y=y->parent;
            }

            return y;
    }

    BSTNode<T>* search(T key){
        return search(root,key);
    }

    //ricerca di un nodo data una chiave
    BSTNode<T>* search(BSTNode<T>* ptr, T key){
        if(ptr==nullptr){
            return nullptr;
        }
        if(ptr->key==key){
            return ptr;
        }

        if(key<=ptr->key){ //dicotomica
            return search(ptr->left,key);
        }
        else{
            return search(ptr->right,key);
        }

        return nullptr;
    }
    
};


#endif