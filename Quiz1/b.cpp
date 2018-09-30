#include <iostream>
#include <stack>

using namespace std;
stack<int> st_a[1201], st_b[1201];
int p[10000];

void find_prime() {
    int MAX_PRIME = 10000;
    memset(p, 0, sizeof(p));// p[i] = 0
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    // 2 3 5 7 11 13 0 1 1  1  0  1  0  1  1 
    // i = 3
    // k = 3
    for (int i = 2; i * i <= MAX_PRIME; i++) {
        if (p[i] == 0) {
            int k = i;
            while (k + i <= MAX_PRIME) {
                p[k + i] = 1;
                k = k + i;
            }
        }
    }
    int k = 1;
    // i = 7
    // k = 5
    for (int i = 2; i <= MAX_PRIME; i++)
        if (p[i] == 0) {
            p[k] = i;
            k++;
        }
}

int main() {
    find_prime();
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        st_a[0].push(x);
    }

    for (int i = 1; i <= m; i++) {
        while (st_a[i - 1].empty() == false) {
            int top = st_a[i - 1].top();
            if (top % p[i] == 0)
                st_b[i].push(top);
            else
                st_a[i].push(top);
            st_a[i - 1].pop();
        }
    }
    for (int i = 1; i <= m; i++)
        while (st_b[i].empty() == false) {
            cout << st_b[i].top() << " ";
            st_b[i].pop(); 
        }

    while (st_a[m].empty() == false) {
        cout << st_a[m].top() << " ";
        st_a[m].pop();
    }
    return 0;
}