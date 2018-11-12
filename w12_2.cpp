#include<iostream>
#include<vector>

using namespace std;
int n, m, x, y;
bool ok = true;
vector<int> g[100];
int used[100];

void dfs(int v, int color) {
    used[v] = color;
    cout << v << " " << endl;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0)
            dfs(g[v][i], 3 - color);
        else if (used[g[v][i]] == color)
            ok = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 1);
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}