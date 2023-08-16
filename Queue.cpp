#include <iostream>
using namespace std;

class Queue{
    class Node{
        public:
            int data;
            Node *next;

            Node(int dta){
                this->data = data;
            }
    };

    Node *front = nullptr;
    Node *rear = nullptr;

    void display(){
        Node *current = front;
        if(current==nullptr){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        while(current!=nullptr){
            cout<<current->data<<", ";
            current = current->next;
        }
    }
};

int main(){
    cout<<"Hello Wolrd..!!\n";
    return 0;
}