#include <iostream>
using namespace std;

class DoublyLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data)
        {
            this->data = data;
        }
    };

public:
    Node *head = nullptr;
    Node *tail = nullptr;

    void addNode(int data){
        Node *newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
    }
};

int main()
{
    cout << "Hello Doubly..\n";
    return 0;
}