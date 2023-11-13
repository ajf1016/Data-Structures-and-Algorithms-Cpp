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

     void insertAtFirst(int data){
         Node *newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail= newNode;
            return;

        }
        newNode->next = head;
        head = newNode;
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

    void duplicateAll(){
        Node *temp = head;
        if(temp == nullptr){
            cout<<"List is Empty..\n";
            return;
        }
        
        while(temp != nullptr){
            Node *current = temp;
            while(current->next != nullptr){
                if(current->next->data == temp->data){
                    current->next = current->next->next;
                }else{
                    current = current->next;
                }
            }
            temp = temp->next;
        }
    }

    void deleteAllNodes(int data){
        Node *temp = head, *prev = nullptr;
        
        if(temp == nullptr){
            cout<<"List is Empty..\n";
            return;
        }

        while(temp != nullptr){
            if(temp->data == data){
                if(temp == head){
                    head  = temp->next;
                    delete temp;
                    temp = head;
                }else{
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
    }

    void sort(){
         if (head == nullptr) {
             cout<<"List is empty..\n";
            return;
        }
        
        bool swapped;
        Node *temp;
        
        do{
            swapped = false;
            temp = head;
            
            while(temp->next != nullptr){
                if(temp -> data > temp->next->data){
                    int tempData = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tempData;
                    swapped = true;
                }
                temp = temp->next;
            }
        }while(swapped);
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
    list.displayReverse();
    return 0;
}