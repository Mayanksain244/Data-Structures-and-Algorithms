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

    }

//     void peek(){

//     }

//     bool isEmpty(){
        
//     }

//     bool isFull(){

//     }
};

int main(){
    Stack a(5);
    a.push(20);
    a.push(20);
    a.push(30);
}