#include <iostream>
using namespace std;

class Stack{
    class Node{
        int data;
        Node* next;

        Node(int data){
            this->data = data;
        }
    };

    Node *top = nullptr;

    void display(){
        Node *current = top;
        if(current != nullptr){
            cout<<"Stack is Empty...!";
        }
    }
};

int main(){
    cout<<"Hello World..!";
    return 0;
}