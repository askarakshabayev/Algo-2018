#include <iostream>
#include <vector>

using namespace std;

int used[100001];
vector<int> g[100001];
vector<int> result;
int n, m;

void dfs(int v){
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
    result.push_back(v);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);

    for (int i = n - 1; i >= 0; i--)
        cout << result[i] + 1 << " ";
    return 0;
}