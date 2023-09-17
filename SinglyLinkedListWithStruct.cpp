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

void deleteNode(int data){
   if(start == nullptr){
        cout<<"List is empty..\n";
        return;
   }
   if(start->data == data){
        start = start->next;
        return;
   }
   temp = start;
   node *previous = temp;
   while(temp != nullptr && temp->data != data){
        previous = temp;
        temp = temp->next;
   }

   if(temp == tail){
        tail = previous;
        tail->next = nullptr;
        delete temp;
        return;
   }
   previous->next = temp->next;
   delete temp;
   temp = previous;
}

void reverse(node *current){
    if(current == nullptr){
        return;
    }
    reverse(current->next);
    cout<<current->data<<",";
}
void displayReverse(){
    cout<<"Singly Linked list in reverse order..\n";
    reverse(start);
}



int main()
{
    insertEnd(100);
    insertEnd(105);
    printList();

    return 0;
}