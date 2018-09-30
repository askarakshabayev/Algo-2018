#include<iostream>

using namespace std;
string s;

class Node {
    public:
    char ch;
    Node *child[26];
    Node(char ch) {
        this->ch = ch;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};


class Trie {
    public:
    Node *root;
    Trie() {
        root = new Node('+');
    }
    int insert(int k) {
        int cnt = 0;
        Node *node = root;
        for (int i = k; i < s.size(); i++) {
            int pos = s[i] - 'a';
            if (node->child[pos] != NULL) {
                node = node->child[pos];
            } else {
                cnt++;
                Node *temp = new Node(s[i]);
                node->child[pos] = temp;
                node = node->child[pos];
            }
        }
        return cnt;
    }

    bool check(string s) {
        Node *node = root;
        for (int i = 0; i < s.size(); i++) {
            int pos = s[i] - 'a';
            if (node->child[pos] == NULL)
                return false;
            node = node->child[pos];
        }
        return true;
    }
};
int main() {
    Trie *trie = new Trie();
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        cnt += trie->insert(i);
    }
    return 0;
}