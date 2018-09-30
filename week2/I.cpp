//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;

queue <pair<string, int>> q;
int n, qt, pt;
string name;

void solve(int test_case) {
    cin >> n >> qt;
    for (int i = 1; i <= n; i++) {
        cin >> name >> pt;
        q.push({name, pt});
    }

    long long curT = 0;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int x = min(qt, v.second);
        v.second -= x;
        curT += x;
        if (!v.second) {
            cout << v.first << " " << curT << "\n";
        } else {
            q.push(v);
        }
    }
    exit(0);
}

int main() {
    int test_case = 0;
    while (++test_case) {
        solve(test_case);
    }
}
