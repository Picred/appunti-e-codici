#ifndef BST_H
#define BST_H

#include "bst_node.h"

template<typename T>
class BST{
    private:
        BSTNode<T>* root;
    public:
        BST(){
            root=nullptr;
        }

        BSTNode<T>* getRoot(){
            return this->root;
        }

        //Albero vuoto?
        bool isEmpty(){
            return root==nullptr;
        }

        //inserimento di un nodo
        void insert(T key){
            if(this->isEmpty()){
                root= new BSTNode<T>(key);
                return;
            }
            insert(root,key);
        }
        //overload insert
        void insert(BSTNode<T>* ptr, T key){
            if(ptr==nullptr){
                ptr=new BSTNode<T>(key);
                return;
            }

            //caso base. Non ha un figlio sinistro 
            if(ptr->left==nullptr && key<= ptr->key){
                ptr->left=new BSTNode<T>(key);
                ptr->left->setParent(ptr);
                return;
            }
            //caso base. non ha un figlio destro
            if(ptr->right==nullptr && key>ptr->key){
                ptr->right=new BSTNode<T>(key);
                ptr->right->parent=ptr;
                return;
            }
            //ha almeno un figlio
            else if(key<=ptr->key){
                insert(ptr->left,key);
            } 
            else{
                insert(ptr->right,key);
            }
        }

        //INORDER
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

        //IMPLEMENTAZIONE DI POSTORDER
        void postOrder(){
            postOrder(root);
        }

        void postOrder(BSTNode<T>* ptr) {
            if (ptr == nullptr)
                return;

            postOrder(ptr->left);
            postOrder(ptr->right);
            visit(ptr);   
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

            while(ptr->right)
                ptr=ptr->right;

            return ptr;
        }

        BSTNode<T>* search(T key){
            return search(root,key);
        }

        BSTNode<T>* search(BSTNode<T>* ptr,T key){
            if(ptr==nullptr){
                return nullptr;
            }

            if(ptr->key==key){
                return ptr;
            }

            if(key<=ptr->key)
                return search(ptr->left,key);
            
            if(key>ptr->key){
                return search(ptr->right,key);
            }

            return nullptr;
        }

        BSTNode<T>* successor(BSTNode<T>* x){
            if(isEmpty()){
                return nullptr;
            }

            if(x->right){
                return this->min(x->right);
            }

            BSTNode<T>* y=x->parent;

            while (x!=nullptr && x==y->right){
                x=y;
                y=y->parent;
            }
            return y;
        }

        BSTNode<T>* predecessor(BSTNode<T>* x){
            if(isEmpty()){
                return nullptr;
            }
            
            if(x->left){
                return this->max(x->left);
            }

            BSTNode<T>* y=x->parent;

            while(x!=nullptr && x==y->left){
                x=y;
                y=y->parent;
            }

            return y;
        }

};



#endif