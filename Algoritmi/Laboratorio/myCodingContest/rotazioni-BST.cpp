#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;

template <typename T>
class BSTNode{
protected:
    T key;
    BSTNode<T> *left;
    BSTNode<T> *right;
    BSTNode<T> *parent;
    bool verbose = false;

    template <typename U>
    friend class BST;

public:
    BSTNode(T key, bool verbose = true) : key(key), verbose(verbose){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    void setLeft(BSTNode<T> *left){
        this->left = left;
    }

    void setRight(BSTNode<T> *right){
        this->right = right;
    }

    void setParent(BSTNode<T> *parent){
        this->parent = parent;
    }

    BSTNode<T> *getLeft(){
        return this->left;
    }

    BSTNode<T> *getRight(){
        return this->right;
    }

    BSTNode<T> *getParent(){
        return this->parent;
    }

    void setKey(T key){
        this->key = key;
    }

    T getKey(){
        return this->key;
    }

    friend ostream& operator<<(ostream &out, BSTNode<T> &node){
        out << node.key;
        return out;
    }
};

template <typename T>
class BST{
    BSTNode<T> *root;
    stringstream s;

public:
    BST(){
        root = nullptr;
        s.str("");
    }

    BSTNode<T> *search(T key){
        return search(root, key);
    }

