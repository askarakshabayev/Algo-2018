#include <iostream>

using namespace std;

int binary_search(int *a, int n, int k) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] <= k)
            left = mid + 1;
        else 
            right = mid;
    }
    if (a[right] == k)
        return right;

    return -1;
}

int main() {
    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cin >> k;
    cout << binary_search(a, n, k);
    
    return 0;
}