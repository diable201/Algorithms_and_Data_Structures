#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> g[100];
int used[100]; // u[i] = 0
int n, m, x, y;

void dfs(int v) {
    cout << v + 1 << '\n';
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0)
            dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y; // x - y, y - x
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    return 0;
}