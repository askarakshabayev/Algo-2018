#include <iostream>
#include <vector>

using namespace std;

int a[22][22];
int n;

int dist(vector<int> v) {
    int d = 0;
    for (int i = 1; i < n; i++)
        d += a[v[i]][v[i - 1]];
    return d;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(i); // 0 1 2
    int min_dist = -1;
    do {
        int d = dist(v);
        if (min_dist == -1 || d < min_dist)
            min_dist = d;
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}