#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
using namespace std;

template<class T>
class BSTNode{
    private:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;

        template <class U>
        friend class BST;
    public:
        BSTNode(T key) : key(key){
            this->left=nullptr;
            this->right=nullptr;
            this->parent=nullptr;
        }

        friend ostream& operator<< (ostream& os,BSTNode<T>& node){
            os << "Node@ = " << &node << " Node key = " << node.key;
            os << " Left = " << node.left << " Right = " << node.right << " Parent = " << node.parent;

            return os;
        }
};

#endif