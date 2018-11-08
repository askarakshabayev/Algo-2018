#include <iostream>
#include <vector>

using namespace std;
vector<int> a[1000];
int g[1000][1000];
bool used[1000];
int n, m, x, y;
vector<int> ts;

void dfs(int v) {
    used[v] = true;
    // for (int i = 0; i < n; i++) 
    //     if (g[v][i] == 1 && used[i] == false)
    //         dfs(i);

    for (int i = 0; i < a[v].size(); i++) 
        if (used[a[v][i]] == false)
            dfs(a[v][i]);
    ts.push_back(v);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x][y] = 1;
        g[y][x] = 1;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == false) {
            dfs(i);
            cnt++;
        }
    return 0;
}