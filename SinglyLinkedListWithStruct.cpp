#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *start = NULL, *nn,*temp;

void insertBegin(int data)
{
    nn = new node;
    nn->data = data;

    if(start == NULL){
        start = nn;
    }else{
        nn->next = start;
        start = nn;
    }
}

void printList(){
    if(start == nullptr){
        cout<<"List is empty..!\n";
        return;
    }
    temp = start;

    while(temp != nullptr){
        cout<<temp->data<<", ";
        temp = temp->next;
    }
}

void insertEnd(int data){
    nn = new node;
    nn->data = data;

    if(start == nullptr){
        start = nn;
        return;
    }
    
    temp = start;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nn;
}



int main()
{
    insertEnd(100);
    insertEnd(105);
    printList();

    return 0;
}