#include <iostream>
#include <stack>

using namespace std;

bool correct(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            if (st.top() == '(' && s[i] != ')')
                return false;
            if (st.top() == '[' && s[i] != ']')
                return false;
            if (st.top() == '{' && s[i] != '}')
                return false;
            st.pop();
        }
    }
    if (st.empty())
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (correct(s))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}