#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* findNode(TreeNode* node, int parentData) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data == parentData) {
            return node;
        }

        TreeNode* leftChild = findNode(node->left, parentData);
        if (leftChild != nullptr) {
            return leftChild;
        }

        return findNode(node->right, parentData);
    }

    void insertRec(TreeNode* parent, int key) {
        if (parent->left == nullptr) {
            parent->left = new TreeNode(key);
        } else if (parent->right == nullptr) {
            parent->right = new TreeNode(key);
        } else {
            // If both children are already occupied, insert recursively to the left subtree.
            insertRec(parent->left, key);
        }
    }

    void traverseRec(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " -> ";
        traverseRec(node->left);
        traverseRec(node->right);
    }

public:
    BinaryTree(int rootData) : root(new TreeNode(rootData)) {}

    void insert(int parentData, int key) {
        TreeNode* parentNode = findNode(root, parentData);
        if (parentNode != nullptr) {
            insertRec(parentNode, key);
        }
    }

    void traverse() {
        std::cout << "Binary Tree Traversal: ";
        traverseRec(root);
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    BinaryTree binaryTree(1);

    binaryTree.insert(1, 2);
    binaryTree.insert(1, 3);
    binaryTree.insert(2, 4);
    binaryTree.insert(2, 5);
    binaryTree.insert(3, 6);

    binaryTree.traverse();

    return 0;
}
