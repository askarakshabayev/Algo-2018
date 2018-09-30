//Solution by NurlashKO
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n, student, team[1000000];

void solve(int test_case) {
    queue <int> team_queue[1111];
    queue <queue<int>* > teams;

    cin >> n;
    if (!n) exit(0);

    cout << "Scenario #" << test_case << "\n";

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            cin >> student;
            team[student] = i;
        }
    }

    string cmd;
    while (cin >> cmd) {
        if (cmd == "STOP") {
            cout << "\n";
            return;
        }
        if (cmd == "ENQUEUE") {
            cin >> student;
            int t = team[student];
            if (team_queue[t].empty()) {
                // There is no one from our team ;(
                // Let's add a new team to queue !
                teams.push(&team_queue[t]);
            }
            team_queue[t].push(student);
        } else {
            cout << (*teams.front()).front() << "\n";
            (*teams.front()).pop();
            if ((*teams.front()).empty()) teams.pop();
        }
    }
}

int main() {
    int test_case = 0;
    while (++test_case) {
        solve(test_case);
    }
}
