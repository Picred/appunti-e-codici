#ifndef BST_H
#define BST_H

#include "bst_node.h"

template <class T>
class BST{
    private:
        BSTNode<T>* root;
        int distanza=0;
    public:
        BST(){
            this->root=nullptr;
        }

        bool isEmpty(){ //se l'albero e' vuoto, la radice è nullptr
            return root==nullptr;
        }

        void insert(T key){
            if(this->isEmpty()){
                root=new BSTNode<T>(key);
                return;
            }

            insert(root,key); //l'albero non è vuoto
        }

        void insert(BSTNode<T>* ptr, T key){
            //caso base
            if(ptr==nullptr){
                ptr=new BSTNode<T>(key);
                return;
            }

            //caso base, il nodo non ha un figlio sinistro
            if(ptr->left==nullptr && key<=ptr->key){
                ptr->left=new BSTNode<T>(key);
                ptr->left->parent=ptr;
                return;
            }

            //caso base, il nodo non ha un figlio destro
            if(ptr->right==nullptr && key>=ptr->key){
                ptr->right=new BSTNode<T>(key);
                ptr->right->parent=ptr;
            }

            //passo ricorsivo, scorrimento dell'albero
            else if(key<=ptr->key){
                insert(ptr->left,key);
            }
            else {
                insert(ptr->right,key);
            }
        }

        void visit(BSTNode<T>* ptr){
            cout << *ptr << endl;
        }

        void in_order(){
            in_order(root);
        }

        void in_order(BSTNode<T>* ptr){
            if(ptr==nullptr){
                return;
            }
            in_order(ptr->left);
            visit (ptr);
            in_order(ptr->right);
        }

        BSTNode<T>* successore(BSTNode<T>* x){
            if(this->isEmpty()){
                return nullptr;
            }

            this->distanza=1;

            if(x->right){
                return min(x->right);
            }
            
            BSTNode<T>* y = x->parent;

            while(y!=nullptr && x==y->right){
                x=y;
                y=y->parent;
                this->distanza++; //ho percorso un arco
            }

            return y;
        }

        BSTNode<T>* min(){
            return min(root);
        }

        BSTNode<T>* min(BSTNode<T>* from){
            if(this->isEmpty()){
                return nullptr;
            }

            BSTNode<T>* ptr = from;

            while(ptr->left){
                ptr=ptr->left;
                this->distanza++;
            }

            return ptr;
        }

        BSTNode<T>* search(T key){
            return search(root,key);
        }

        BSTNode<T>* search(BSTNode<T>* ptr, T key){
            if(ptr==nullptr){
                return nullptr;
            }

            //caso base
            if(ptr->key==key){
                return ptr;
            }

            //passi ricorsivi
            if(key<=ptr->key){
                return search(ptr->left,key);
            }

            if(key>=ptr->key){
                return search(ptr->right,key);
            }

            //caso nodo non trovato
            return nullptr;
        }

        int distanza_successore(T X){
            BSTNode<T>* ptr = this->search(X);

            //elemento non trovato nell'albero
            if(ptr==nullptr){
                return 0;
            }

            // successore dell'elemento non esiste
            if(!successore(ptr)){
                return 0;
            }

            return distanza;

        }
};

#endif