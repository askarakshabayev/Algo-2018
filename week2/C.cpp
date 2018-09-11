//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;


void solve(int test_case) {
    int len, l, m, ans = 0;
    string side;
    queue<int> queueL, queueR;
    cin >> l >> m;
    l *= 100;
    for (int i = 1; i <= m; i++) {
        cin >> len >> side;
        if (side == "left") {
            queueL.push(len);
        } else {
            queueR.push(len);
        }
    }

    side = "left";
    while (!queueL.empty() || !queueR.empty()) {
        ans++;
        if (side == "left") {
            int s = 0;
            while (!queueL.empty() && s + queueL.front() <= l) {
                s += queueL.front();
                queueL.pop();
            }
            side = "right";
        } else {
            int s = 0;
            while (!queueR.empty() && s + queueR.front() <= l) {
                s += queueR.front();
                queueR.pop();
            }
            side = "left";
        }
    }
    cout << ans << "\n";
}

int main() {
    int test_case = 0;
    cin >> test_case;
    while (test_case--) {
        solve(test_case);
    }
}
