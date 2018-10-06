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

class BSTree {
    public:
    Node *root;
    BSTree() {
        root = NULL;
    }

    Node* insert(Node *node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return node;
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
    void preOrder(Node *node) {
        if (node == NULL)
            return;
        cout << node->key << " ";
        inOrder(node->left);
        inOrder(node->right);
    }
    void postOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        inOrder(node->right);
        cout << node->key << " ";
    }
    Node* minimum(Node *node) {
        if (node->left == NULL)
            return node;
        return minimum(node->left);
    }
    Node *maximum(Node *node) {
        if (node->right == NULL)
            return node;
        return maximum(node->right);
    }

    Node* del(Node *node, int key) {
        if (node == NULL)
            return NULL;
        if (key < node->key) {
            node->left = del(node->left, key);
        } else if (key > node->key) {
            node->right = del(node->right, key);
        } else if (node->left != NULL && node->right != NULL) {
            node->key = minimum(node->right)->key;
            node->right = del(node->right, node->key);
        } else if (node->left != NULL)
            node = node->left;
        else 
            node = node->right;
        return node;
    }
};

int main() {
    BSTree *tree = new BSTree();
    // tree->insert(tree->root, 5);
    // tree->insert(tree->root, 5);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }
    
    // tree->inOrder(tree->root);
    cout << tree->maximum(tree->root)->key << endl;
    cout << tree->minimum(tree->root)->key;
    return 0;
}