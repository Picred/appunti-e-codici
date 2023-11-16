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
            if(ptr->left==nullptr && key->getArea()<= ptr->key->getArea()){
                ptr->left=new BSTNode<T>(key);
                ptr->left->setParent(ptr);
                return;
            }
            //caso base. non ha un figlio destro
            if(ptr->right==nullptr && key->getArea()>ptr->key->getArea()){
                ptr->right=new BSTNode<T>(key);
                ptr->right->parent=ptr;
                return;
            }
            //ha almeno un figlio
            else if(key->getArea()<=ptr->key->getArea()){
                insert(ptr->left,key);
            } 
            else{
                insert(ptr->right,key);
            }
        }

        void visit(BSTNode<T>* node){
            cout << *node << endl;
        }
        
        //INORDER
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

        //POSTORDER
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

        //PREORDER
        void preOrder(){
            preOrder(root);
        }

        void preOrder(BSTNode<T>* ptr){
            if(ptr==nullptr){
                return;
            }

            visit(ptr);
            preOrder(ptr->left);
            preOrder(ptr->right);
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

            if(ptr->key->getArea()==key->getArea()){
                return ptr;
            }

            if(key->getArea()<=ptr->key->getArea())
                return search(ptr->left,key);
            
            if(key->getArea()>ptr->key->getArea()){
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

        BSTNode<T>* remove(T key) {
            if (this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* node = search(key); //vado a trovare il nodo che devo eliminare

            if (node == nullptr) {
                return nullptr; //il nodo non è stato trovato
            }
            //il nodo è stato trovato
            BSTNode<T>* toDelete = this->remove(node);
            if (toDelete != nullptr) { //il nodo da rimuovere era una foglia oppure aveva un figlio
                return toDelete;
            }

            //caso 3: nodo da eliminare ha 2 figli, non serve un altro if perchè è l'unica opzione rimasta
            //sostituisco la chiave nel nodo da eliminare con la chiave del suo successore
            BSTNode<T>* next = this->successor(node);
            //sostituzione della chiave(swap)
            T swap = node->key;
            node->key = next->key;
            next->key = swap;
    //devo eliminare next, cioè il successore del nodo "da eliminare". Come?
    //fare una funzione che gestisce separatamente i primi 2 casi e la funzione che 
    //richiamo prenderà come parametro un BSTNode<T>* 
    //richiamo la procedura di cancellazione dei primi 2 casi sul successore del nodo da eliminare visto che non ho più il caso 2 figli
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
                    node->parent->left = node->right;
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


        void remove_area(double area){
            return remove_area(root,area);
        }

        void remove_area(BSTNode<T>* ptr, double area){
            if(!ptr){
                return;
            }

            remove_area(ptr->right,area);
            cancel(ptr,area);
            remove_area(ptr->left,area);
        }


        void cancel(BSTNode<T>* ptr,double area){
            if(ptr->key->getArea()<=area){
                remove(ptr->key);
            }
        }
        
};



#endif