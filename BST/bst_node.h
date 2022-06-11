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

        template<typename U>
        friend class BST;


    public:
        BSTNode(T key) : key(key){
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
            os << "BSTNode@=" << &node << " key=" << node.key;
            os << " left=" << node.left << " right=" << node.right;
            os << " parent=" << node.parent;

            return os;
        }




};

#endif