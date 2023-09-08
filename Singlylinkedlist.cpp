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
        cout << data << " added\n";
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
            cout << data << " deleted\n";
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

        if (temp == tail)
        {
            tail = prev;
            tail->next = nullptr;
            cout << data << " deleted\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << data << " deleted\n";
    }

    void insertNode(int nextTo, int data)
    {
        Node *newNode = new Node(data);
        Node *temp = head;

        while (temp != nullptr && temp->data != nextTo)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            return;
        }

        if (temp == tail)
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeDuplicateNode()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            while (next != nullptr && next->data == current->data)
            {
                next = next->next;
            }

            current->next = next;
            if (next == tail && current->data == next->data)
            {
                tail = current;
                tail->next = nullptr;
            }
            current = next;
        }
    }

    void displayReverse(Node* current) {
        if (current == nullptr) {
            return;
        }

        displayReverse(current->next);
        cout << current->data << "\n";
    }

    void displayReverse() {
        cout << "Linked list in reverse order:\n";
        displayReverse(head);
    }
};

int main()
{
    cout << "Hello world";
    SLinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(3);
    list.addNode(3);
    list.addNode(4);
    list.addNode(3);
    list.addNode(3);
    list.addNode(6);
    list.addNode(7);
    list.display();
    list.deleteNode(3);
    list.display();
    return 0;
}