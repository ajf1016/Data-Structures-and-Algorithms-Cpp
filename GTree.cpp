#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    TreeNode* findNode(TreeNode* node, int parentData) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data == parentData) {
            return node;
        }

        TreeNode* child = findNode(node->firstChild, parentData);
        if (child != nullptr) {
            return child;
        }

        return findNode(node->nextSibling, parentData);
    }

    void insertRec(TreeNode* parent, int key) {
        TreeNode* newNode = new TreeNode(key);
        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        } else {
            TreeNode* child = parent->firstChild;
            while (child->nextSibling != nullptr) {
                child = child->nextSibling;
            }
            child->nextSibling = newNode;
        }
    }

    void traverseRec(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " -> ";
        traverseRec(node->firstChild);
        traverseRec(node->nextSibling);
    }

public:
    Tree(int rootData) : root(new TreeNode(rootData)) {}

    void insert(int parentData, int key) {
        TreeNode* parentNode = findNode(root, parentData);
        if (parentNode != nullptr) {
            insertRec(parentNode, key);
        }
    }

    void traverse() {
        std::cout << "Tree Traversal: ";
        traverseRec(root);
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    Tree tree(1);

    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(2, 4);
    tree.insert(2, 5);
    tree.insert(3, 6);

    tree.traverse();

    return 0;
}
