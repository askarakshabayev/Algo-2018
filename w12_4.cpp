#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> g[100];
queue<int> q;
int n, m, x, y;

int d[100];

void bfs(int v) {
    d[v] = 1;
    q.push(v);
    while (q.empty() == false) {
        int x = q.front();
        for (int i = 0; i < g[x].size(); i++)
            if (d[g[x][i]] == 0) {
                q.push(g[x][i]);
                d[g[x][i]] = d[x] + 1;
            }
        q.pop();
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
    bfs(0);
    return 0;
}