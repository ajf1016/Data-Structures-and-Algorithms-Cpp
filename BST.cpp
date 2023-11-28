#include <iostream>
using namespace std;

class BST{
    class Node{
    public:
        int data;
        Node *left,*right;

        Node(int data){
            this->data = data;
            left = nullptr;
            right = nullptr;
        }
    };
    public:
        Node *root;
        BST(){
            root = nullptr;
        }

        void insert(int data){
            Node *currentNode = root;
            if(currentNode == nullptr){
                root = new Node(data);
                return;
            }

            while(true){
                if(data < currentNode->data){
                    if(currentNode->left == nullptr){
                        currentNode->left = new Node(data);
                        break;
                    }else{
                        currentNode = currentNode->left;
                    }
                }else{
                    if(currentNode->right == nullptr){
                        currentNode->right = new Node(data);
                        break;
                    }else{
                        currentNode = currentNode->right;
                    }
                }
            }
        };

        bool contain(int data){
            Node *currentNode = root;

            while(currentNode != nullptr){
                if(data < currentNode->data){
                    currentNode = currentNode->left;
                }else if(data > currentNode->data){
                    currentNode = currentNode->right;
                }else{
                    return true;
                }
            }
            return false;
        }

        void inOrder(){
            cout<<"IN ORDER : ";
            inOrderHelper(root);
            cout<<"\n";
        };
        void preOrder(){
            cout<<"PRE ORDER : ";
            preOrderHelper(root);
            cout<<"\n";
        };
        void postOrder(){
            cout<<"POST ORDER : ";
            postOrderHelper(root);
            cout<<"\n";
        };

        void inOrderHelper(Node *current){
            if(current != nullptr){
                inOrderHelper(current->left);
                cout<<current->data<<", ";
                inOrderHelper(current->right);
            }
        };
        void preOrderHelper(Node *current){
            cout<<current->data<<", ";
            inOrderHelper(current->left);
            inOrderHelper(current->right);
        };
        void postOrderHelper(Node *current){
            inOrderHelper(current->left);
            inOrderHelper(current->right);
            cout<<current->data<<", ";
        };
};


int main(){
    cout<<"Hello world..\n";
    BST t;
    t.insert(40);
    t.insert(30);
    t.insert(50);
    t.insert(25);
    t.insert(35);
    t.insert(45);
    t.insert(60);
    // cout<<t.contain(600)<<"HEllo";
    t.inOrder();
    t.preOrder();
    t.postOrder();
    return 0;
}