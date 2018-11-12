#include <iostream>
#include <vector>

using namespace std;
vector<int> g[100];
vector<int> result;
bool used[100]; 

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]] == false)
            dfs(g[v][i]);
    result.push_back(v);
}


int main() {
    return 0;
}