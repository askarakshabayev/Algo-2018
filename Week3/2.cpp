#include <iostream>

using namespace std;

class Node {
    public:
    int key;
    Node *left;
    Node *right;
    Node(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

class Tree {
    public:
    Node *root;
    Tree() {
        root = NULL;
    }
    
    Node* insert(Node *node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return node;
        }
        else if (node->key >= key) {
            node->left = insert(node->left, key);
        }
        else {
            node->right = insert(node->right, key);
        }
        return node;
    }
};

int main() {
    Tree *tree = new Tree();
    int k;
    for (int i = 0; i < 11; i++) {
        cin >> k;
        tree->root = tree->insert(tree->root, k);
    }
    cout << tree->root->left->right->key;
    return 0;
}