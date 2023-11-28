#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int data) : key(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insertRec(root->left, key);
        } else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }

        return root;
    }

    void inorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderRec(root->left);
        cout << root->key << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->key << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->key << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorderTraversal() {
        inorderRec(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorderRec(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorderRec(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    cout << "Preorder Traversal: ";
    bst.preorderTraversal();

    cout << "Postorder Traversal: ";
    bst.postorderTraversal();

    return 0;
}
