#include <iostream>
using namespace std;

const int MAX_CAP = 100;
class Stack{
public:
    int data[MAX_CAP];
    int topIndex;

    Stack(){
        topIndex = -1;
    }

    int size(){
        return topIndex;
    }

    bool isFull(){
        return MAX_CAP - 1 == topIndex;
    } 

    bool isEmpty(){
        return topIndex == -1;
    }

    void push(int val){
        if(isFull()){
            cout<<"Stack overflow..\n";
            return;
        }
        data[++topIndex] = val;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow.." << std::endl;
            return -1; // Return a sentinel value to indicate an error
        }
        return data[topIndex--];
    }

    void display(){
        for(int i = 0;i<topIndex+1;i++){
            cout<<data[i]<<"\n";
        }
    }
};


int main(){
    cout<<"Hello world..\n";
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}