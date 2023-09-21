#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end of the circular linked list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            head->next = head; // Point to itself to form a loop
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Point back to the head to form the loop
        }
    }

    // Function to display the elements in the circular linked list
    void display() {
        if (head == nullptr) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }
        
        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

    // Function to delete a node by its value
    void deleteNode(int val) {
        if (head == nullptr) {
            std::cout << "Circular Linked List is empty. Cannot delete." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == val) {
                if (current == head) {
                    Node* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        std::cout << "Value " << val << " not found in the Circular Linked List." << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(1);
    cll.insert(2);
    cll.insert(3);

    std::cout << "Circular Linked List: ";
    cll.display(); // Output: 1 2 3

    cll.deleteNode(2); // Delete node with value 2

    std::cout << "Circular Linked List after deleting 2: ";
    cll.display(); // Output: 1 3

    return 0;
}