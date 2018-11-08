#include <iostream>

using namespace std;
int a[3];
int b[3];

int cnt = 0, sum = 0, w;

void rec(int sum, int p, int k) {
    if (k == 3) {
        if (w - sum >= p)
            cnt++;
        return;
    }
    for (int i = p; i <= w; i++) {
        sum = sum + i;
        rec(sum, i, k + 1);
        sum = sum - i;
    }

}

int main() {
    cin >> w;
    rec(0, 1, 0);
    cout << cnt;
    return 0;
}