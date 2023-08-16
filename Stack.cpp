#include <iostream>
using namespace std;

class Stack
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
    Node *top = nullptr;

    void display()
    {
        Node *current = top;
        if (top == nullptr)
        {
            cout << "Stack is Empty...!\n";
            return;
        }

        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        cout << data << " Node added\n";
    }

    
};

int main()
{
    cout << "Hello World..!\n";
    Stack st;
    st.display();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.display();
    return 0;
}