#include <iostream>
#include <cmath>

using namespace std;
int d[1 << 22];
int x[22];
int y[22];

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


int main() {
    memset(d, 255, sizeof(d));
    d[0] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for (int mask = 0; mask < (1 << n); mask++) {
        if (d[mask] != 0)
            for (int i = 0; i < n; i++)
                if ((mask & (1 << i)) > 0)
                    for (int j = i + 1; j < n; j++)
                        if ((mask & (1 << j)) > 0 && i != j)
                            if (d[mask + (1 << i) + (1 << j)] == -1 || d[mask + (1 << i) + (1 << j)] > d[mask] + dist(x[i], y[i], x[j], y[j])) {
                                d[mask + (1 << i) + (1 << j)] = d[mask] + dist(x[i], y[i], x[j], y[j]);
                            }
    }
    cout << d[(1 << n) - 1];
    return 0;
}