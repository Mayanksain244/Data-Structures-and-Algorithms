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
        length++;
        
        
    }

    void replace(int num, int index){
        if(index >= length || index < 0){
            std::cout << "index out of bound" << std::endl;
            return; 
        }

        int indexCounter = (index < (length)/2)?0:length-1;
        Node* iterator = (index < (length)/2)?head:tail;

        std::cout << "iterator = "<< iterator->value << std::endl;

        if(index < int((length)/2)){
            while (iterator->next!=nullptr)
            {
                std::cout << "current index = " << indexCounter <<std::endl;
                std::cout << "iter val = " << iterator->value << std::endl;

                if(indexCounter == index){
                    break;
                }
                iterator = iterator->next;
                indexCounter++;
            }
        }
        else{
            while (iterator->prev!=nullptr)
            {
                std::cout << "current index = " << indexCounter <<std::endl;
                std::cout << "iter val = " << iterator->value << std::endl;

                if(indexCounter == index){
                    break;
                }
                iterator = iterator->prev;
                indexCounter--;
            }
        }

        // which ever node is close will go to replace the value

        iterator->value = num;
    }

    void delEnd(){
        
        tail = tail->prev;
        tail->next->prev = nullptr;

        delete tail->next;

        tail->next = nullptr;

        length--;

    }




    

    void delFront(){

        head = head->next;
        head->prev->next = nullptr;
        
        delete head->prev;

        head->prev = nullptr;

        length--;

    }

    void del(int index){

        if (index == 0)
        {
            delFront();
        }
        else if (index == length - 1)
        {
            delEnd();
        }
        else if (index >= length)
        {
            std::cout << "index out of bound" << std::endl;
        }
        else{
            int indexCounter = (index < (length)/2)?0:length-1;
            Node* iterator = (index < (length)/2)?head:tail;

            // std::cout << "iterator = "<< iterator->value << std::endl;

            if(index < int((length)/2)){
                while (iterator->next!=nullptr)
                {
                    // std::cout << "current index = " << indexCounter <<std::endl;
                    // std::cout << "iter val = " << iterator->value << std::endl;

                    if(indexCounter == index){
                        break;
                    }
                    iterator = iterator->next;
                    indexCounter++;
                }
            }
            else{
                while (iterator->prev!=nullptr)
                {
                    // std::cout << "current index = " << indexCounter <<std::endl;
                    // std::cout << "iter val = " << iterator->value << std::endl;

                    if(indexCounter == index){
                        break;
                    }
                    iterator = iterator->prev;
                    indexCounter--;
                }
            }

            iterator->prev->next = iterator->next;
            iterator->next->prev = iterator->prev;
            delete iterator; 
            length--;
            
        }

    } 





    int getItem(int index)
    {

        Node *iterator = head;

        int indexCounter = 0;
        while (head != nullptr)
        {
            if (indexCounter == index)
            {
                int val = head->value;

                head = iterator;

                return val;
            }

            head = head->next;
            indexCounter++;
        }

        std::cerr << "Error: Index out of range" << std::endl;

        return -1;

    }

    int operator[](int i){

        return getItem(i);
    
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


// main()
// {
//     DoubleLinkedList list(1);
//     list.addNodeEnd(2);
//     list.addNodeEnd(3);
//     list.addNodeEnd(4);
//     list.addNodeEnd(5);
//     list.addNodeFront(0);
//     list.insert(100,2);
//     list.replace(999,7);

//     list.Print();
//     list.delEnd();
//     list.Print();
//     list.delFront();
//     list.Print();
//     list.del(4);
//     list.Print();
//     list.PrintRev();



//     std::cout << list.Length() << std::endl;
//     std::cout << "----------------------------------------------------------------" << std::endl;
//     std::cout << list[4];
// }