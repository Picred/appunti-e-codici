#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

using namespace std;

template <typename T> 
class BSTNode {
    private:
        T key; //valore 
        BSTNode<T>* left; //figlio sinistro
        BSTNode<T>* right; //figlio destro
        BSTNode<T>* parent; //genitore del nodo

        template <typename U>
        friend class BST; //futura classe dell'albero per poter accedere ai campi privati di questa classe

    public:
        BSTNode(T key) : key(key){
            left=nullptr;
            right=nullptr;
            parent=nullptr;
        }

        void setLeft(BSTNode<T>* left){
            this->left=left;
        }

        void setRight(BSTNode<T>* right){
            this->right=right;
        }

        BSTNode<T>* getLeft(){
            return this->left;
        }

        BSTNode<T>* getRight(){
            return this->right;
        }

        void setParent(BSTNode<T>* parent){
            this->parent=parent;
        }

        BSTNode<T>* getParent(){
            return this->parent;
        }

        void setKey(T key){
            this->key=key;
        }

        T getKey(){
            return this->key;
        }

        friend ostream& operator<<(ostream& out, BSTNode<T>& node){
            out << "BSTNode@=" << &node << " key=" << node.key << " left=" << node.left << " right=" << node.right << " parent=" << node.parent;
            return out;  
        }
        
        
        // //aggiungo il distruttore in piu rispetto alle liste,code ecc..
        // //quando distruggo un nodo, distruggo l'albero quindi non mi interessano più i sottoalberi dx e sx
        // ~BSTNode(){
        //     delete left;
        //     delete right;
        // }
        //l'ho commentato perchè lo implementeremo in modo diverso perchè i puntatori dovrebbero esesre allocati in modo statico quindi non si possono deletare
};

#endif