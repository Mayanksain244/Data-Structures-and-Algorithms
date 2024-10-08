#include <iostream>

class BSTree{

public:
    class Node{
    public:
        Node* left;
        int data;
        Node* right;

        Node()
        :left(nullptr),
        right(nullptr)
        {}

        Node(int data)
        :left(nullptr),
        right(nullptr),
        data(data)
        {}
    };

    Node* root;

    void insert(int data){
        this->root = _insertData(this->root,data);
    }

    int height(){
        return _getHeight(this->root);
    }

    void inOrder(){
        _inOrderTraversal(this->root);
        std::cout<<std::endl;
    }

    bool searchKey(int key){
        return _searchKey(this->root,key);
    }

    void Delete(int key){
        root = _Delete(root ,key);
    }


    // void insertData2(Node *node, int data){
    //     if(node == nullptr){
    //         node = new Node(data);
    //     }
    //     else if(data > node->data){                                 memorry leak error (segmentation fault cuz the pointer is lost)
    //         insertData(node->right,data);
    //     }
    //     else if(data < node->data){
    //         insertData(node->left,data);
    //     }
    // }

    Node* _insertData(Node *root, int data){
        if(root == nullptr){
            root = new Node(data);
        }
        else if(data > root->data){
            root->right = _insertData(root->right,data);
        }
        else if(data < root->data){
            root->left = _insertData(root->left,data);
        }
        return root;
    }

    int _getHeight(Node* root){
        if(root == nullptr){
            return 0;
        }
        int lh = _getHeight(root->left)+1;
        int rh = _getHeight(root->right)+1;
        return std::max(lh , rh);
    }

    void _inOrderTraversal(Node* root){
        if(root != nullptr){
            _inOrderTraversal(root->left);
            std::cout<<root->data<<" ";
            _inOrderTraversal(root->right);
        }
    }

    bool _searchKey(Node* root , int key){
        if(root == nullptr){
            return false;
        }
        if(key == root->data){
            return true;
        }
        else if(key > root->data ){
            return _searchKey(root->right,key);
        }
        else if(key < root->data){
            return _searchKey(root->left,key);
        }
        return false;
    }

    Node* _Delete(Node* root ,int key){
        if(root == nullptr) {
            return nullptr;
        }
        else{
            // find the element
            if(key < root->data){
                root->left = _Delete(root->left,key);
            }
            else if(key > root->data){
                root->right = _Delete(root->right,key);
            }
            else{
                // key is found and not remove it
            }

        }
    }


    BSTree(){
        root = nullptr;
    }

};

int main(){
    BSTree a;
    a.insert(8);
    a.insert(4);
    a.insert(2);
    a.insert(6);
    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(7);
    a.insert(12);
    a.insert(10);
    a.insert(9);
    a.insert(11);
    a.insert(14);
    a.insert(13);
    a.insert(15);
    std::cout<< a.height() <<std::endl;

    a.inOrder();
    std::cout<<a.searchKey(101);
}