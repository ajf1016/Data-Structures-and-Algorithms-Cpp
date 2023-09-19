#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
	node(int data){
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
}*head = nullptr,*tail = nullptr,*temp = nullptr;

void insertNode(int data){
	node *newNode = new node(data);

	if(head == nullptr){
		head = newNode;
	}else{
		tail->next = newNode;
		newNode->prev = tail;
		newNode->next = nullptr;
	}
	tail = newNode;
}


void displayList(){
	if(head == nullptr){
		cout<<"List is empty..\n";
		return;
	}
	temp = head;
	while(temp != nullptr){
		cout<<temp->data<<", ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(){
	cout<<"Hell world..\n";
	displayList();
	insertNode(1);
	insertNode(2);
	insertNode(3);
	insertNode(4);
	displayList();


	return 0;
}