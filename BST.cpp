#include <iostream>

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
        std::cout << root->key << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->key << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        postorderRec(root->left);
        postorderRec(root->right);
        std::cout << root->key << " ";
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void inorderTraversal() {
        inorderRec(root);
        std::cout << std::endl;
    }

    void preorderTraversal() {
        preorderRec(root);
        std::cout << std::endl;
    }

    void postorderTraversal() {
        postorderRec(root);
        std::cout << std::endl;
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

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    std::cout << "Preorder Traversal: ";
    bst.preorderTraversal();

    std::cout << "Postorder Traversal: ";
    bst.postorderTraversal();

    return 0;
}
