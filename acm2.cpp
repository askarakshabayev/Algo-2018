#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 20;
int d[1 << MAX_N][MAX_N];
int g[MAX_N][MAX_N];

int main() {
    int n, m, x, y, l;

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> l;
        g[x][y] = l;
        g[y][x] = l;
    }
    memset(d, 1, sizeof(d));
    for (int i = 0; i < n; i++)
        d[1 << i][i] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; i++)
            if ((mask & (1 << i)) > 0) {
                for (int j = 0; j < n; j++)
                    if ((mask & (1 << j)) == 0) {
                        d[mask + (1 << j)][j] = min(d[mask + (1 << j)][j], d[mask][i] + g[i][j]);
                    }
            }
    }
    // d[(1 << n) - 1][i]
    return 0;
}