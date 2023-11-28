#include <iostream>
using namespace std;

class Stack{
    class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = nullptr;
        }
    };
public:
    Node *top;
    Stack(){
        top = nullptr;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    void push(int val){

        Node *nn = new Node(val);

        nn->next = top;
        top = nn;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack underflow..\n";
            return;
        }

        Node *t = top;
        top = top->next;
        free(t);
    }

    void display(){
        Node *t = top;
        if(isEmpty()){
            return;
        }
        while(t != nullptr){
            cout<<t->data<<", ";
            t = t->next;
        }
        cout<<"\n";
    }
};



int main(){
    cout<<"Hello world..\n";
    Stack s1;
    s1.push(1);
    s1.push(2);s1.push(3);s1.push(4);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}