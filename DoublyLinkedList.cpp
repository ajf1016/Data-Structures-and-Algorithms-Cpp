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

    void addNode(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
        cout << "Node " << data << " added";
        cout << "\n";
    }

    void display()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        while (temp != nullptr)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayReverse()
    {

        Node *temp = tail;
        if (tail == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        while (temp != nullptr)
        {
            cout << temp->data << ", ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    void deleteNode(int data)
    {
        Node *temp = head, *prev;
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        else if (temp != nullptr && temp->data == data)
        {
            head = temp->next;
            cout << data << " deleted\n";
            return;
        }

        while (temp != nullptr && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;

        if (temp == tail)
        {
            tail = prev;
            tail->next = nullptr;
            cout << data << " deleted\n";
            return;
        }

        cout << data << " deleted\n";
    }

    void insertAfter(int nextTo, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "List is empty..!" << data << " added to first position\n";
            head = newNode;
            tail = newNode;
            return;
        }

        while (temp != nullptr && temp->data != nextTo)
        {
            temp = temp->next;
        }

        if (tail->data == nextTo)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
        else
        {

            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void insertBtw(int nextTo, int beforeTo, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "List is empty..!" << data << " added to first position\n";
            head = newNode;
            tail = newNode;
            return;
        }

        while (temp != nullptr && temp->data != nextTo && temp->next->data != beforeTo)
        {
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteRepeatedNodes()
    {
        Node *current = head;
        while(current != nullptr){
            Node *next = current->next;
            while(next != nullptr && next->data == current->data){
                next = next->next;
            }
            current->next = next;
            if(next == tail){
                tail = current;
            }
            current = next;
        }
        
    }
};

int main()
{
    cout << "Hello Doubly..\n";
    DoublyLinkedList list;
    // list.display();
    // list.addNode(1);
    // list.addNode(2);
    // list.addNode(3);
    // list.addNode(4);
    // list.addNode(5);
    // list.display();
    // list.insertAfter(4, 40);
    // list.insertBtw(4,5,34);
    // list.display();
    // list.displayReverse();
    list.addNode(1);
    list.addNode(1);
    list.addNode(3);
    list.addNode(3);
    list.addNode(3);
    list.addNode(4);
    list.addNode(4);
    list.display();
    list.deleteRepeatedNodes();
    list.display();
    return 0;
}