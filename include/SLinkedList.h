#ifndef S_LINKEDLIST
#define S_LINKEDLIST

#include<iostream>

class Node
{
public:
    int value;
    Node *next;

    Node()
    {
        this->value = 0;
        this->next = nullptr;
    }

    Node(int num)
    {
        this->value = num;
        this->next = nullptr;
    }

    Node(int num, Node *nxt)
    {
        this->value = num;
        this->next = nxt;
    }
};

class SingleLinkedList
{
private:
    int length = 0;

public:
    Node *head;
    
    SingleLinkedList()
    {
        head = new Node();
        length++;
    }

    SingleLinkedList(int num)
    {
        head = new Node(num);
        length++;
    }

    int Length()
    {
        return length;
    }

    void addNodeEnd(int num)
    {

        Node *iterator = head;

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

    void addNodeFront(int num)
    {

        Node *iterator = new Node(num, head);
        head = iterator;

        length++;
    }

    void insert(int num, int index)
    {

        if (index == 0)
        {
            addNodeFront(num);
        }
        else if (index == length)
        {
            addNodeEnd(num);
        }
        else if (index > length)
        {
            // std::cout << "index out of bound" << std::endl;
        }
        else
        {

            Node *iterator = head;

            int indexCounter = 0;
            while (head->next != nullptr)
            {
                if (indexCounter == index - 1)
                {
                    break;
                }
                indexCounter++;
                head = head->next;
            }

            Node *temp = head->next;
            head->next = new Node(num, temp);

            head = iterator;

            length++;
        }
    }

    void replace(int num, int index)
    {
        if (index >= length || index < 0)
        {
            // std::cout << "index of of bound" << std::endl;
            return;
        }

        int indexCounter = 0;

        Node *iterator = head;
        while (head->next != nullptr)
        {
            if (indexCounter == index)
            {
                break;
            }

            head = head->next;
            indexCounter++;
        }

        head->value = num;

        head = iterator;
    }

    void delEnd()
    {

        Node *iterator = head;
        while (head->next->next != nullptr)
        {
            head = head->next;
        }

        delete head->next;
        head->next = nullptr;

        head = iterator;
        length--;
    }

    void delFront()
    {
        Node *temp = head;

        head = head->next;
        delete temp;

        length--;
    }

    void del(int index)
    {

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
            // std::cout << "index out of bound" << std::endl;
        }
        else
        {
            Node *iterator = head;

            int indexCounter = 0;
            while (head->next->next != nullptr)
            {
                if (indexCounter >= index - 1)
                {
                    break;
                }
                indexCounter++;
                head = head->next;
            }

            Node *temp = head->next;

            head->next = head->next->next;

            delete temp;

            head = iterator;
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

        // std::cerr << "Error: Index out of range" << std::endl;

        return -1;

    }

    int operator[](int i){

        return getItem(i);
    
    }

    void Print()
    {
        Node *iterator = head;

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

#endif