    BSTNode<T> *search(BSTNode<T> *ptr, T key){
        if (ptr == nullptr)
            return nullptr;

        if (ptr->key == key)
            return ptr;

        if (key <= ptr->key)
            return search(ptr->left, key);
        else
            return search(ptr->right, key);

        return nullptr;
    }
    void clear(){
        root = nullptr;
    }
    void preorder(BSTNode<T> *ptr){
        if (ptr == nullptr)
            return;

        visit(ptr);
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void inorder(BSTNode<T> *ptr){
        if (ptr == nullptr)
            return;

        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }

    void postorder(BSTNode<T> *ptr){
        if (ptr == nullptr)
            return;

        postorder(ptr->left);
        postorder(ptr->right);
        visit(ptr);
    }

    BSTNode<T> *successor(){
        return successor(root);
    }

    void inorder(){
        inorder(root);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    bool isEmpty(){
        return root == nullptr;
    }

    BSTNode<T> *getRoot(){
        return this->root;
    }

    void insert(T key){
        if (this->isEmpty()){
            root = new BSTNode<T>(key);
            return;
        }
        insert(root, key);
    }

    void insert(BSTNode<T> *ptr, T key){
        if (ptr->left == nullptr && key <= ptr->key){
            ptr->left = new BSTNode<T>(key);
            ptr->left->setParent(ptr);
            return;
        }
        if (ptr->right == nullptr && key > ptr->key){
            ptr->right = new BSTNode<T>(key);
            ptr->right->parent = ptr;
            return;
        }
        else if (key <= ptr->key)
            insert(ptr->left, key);
        else
            insert(ptr->right, key);
    }

    void visit(BSTNode<T> *node){
        s << *node << " ";
    }

    BSTNode<T> *max(){
        return max(root);
    }

    BSTNode<T> *max(BSTNode<T> *from){
        if (isEmpty())
            return NULL;

        BSTNode<T> *ptr = from;
        while (ptr->right)
            ptr = ptr->right;

        return ptr;
    }

    BSTNode<T> *min(){
        return min(root);
    }

    BSTNode<T> *min(BSTNode<T> *from){
        if (isEmpty())
            return NULL;

        BSTNode<T> *ptr = from;
        while (ptr->left){
            ptr = ptr->left;
        }

        return ptr;
    }

    BSTNode<T> *successor(BSTNode<T> *x){
        if (this->isEmpty()){
            return nullptr;
        }

        if (x->right)
            return this->min(x->right);

        BSTNode<T> *y = x->parent;

        while (y != nullptr && x == y->right){
            x = y;
            y = y->parent;
        }

        return y;
    }

    BSTNode<T> *remove(BSTNode<T> *ptr){
        // CASO 1
        if (ptr == root && !(ptr->left) && !(ptr->right)){
            root = nullptr;
            return ptr;
        }

        if (!(ptr->left) && !(ptr->right)){
            if (ptr == ptr->parent->left){
                ptr->parent->left = nullptr;
                return ptr;
            }
            else{
                ptr->parent->right = nullptr;
                return ptr;
            }
        }

        // CASO 2
        if (ptr == root && ptr->left && !(ptr->right)){
            ptr->left->parent = nullptr;
            root = ptr->left;
            return ptr;
        }

        if (ptr == root && !(ptr->left) && ptr->right){
            ptr->right->parent = nullptr;
            root = ptr->right;
            return ptr;
        }

        if (ptr->left && !(ptr->right)){
            ptr->left->parent = ptr->parent;
            if (ptr == ptr->parent->left){
                ptr->parent->left = ptr->left;
                return ptr;
            }
            else{
                ptr->parent->right = ptr->left;
                return ptr;
            }
        }

        if (!(ptr->left) && ptr->right){
            ptr->right->parent = ptr->parent;
            if (ptr == ptr->parent->left){
                ptr->parent->left = ptr->right;
                return ptr;
            }
            else{
                ptr->parent->right = ptr->right;
                return ptr;
            }
        }

        return nullptr;
    }

    BSTNode<T> *remove(T key){
        if (this->isEmpty())
            return nullptr;

        BSTNode<T> *toDelete = search(key);

        if (!toDelete)
            return nullptr;

        BSTNode<T> *toRemove = remove(toDelete);
        if (toRemove)
            return toRemove;

        BSTNode<T> *next = successor(toDelete);
        T swap = toDelete->key;
        toDelete->key = next->key;
        next->key = swap;

        toRemove = remove(next);
        return toRemove;
    }

    void leftRotate(T key){
        BSTNode<T> *x = search(key);

        if (!x || x->right == nullptr)
            return;

        BSTNode<T> *y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(T key){
        BSTNode<T> *x = search(key);

        if (!x || x->left == nullptr)
            return;

        BSTNode<T> *y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
            y->right->parent = x;

        y->parent = x->parent;

        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    string print(){
        return s.str();
    }
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type, visit, str;
    int m = 0; // Numero di operazioni di rotazione
    int n = 0; // Numero di elementi da inserire o cancllare dal BST

    int int_value = 0;
    double double_value = 0.0;

    for (int x = 0; x < 100; x++){
        in >> type >> n >> m >> visit;

        if (type == "int"){
            BST<int> *BST_int = new BST<int>;

            for (int i = 0; i < n; i++){
                in >> str;

                if (str[0] == 'i'){ // Inserimento
                    int_value = stoi(str.substr(4, str.length()));
                    BST_int->insert(int_value);
                }
                else if (str[0] == 'c'){ // Cancellazione
                    int_value = stoi(str.substr(5, str.length()));
                    BST_int->remove(int_value);
                }
            }

            for (int i = 0; i < m; i++){
                in >> str;

                if (str[0] == 'l'){ // Rotazione a sinistra
                    int_value = stoi(str.substr(5, str.length()));
                    BST_int->leftRotate(int_value);
                }
                else if (str[0] == 'r'){// Rotazione a destra
                    int_value = stoi(str.substr(6, str.length()));
                    BST_int->rightRotate(int_value);
                }
            }

            if (visit == "inorder")
                BST_int->inorder();

            if (visit == "preorder")
                BST_int->preorder();

            if (visit == "postorder")
                BST_int->postorder();

            out << BST_int->print() << endl;
        }

        if (type == "double"){
            BST<double> *BST_double = new BST<double>;

            for (int i = 0; i < n; i++){
                in >> str;

                if (str[0] == 'i'){ // Inserimento
                    double_value = stod(str.substr(4, str.length()));
                    BST_double->insert(double_value);
                }
                else if (str[0] == 'c'){ // Cancellazione
                    double_value = stod(str.substr(5, str.length()));
                    BST_double->remove(double_value);
                }
            }

            for (int i = 0; i < m; i++){
                in >> str;

                if (str[0] == 'l'){ // Rotazione a sinistra
                    double_value = stod(str.substr(5, str.length()));
                    BST_double->leftRotate(double_value);
                }
                else if (str[0] == 'r') // Rotazione a destra
                {
                    double_value = stod(str.substr(6, str.length()));
                    BST_double->rightRotate(double_value);
                }
            }

            if (visit == "inorder")
                BST_double->inorder();

            if (visit == "preorder")
                BST_double->preorder();

            if (visit == "postorder")
                BST_double->postorder();

            out << BST_double->print() << endl;
        }
    }
}