#include <iostream>
using namespace std;

class Queue
{
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

public:
    Node *front = nullptr;
    Node *rear = nullptr;

    void display()
    {
        Node *current = front;
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << ", ";
            current = current->next;
        }
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);

        if (rear == nullptr)
        {
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout<<data<<" added\n";
    }
    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
    }
};

int main()
{
    cout << "Hello Wolrd..!!\n";
    Queue q;
    q.display();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}