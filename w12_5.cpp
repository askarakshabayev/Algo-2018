#include <iostream>
#include <queue>

using namespace std;
int d[10][10];
queue<pair<int, int> > q;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int x1, y1, x2, y2;

bool check(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
    return false;
}

void bfs(int x, int y) {
    d[x][y] = 1;
    q.push(make_pair(x, y));
    while (q.empty() == false) {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0; i < 8; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (check(x1, y1) && d[x1][y1] == 0) {
                d[x1][y1] = d[x][y] + 1;
                q.push(make_pair(x1, y1));
            }
        }
        q.pop();
    }
}


int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    cout << d[x2][y2];
    return 0;
}