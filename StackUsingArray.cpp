#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100;

class Stack{
public:
    int data[MAX_CAPACITY];
    int topIndex;

    Stack(){
        topIndex = -1;
    }

bool isEmpty() const {
        return topIndex == -1;
    }
    void push(int item){
        if(topIndex >= MAX_CAPACITY - 1){
            cout<<"Stack overflow..\n";
            return;
        }

        data[++topIndex] = item;

    }
    void pop(int &item){
        if(isEmpty()){
            cout<<"Stack underflow..\n";
            return;
        }

        item = data[--topIndex];
        data[topIndex + 1] = -1;
    }

    

    void display(){
        for(int i = 0;i<=topIndex;i++){
            cout<<data[i]<<"\n";
        }
        cout<<"\n";
    }
};
int main(){
    cout<<"Hello world..\n";
Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s1.display();
    return 0;
}