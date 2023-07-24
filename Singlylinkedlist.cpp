#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class SLinkedList
{
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
        }
        tail = newNode;
        cout<<data<<" added\n";
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is Empty..!!";
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    void deleteNode(int data)
    {
        Node *temp = head, *prev = nullptr;
        if (temp != nullptr && temp->data == data)
        {
            head = temp->next;
            delete temp;
            cout<<data<<" deleted\n";
            return;
        }

        while (temp != nullptr && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            return;
        }

        if(temp == tail){
            tail = prev;
            tail->next = nullptr;
            cout<<data<<" deleted\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout<<data<<" deleted\n";
    }
};

int main()
{
    cout << "Hello world";
    SLinkedList list;
    list.display();
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.addNode(7);
    list.display();
    list.deleteNode(1);
    list.display();
    return 0;
}