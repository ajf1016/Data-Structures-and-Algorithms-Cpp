#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *previous;
	node(int data){
		this->data = data;
		next = nullptr;
		previous = nullptr;
	}
}*head = nullptr,*tail = nullptr,*temp = nullptr;

void insertNode(int data){
	node *newNode = new node(data);

	if(head == nullptr){
		head = newNode;
	}else{
		tail->next = newNode;
		newNode->previous = tail;
		newNode->next = nullptr;
	}
	tail = newNode;
}

void deleteNode(int data){
	if(head->data == data){
		head = head->next;
		return;
	}

	temp = head;
	while(temp != nullptr && temp->data != data){
		// temp->previous->next = temp;
		temp = temp->next;
	}

	if(temp == tail){
		tail = temp->previous;
		tail->next = nullptr;
		return;

	}

	temp->previous->next = temp->next;
	delete temp;
}

void deleteAllNode(int data){
	if(head == nullptr){
		cout<<"List is already empty..\n";
		return;
	}

	temp = head;
	while(temp != nullptr){
		if(temp->data == data){
			if(temp->previous != nullptr){
				temp->previous->next = temp->next;
			}else{
				head = temp->next;
			}

			if(temp->next != nullptr){
				temp->next->previous = temp->previous;
			}else{
				tail = temp->previous;
			}
		}
		temp = temp->next;
	}
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
	insertNode(2);
	insertNode(2);
	insertNode(2);
	insertNode(3);
	insertNode(3);
	insertNode(3);
	insertNode(3);
	insertNode(4);
	insertNode(3);
	insertNode(3);
	insertNode(4);
	displayList();
	// deleteNode(4);
	deleteAllNode(2);
	displayList();


	return 0;
}