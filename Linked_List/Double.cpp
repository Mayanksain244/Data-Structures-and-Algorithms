#include <iostream>

class Node
{
public:
    Node *prev;
    int value;
    Node *next;

    Node()
    {
        this->prev = nullptr;
        this->value = 0;
        this->next = nullptr;
    }

    Node(int num)
    {
        this->prev = nullptr;
        this->value = num;
        this->next = nullptr;
    }

    Node(Node *pre, int num, Node *nxt)
    {
        this->prev = pre;
        this->value = num;
        this->next = nxt;
    }
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int length = 0;
public:
    DoubleLinkedList(){
        head = new Node();
        tail = head;
        length++;
    }

    DoubleLinkedList(int num){
        head = new Node(num);
        tail = head;
        length++;
    }

    int Length(){
        return length;
    }

    void addNodeEnd(int num){

        tail->next = new Node(tail , num , nullptr);
        tail = tail->next;

        length++;

    }

    void addNodeFront(int num){

        head->prev = new Node(nullptr , num , head);
        head = head->prev;
        length++;

    }

    void insert(int num, int index){
        if(index == 0){
            addNodeFront(num);
        }
        else if (index == length)
        {
            addNodeEnd(num);
        }
        else if (index > length)
        {
            std::cout << "index out of bound" << std::endl;
        }
        else{


            Node *iterHead = head;
            Node *iterTail = tail;

            int indexCounter = 0;
            while (iterHead->next != nullptr)
            {
                if(indexCounter == index-1){
                    break;
                } //going to the previous node before the index
                iterHead = iterHead->next;
                indexCounter++;
            }

            while (iterTail->prev != iterHead)
            {
                iterTail = iterTail->prev;
            }

            iterHead->next = new Node(iterHead,num,iterTail);
            iterTail->prev = iterHead->next;
            
            
        }
        
        
    }




    

    void replace(int num, int index){

    }




    


    void delEnd(){

    }




    

    void delFront(){

    }




    

    void del(int index){

    }




    

    void Print(){
        Node* iterator = head;
        while (iterator != nullptr)
        {
            std::cout << iterator->value << " ";
            iterator = iterator->next;

        }
        std::cout << std::endl;

        // std::cout << "head = " << head->value << std::endl;
        // std::cout << "tail = " << tail->value << std::endl;

    }

    void PrintRev(){
        
        Node* iterator = tail;
        while (iterator != nullptr)
        {
            std::cout << iterator->value << " ";
            iterator = iterator->prev;

        }
        std::cout << std::endl;
    }


};


main()
{
    DoubleLinkedList list(1);
    list.addNodeEnd(2);
    list.addNodeEnd(3);
    list.addNodeEnd(4);
    list.addNodeEnd(5);
    list.addNodeFront(0);
    list.insert(100,2);

    list.Print();
    list.PrintRev();
    std::cout << list.Length();
}