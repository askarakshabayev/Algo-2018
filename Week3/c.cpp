#include <iostream>

using namespace std;

int a[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int k = i;
        while (k > 0 && a[i] > a[k - 1])
            k--;
        cout << k << " ";
    }
    return 0;
}