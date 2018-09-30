#include <iostream>

using namespace std;

int binary_search(int *a, int n, int k) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < k)
            l = m + 1;
        else
            r = m;
    }
    if (a[r] == k)
        return r;
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << binary_search(a, n, k);
    return 0;
}