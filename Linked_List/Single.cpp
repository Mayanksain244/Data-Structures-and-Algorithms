/*
this is what all i have added yet

- add at end
- add at front
- insert at index ("out of bound")

-replace at index

- delete from end

things i will add

- delete from front
- delete from index

- get item (operator overloading)

*/


#include <iostream>

class Node
{
public:
    int value;
    Node* next;

    Node() {
        this->value = 0;
        this->next = nullptr;
    }

    Node(int num) {
        this->value = num;
        this->next = nullptr;
    }

    Node(int num, Node* nxt) {
        this->value = num;
        this->next = nxt;
    }
};

class LinkedList {
private:
    Node* head;
    int length = 0;
public:

    LinkedList() {
        head = new Node();
        length++;
    }

    LinkedList(int num) {
        head = new Node(num);
        length++;
    }

    int Length() {
        return length;
    }

    void addNodeEnd(int num) {

        Node* iterator = head;

        while (head->next != nullptr)
        {
            // std::cout << head->value << std::endl;
            head = head->next;
        }

        head->next = new Node(num);

        head = iterator;


        length++;
        // std::cout << head->next->next->value << std::endl;
    }

    void addNodeFront(int num) {

        Node* iterator = new Node(num, head);
        head = iterator;

        length++;
    }

    void insert(int num, int index) {

        if (index == 0) {
            addNodeFront(num);
        }
        else if (index == length) {
            addNodeEnd(num);
        }
        else if (index > length) {
            std::cout << "index out of bound" << std::endl;
        }
        else {

            Node* iterator = head;

            int indexCounter = 0;
            while (head->next != nullptr)
            {
                if (indexCounter == index - 1) {
                    break;
                }
                indexCounter++;
                head = head->next;
            }

            Node* temp = head->next;
            head->next = new Node(num, temp);

            head = iterator;

            length++;

        }
    }

    void replace(int num , int index){
         if(index >= length){
             std::cout << "index of of bound" << std::endl;
             return;
         }

         int indexCounter = 0;

         Node* iterator = head;
         while (head->next != nullptr)
         {
             if(indexCounter == index){
                 break;
             }

             head = head->next;
             indexCounter++;
         }

         head->value = num;

         head = iterator;

     }




    void delEnd(){
        
    }



    void Print() {
        Node* iterator = head;

        while (head != nullptr)
        {
            std::cout << head->value;
            std::cout << " ";
            head = head->next;
        }
        std::cout << std::endl;

        head = iterator;
    }
};


int main() {
    LinkedList list(1);
    list.addNodeEnd(2);
    list.insert(50, 2);
    list.addNodeEnd(10);
    list.replace(69,2);
    list.Print();
    // list.replace(69,2);
    list.Print();

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << list.Length();
}