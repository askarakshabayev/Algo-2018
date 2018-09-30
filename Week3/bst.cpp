#include <iostream>

using namespace std;
class Node {
    public:
    int key;

    Node *left, *right, *parent;
    Node(int key) {
        this->key = key;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class Tree {
    public:
    Node *root;
    Tree() {
        root = NULL;
    }

    Node *insert(Node *node, int key) {
        if (node == NULL) {
            node = new Node(key);
            return node;
        } else if (node->key >= key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

};

int main() {
    return 0;
}