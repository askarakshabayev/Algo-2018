#include <iostream>

using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node *next;
    Node(T data) {
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Stack {
    public:
    Node<T> *top;
    int sz;
    Stack() {
        top = NULL;
        sz = 0;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    } 

    void push(T data) {
        Node<T> *node = new Node<T>(data);
        node->next = top;
        top = node;
        sz++;
    }

    T back() {
        return top->data;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }
};


int main() {
    string s;
    Stack<char> *st = new Stack<char>();
    cin >> s;
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st->push(s[i]);
        else {
            if (st->size() == 0) {
                ok = false;
                break;
            }
            char ch = st->back(); 
            st->pop();
            if (s[i] == ')' && ch != '(')
                ok = false;
            if (s[i] == ']' && ch != '[')
                ok = false;
            if (s[i] == '}' && ch != '{')
                ok = false;
            if (!ok)
                break;
        }
    }
    if (ok && st->size() == 0)
        cout << "YES";
    else   
        cout << "NO";
    return 0;
}