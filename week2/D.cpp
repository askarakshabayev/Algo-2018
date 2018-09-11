//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;


void solve(int test_case) {
    int n, position, priority[1111], ans = 0;
    queue<int> q;
    cin >> n >> position;
    for (int i = 0; i < n; i++) {
        cin >> priority[i];
        q.push(priority[i]);
    }
    // Sort priorities to make getting max much easier later.
    sort(priority, priority + n);

    while (1) {
        if (q.front() < priority[q.size() - 1]) {
            q.push(q.front());
        } else {
            ans++;
            if (position == 0) {
                cout << ans << "\n";
                return;
            }
        }
        q.pop();
        // One element was either moved back or removed which means that we moved one step forward.
        position = (position - 1 + q.size()) % q.size();
    }

}

int main() {
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        solve(test_case);
    }
}
