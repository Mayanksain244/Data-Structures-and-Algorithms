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


    BSTree(){
        root = nullptr;
    }

};

int main(){
    BSTree a;
    a.insert(60);
    a.insert(15);
    a.insert(25);
    a.insert(20);
    a.insert(70);
    a.insert(80);
    a.insert(100);
    a.insert(90);
    std::cout<< a.height() <<std::endl;
}