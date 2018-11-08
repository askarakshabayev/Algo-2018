#include <iostream>

using namespace std;

void merge(int a[], int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = 0;
    int b[r - l + 1];
    while (!(i > m && j > r)) {
        if (i <= m && j <= r && a[i] < a[j])
            b[k++] = a[i++];
        else if (i <= m && j <= r && a[i] > a[j])
            b[k++] = a[j++];
        else if (i <= m)
            b[k++] = a[i++];
        else if (j <= r)
            b[k++] = a[j++];
    }    
    for (int i = 0; i < r - l + 1; i++)
        a[l + i] = b[i];
}
void mergeSort(int a[], int l, int r) {
    if (r > l) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];        
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}