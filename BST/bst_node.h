#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class BSTNode{
    private:
        T key;
        BSTNode<T>* right;
        BSTNode<T>* left;
        BSTNode<T>* parent;
        bool verbose = false;

        template<typename U>
        friend class BST;


    public:
        BSTNode(T key, bool verbose=false) : key(key), verbose(verbose){
            right=nullptr;
            left=nullptr;
            parent=nullptr;
        }

        //setter

        void setLeft(BSTNode<T>* left){
            this->left=left;
        }

        void setRight(BSTNode<T>* right){
            this->right=right;
        }

        void setParent(BSTNode<T>* parent){
            this->parent=parent;
        }

        void setKey(T key){
            this->key=key;
        }

        void setVerbose(bool x){
            this->verbose=x;
        }

        //getter


        BSTNode<T>* getLeft(){
            return this->left;
        }

        BSTNode<T>* getRight(){
            return this->right;
        }

        BSTNode<T>* getParent(){
            return this->parent;
        }

        T getKey(){
            return this->key;
        }

        friend ostream& operator<<(ostream& os, BSTNode<T>& node){
            if(node.verbose)
                os << "BSTNode@=" << &node << " key=" << node.key << " left=" << node.left << " right=" << node.right << " parent=" << node.parent;
            else
                os << "BSTNode key=" << node.key;
            return os;
        }




};

#endif