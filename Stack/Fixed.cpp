#include<iostream>
#include "SLinkedList.h"

class Stack{
private:
    int length = 0; 
    int maxLen = 0;
public:
    Node* top;
    SingleLinkedList* list;
    Stack(int size){
        this->maxLen = size;
    }
    
    void push(int num){
        if(length == maxLen){
            std::cout << "Overflow" << std::endl;   
        }
        else if(length==0){
            list = new SingleLinkedList(num);
            std::cout <<list->Length()<< std::endl;
            length++;
        }
        else{
            list->addNodeFront(num);
            list->Print();
            this->length++;
        }
    }

    

    int pop(){
        if(length == 0){
            std::cout << "under flow" << std::endl;
            return -1;
        }
        else if(length == 1){
            int val = list->head->value;
            delete list;
            length--;
            std::cout << val << std::endl;
            return val;
        }
        else{
            int val = list->head->value;
            list->delFront();
            length--;
            std::cout << val << std::endl;
            return val;
        }
        
    }

    void peek(){
        if(length == 0){
            std::cout << "under flow" << std::endl;
            return;
        }else{
            std::cout << list->head->value << std::endl;
        }
    }

    bool isEmpty(){
        if(length == 0){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(length == maxLen){
            return true;
        }else{
            return false;
        }
    }
    
};

int main(){
    Stack a(5);
    a.push(20);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    a.push(20);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
    a.peek();
}