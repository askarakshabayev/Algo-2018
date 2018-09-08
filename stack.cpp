#include <iostream>
#include "st.h"

using namespace std;


int main() {
    // Stack<int> *stack = new Stack<int>();
    // stack->push(5);
    // stack->push(6);
    // stack->push(7);
    // stack->push(8);
    // stack->push(9);
    // cout << stack->back(); 
    // stack->pop();
    // cout << stack->back();
    // stack->pop();
    // stack->pop();
    // cout << stack->back();
    Stack<string> *stack = new Stack<string>();
    stack->push("hello");
    stack->push("test");
    stack->push("123");
    cout << stack->back();

    return 0;
}