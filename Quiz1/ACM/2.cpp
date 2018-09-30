#include <iostream>
#include <vector>

using namespace std;
int tin[100]; 
int fup[100];  
int used[100];
vector<int> g[100];
int t = 0;

void dfs(int v, int p) {
    used[v] = true;
    tin[v] = ++t;
    fup[v] = tin[v];
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                is_bridge(v, to);
            }
        }
    }
}

int main() {

    return 0;
}