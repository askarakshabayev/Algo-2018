#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100];
int used[100];
int n, m;
bool ok = true;

void dfs(int v, int p) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] == 0)
            dfs(g[v][i], v);
        else if (g[v][i] != p && used[g[v][i]] == 1) {
            ok = false;
        }
    }
    used[v] = 2;
}

int main() {
    dfs(0, -1);
    return 0;
}