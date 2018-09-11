//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;


void solve(int test_case) {
    int n, val, cur = 1;
    stack <int> st;
    cin >> n;
    if (n == 0) exit(0);
    for (int i = 1; i <= n; i++) {
        cin >> val;
        if (val == cur) {
            cur++;
            while (!st.empty() && st.top() == cur) {
                cur++;
                st.pop();
            }
            continue;
        }
        st.push(val);
    }
    cout << (st.empty() ? "yes" : "no") << "\n";
}

int main() {
    int test_case = 0;
    while (++test_case) {
        solve(test_case);
    }
}
